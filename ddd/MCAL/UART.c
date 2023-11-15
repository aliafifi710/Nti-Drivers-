/*
 * UART.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Ali Afifi
 */


#include "UART.h"
#include "DIO_interface.h"
void (*Uart_CallBack) (uint8* data) = NULL_PTR;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void USART_RXC_ISR(void) __attribute__((signal, used, externally_visible));

void USART_RXC_ISR(void)
{

	SET_BIT(UART_regs->UCSRA.Reg,PIN7_ID);

	Uart_CallBack(UART_regs->UDR.Reg);
}
/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(uint32 baud_rate,UART_configType *Config_ptr)
{
	uint16 ubrr_value = 0;

	/* U2X = 1 for double transmission speed */
	UART_regs->UCSRA.Reg = (1<<PIN1_ID);

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * XEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	UART_regs->UCSRB.Reg = (1<<PIN3_ID) | (1<<PIN4_ID)  ;

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	UCSRC_t = (1<<PIN7_ID);
	UCSRC_t = (UCSRC_t & 0xCF) | ((Config_ptr -> parity)<<4);
	UCSRC_t = (UCSRC_t & 0xF7) | ((Config_ptr -> stop)<<3);
	UCSRC_t = (UCSRC_t & 0xF9) | ((Config_ptr -> size)<<1);

	/* Calculate the UBRR register value */
	ubrr_value = (uint16)(((16000000 / (baud_rate * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH_t = ubrr_value>>8;
	UART_regs->UBRRL.Reg = ubrr_value;
}

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte( uint8 data)
{
	//	/*
	//	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	//	 * transmitting a new byte so wait until this flag is set to one
	//	 */
	//	while(BIT_IS_CLEAR(UART_regs->UCSRA.Reg,PIN6_ID)){}
	//	/*
	//	 * Put the required data in the UDR register and it also clear the UDRE flag as
	//	 * the UDR register is not empty now
	//	 */
	//	UART_regs->UDR.Reg = data;

	/************************* Another Method *************************/
	UART_regs->UDR.Reg = data;
	while(BIT_IS_CLEAR(UART_regs->UCSRA.Reg,PIN6_ID)){} // Wait until the transmission is complete TXC = 1
	SET_BIT(UART_regs->UCSRA.Reg,PIN6_ID); // Clear the TXC flag
	/*******************************************************************/
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte_Polling(void)
{
	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UART_regs->UCSRA.Reg,PIN7_ID)){}
	DIO_voidSetPinDirection(PORTA,PIN6_ID,OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_LOW);

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
	return UART_regs->UDR.Reg;
}
uint8 UART_recieveByte_NON_BLOCK()
{

	if(UART_regs->UCSRA.Bitfield.B7)
	{
		SET_BIT(UART_regs->UCSRA.Reg,PIN7_ID);
		return UART_regs->UDR.Reg;   /*Read the received data from the Rx buffer (UDR)*/

	}
	else
	{
		return 0;
	}
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		UART_sendByte(*Str);
		Str++;
	}
	 *******************************************************************/
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString_Polling(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte_Polling();

	/* Receive the whole string until the '#' */
	while(Str[i] <= 12)
	{
		i++;
		Str[i] = UART_recieveByte_Polling();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	//Str[i] = '\0';
}


void Set_CallBack(void(*fnptr)(void))
{
	Uart_CallBack = fnptr;

}


void UART_receiveByteAsynchCallBack(void)
{
	SET_BIT(UART_regs->UCSRB.Reg,PIN7_ID);

}


