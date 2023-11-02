/*
 * Timer.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Ali Afifi
 */
#include <stdlib.h>
#include "Timer0.h"

void (*ptr_callBack)(void)=NULL_PTR;

void Timer_Init(TIMER0_CONFIG *Timer_Config)
{
	switch(Timer_Config->TIMER0_MODES)
	{
	case NORMAL_MODE:
		Timer0_Regs->TCCR0.Bitfield.B7=1;              //FOC0 IS SET FOR NON PWM MODE

		Timer0_Regs->TCCR0.Bitfield.B3=0;
		Timer0_Regs->TCCR0.Bitfield.B6=0;

		Timer0_Regs->TCCR0.Reg|=(Timer_Config->NON_PWM_MODE)<<PIN4_ID;

		Timer0_Regs->TCNT0.Reg=Timer_Config->VALUE;

		break;

	case PWM_MODE:
		Timer0_Regs->TCCR0.Bitfield.B7=0;              //FOC0 IS CLEARED FOR PWM MODE

		Timer0_Regs->TCCR0.Bitfield.B3=0;
		Timer0_Regs->TCCR0.Bitfield.B6=1;
		Timer0_Regs->TCCR0.Reg|=(Timer_Config->PWM_MODE)<<PIN4_ID;
		break;

	case CTC_MODE:
		Timer0_Regs->TCCR0.Bitfield.B7=1;				//FOC0 IS SET FOR NON PWM MODE

		Timer0_Regs->TCCR0.Bitfield.B3=1;
		Timer0_Regs->TCCR0.Bitfield.B6=0;
		Timer0_Regs->TCCR0.Reg|=(Timer_Config->NON_PWM_MODE)<<PIN4_ID;

		Timer0_Regs->TCNT0.Reg=Timer_Config->VALUE;

		break;

	case FAST_PWM:
		Timer0_Regs->TCCR0.Bitfield.B7=0;               //FOC0 IS CLEARED FOR PWM MODE

		Timer0_Regs->TCCR0.Bitfield.B3=1;
		Timer0_Regs->TCCR0.Bitfield.B6=1;

		Timer0_Regs->TCCR0.Reg|=(Timer_Config->PWM_MODE)<<PIN4_ID;
		//DIO_voidSetPinValue(PORTA,PIN4_ID,LOGIC_HIGH);

		break;
	}
	Timer0_Regs->TCCR0.Reg=((Timer0_Regs->TCCR0.Reg)&0xF8) | ((Timer_Config->PRESCALER) & 0x07);
	//DIO_voidSetPinValue(PORTA,PIN6_ID,LOGIC_HIGH);


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

void EnableInt(TIMER0_CONFIG *Timer_Config,void *ptrfn_timer(void))
{
	switch (Timer_Config->TIMER0_MODES)
	{
	case CTC_MODE:
		Timer0_Regs->TIMSK.Bitfield.B1=1;
		Timer0_Regs->TIFR.Bitfield.B1=1;
		setCallBack(ptrfn_timer);
		break;
	case NORMAL_MODE:
		Timer0_Regs->TIMSK.Bitfield.B0=1;
		Timer0_Regs->TIFR.Bitfield.B0=1;
		setCallBack(ptrfn_timer);

		break;
	}


}

void DisableInt(TIMER0_CONFIG *Timer_Config)
{
	switch (Timer_Config->TIMER0_MODES)
	{
	case CTC_MODE:
		Timer0_Regs->TIMSK.Bitfield.B1=0;
		break;
	case NORMAL_MODE:
		Timer0_Regs->TIMSK.Bitfield.B0=0;
		break;
	}
}

void setCallBack(void *ptrfn_timer(void))
{

	ptr_callBack=ptrfn_timer;
}

void setFastPWM(uint8 duty,PWM_MODE_0 TYPE)
{
	//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);

	/*DONT FORGERT TO SET PIN AS OUTPUT IN APPLICATION */
	if(TYPE==INVERTING_MODE)
	{
		Timer0_Regs->OCR0.Reg= abs(255-((duty*255)/100));
		//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);


	}
	 if(TYPE==NON_INVERTING_MODE)
	{
		Timer0_Regs->OCR0.Reg= abs(((duty*255)/100)-1);
		//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);

	}
}

void setphaseCorrectPWM(uint8 duty)
{
	/*DONT FORGERT TO SET PIN AS OUTPUT IN APPLICATION */
	Timer0_Regs->OCR0.Reg= abs(((duty*256)/100));
}

//ISR(TIMER0_OVF_vect)
void __vector_11 (void)
{
	CLEAR_BIT(SREG,PIN7_ID);
	Timer0_Regs->TIFR.Bitfield.B0=1;    //clear flag
//	if(ptr_callBack != NULL_PTR)
//	{
//
//	}
	(*ptr_callBack)();

	SET_BIT(SREG,PIN7_ID);
}





