/*
 * MCU_HW.h
 *
 *  Created on: Oct 24, 2023
 *      Author: user
 */

#ifndef INC_MCU_HW_H_
#define INC_MCU_HW_H_

#include "std_types.h"
#include "common_macros.h"

typedef union
{
	uint8 Reg;
	struct
	{
		uint8 B0:1;
		uint8 B1:1;
		uint8 B2:1;
		uint8 B3:1;
		uint8 B4:1;
		uint8 B5:1;
		uint8 B6:1;
		uint8 B7:1;
	}Bitfield;
}Reg_Def;



/*************************GPIO******************************/
typedef struct
{
	Reg_Def Pin;
	Reg_Def DDR;
	Reg_Def PORT;


}Port_Def;

#define PORTA   ((Port_Def*) 0x39)
#define PORTB   ((Port_Def*) 0x36)
#define PORTC   ((Port_Def*) 0x33)
#define PORTD   ((Port_Def*) 0x30)


/***************************EXTI******************************/
typedef struct
{
	Reg_Def MCUCSR;
	Reg_Def MCUCR;
	Reg_Def reserved[5];
	Reg_Def GICR;

}EXTI_REGs;

#define EXTI 	 	((EXTI_REGs*)0x54)
#define SREG 		(*((volatile uint8*)(0x5F)))

/***********************ADC*********************************/

typedef struct
{
	uint16 ADCL_r;
	Reg_Def ADCSRA_r;
	Reg_Def ADMUX_r;
//	Reg_Def RESERVED[23];
//	Reg_Def SFIOR_r;

}ADC_REGS;

#define ADC_REGS       ((ADC_REGS*)0x24)

/************************TIMER0****************************/


typedef struct
{
	Reg_Def TCNT0;
	Reg_Def TCCR0;
	uint8 RESERVED_1[4];
	Reg_Def TIFR;
	Reg_Def TIMSK;
	uint8 RESERVED_2[2];
	Reg_Def OCR0;

}TIMER0_REGS;

#define Timer0_Regs ((TIMER0_REGS*)0x52)

/***********************TIMER1*******************************/

typedef struct
{
	Reg_Def ICR1L;
	Reg_Def ICR1H;
	Reg_Def OCR1BL;
	Reg_Def OCR1BH;
	Reg_Def OCR1AL;
	Reg_Def OCR1AH;
	Reg_Def TCNT1L;
	Reg_Def TCNT1H;
	Reg_Def TCCR1B;
	Reg_Def TCCR1A;
	uint8 RESERVED_1[9];
	Reg_Def TIFR;
	Reg_Def TIMSK;

}TIMER1_REGS;

#define Timer1_Regs ((TIMER1_REGS*)0x46)

/**************************UART**************************/

typedef struct
{
	Reg_Def UBRRL;
	Reg_Def UCSRB;
	Reg_Def UCSRA;
	Reg_Def UDR;

}UART_REGS;

#define UART_regs ((UART_REGS*)0x29)
#define UBRRH_t   (*((volatile uint8 * ) (0x40)))
#define UCSRC_t   (*((volatile uint8 * ) (0x40)))



#endif /* INC_MCU_HW_H_ */
