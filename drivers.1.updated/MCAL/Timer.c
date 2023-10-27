/*
 * Timer.c
 *
 *  Created on: Oct 27, 2023
 *      Author: user
 */
#include "Timer.h"

void Timer_Init(TIMER0_CONFIG *Timer_Config)
{
	switch(Timer_Config->TIMER0_MODES)
	{
	case NORMAL_MODE:
		Timer0_Regs->TCCR0.Bitfield.B7=1;              //FOC0 IS SET FOR NON PWM MODE

		Timer0_Regs->TCCR0.Bitfield.B3=0;
		Timer0_Regs->TCCR0.Bitfield.B6=0;

		Timer0_Regs->TCCR0.Reg=(Timer_Config->NON_PWM_MODE)<<PIN4_ID;

		Timer0_Regs->TCNT0.Reg=Timer_Config->VALUE;

		break;

	case PWM_MODE:

		Timer0_Regs->TCCR0.Bitfield.B3=0;
		Timer0_Regs->TCCR0.Bitfield.B6=1;
		Timer0_Regs->TCCR0.Reg=(Timer_Config->NORMAL_PWM_MODE)<<PIN4_ID;
		break;

	case CTC_MODE:
		Timer0_Regs->TCCR0.Bitfield.B7=1;				//FOC0 IS SET FOR NON PWM MODE

		Timer0_Regs->TCCR0.Bitfield.B3=1;
		Timer0_Regs->TCCR0.Bitfield.B6=0;
		Timer0_Regs->TCCR0.Reg=(Timer_Config->NON_PWM_MODE)<<PIN4_ID;

		Timer0_Regs->TCNT0.Reg=Timer_Config->VALUE;

		break;

	case FAST_PWM:
		Timer0_Regs->TCCR0.Bitfield.B3=1;
		Timer0_Regs->TCCR0.Bitfield.B6=1;
		Timer0_Regs->TCCR0.Reg=(Timer_Config->FAST_PWM_MODE)<<PIN4_ID;
		break;
	}
	Timer0_Regs->TCCR0.Reg=((Timer0_Regs->TCCR0.Reg)&0xF8) | ((Timer_Config->PRESCALER) & 0x07);

}


void Timer_Resume(TIMER0_CONFIG *Timer_Config)
{
	Timer0_Regs->TCCR0.Reg=((Timer0_Regs->TCCR0.Reg)&0xF8) | ((Timer_Config->PRESCALER) & 0x07);

}

void Timer_Stop(TIMER0_CONFIG *Timer_Config)
{
	Timer0_Regs->TCCR0.Reg &= 0xF8;

}

RELOAD_VALUES Timer_GetCounts(TIMER0_CONFIG *Timer_Config)
{
	Timer_Config->VALUE=Timer0_Regs->TCNT0.Reg;
	return Timer_Config->VALUE;
}


void Timer_setDelayTimeMilliSec(uint32 time)
{

}



