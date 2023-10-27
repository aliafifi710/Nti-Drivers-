/*
 * LCD.c
 *
 *  Created on: Oct 22, 2023
 *      Author: user
 */

#include "LCD.h"
#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* To use the macros like SET_BIT */


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void H_LCD_void_Init(void)
{
	/* Configure the direction for RS, and E pins as output pins */
	DIO_voidSetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,OUTPUT);

	//DIO_voidSetPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,OUTPUT);

	/* Configure 4 pins in the data port as output pins */
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D4_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D5_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D6_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_D7_PIN,OUTPUT);

#if (LCD_DATA_BITS_MODE == 4)
	_delay_ms(50);

	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN0_ID,LOGIC_LOW);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN1_ID,LOGIC_HIGH);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN2_ID,LOGIC_LOW);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,PIN4_ID,LOGIC_LOW);
	_delay_ms(1);


	H_LCD_void_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	_delay_us(5);
	H_LCD_void_sendCommand(LCD_CURSOR_OFF);
	_delay_ms(1);
	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
	_delay_ms(5);
	H_LCD_void_sendCommand(LCD_GO_TO_HOME);
	_delay_ms(1);

#elif (LCD_DATA_BITS_MODE == 8)
	_delay_ms(50);

	/* Configure 4 pins in the data port as output pins */
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID+1,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID+2,OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN_ID+4,OUTPUT);

	H_LCD_void_sendcommand(LCD_FUNCTION_SET_4_LINES);
	_delay_us(50);
	H_LCD_void_sendcommand(LCD_DISPLAY_ON_CONTROL)

	_delay_us(50);
	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND);
	_delay_ms(5);
	H_LCD_void_sendCommand(LCD_Entery_mode_set);

#endif


}

static void latchbyte(uint8_t Byte)
{


	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);

	_delay_ms(1);
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D4_PIN, GET_BIT(Byte,4));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D5_PIN, GET_BIT(Byte,5));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D6_PIN, GET_BIT(Byte,6));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D7_PIN, GET_BIT(Byte,7));
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);

	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1);

	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D4_PIN, GET_BIT(Byte,0));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D5_PIN, GET_BIT(Byte,1));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D6_PIN, GET_BIT(Byte,2));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_D7_PIN, GET_BIT(Byte,3));
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);

	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(5);
}


/*
 * Description :
 * Send the required command to the screen
 */
void H_LCD_void_sendCommand(uint8 command)
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* Instruction Mode RS=0 */

	_delay_ms(1); /* delay for processing Tas = 50ns */
	latchbyte(command);

}

void H_LCD_void_sendData(uint8 data )
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Instruction Mode RS=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	latchbyte(data);

}


/*
 * Description :
 * Display the required string on the screen
 */
void H_LCD_void_sendString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		H_LCD_void_sendData(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}
	 *********************************************************/
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void H_LCD_void_gotoXY(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x10;
		break;
	case 3:
		lcd_memory_address=col+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	H_LCD_void_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	H_LCD_void_gotoXY(row,col); /* go to to the required LCD position */
	H_LCD_void_sendString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void H_LCD_void_sendIntNum(uint32 data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	H_LCD_void_sendString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	H_LCD_void_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
