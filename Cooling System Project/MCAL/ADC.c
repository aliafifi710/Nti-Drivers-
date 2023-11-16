/*
 * ADC.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Ali Afifi
 */
//#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"

void (*ADC_ptr)(void);


void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	//	ADC_REGS->ADCSRA_r.Bitfield.B7=0;  //DISABLE ADC

	ADC_REGS->ADMUX_r.Reg =((ADC_REGS->ADMUX_r.Reg) & 0x3F) | ((Config_Ptr->ref_volt) << 6); //SET REFERENCE VOLTAGE

	ADC_REGS->ADCSRA_r.Reg = (ADC_REGS->ADCSRA_r.Reg & 0xF8) | ((Config_Ptr -> prescaler)); //set prescaler


	ADC_REGS->ADCSRA_r.Reg |= 1<<7; //ENABLE ADC


	if(Config_Ptr->LeftAdjust==LEFT_ADJUST)
	{
		ADC_REGS->ADMUX_r.Bitfield.B5=Config_Ptr->LeftAdjust;  //set left or right adjust
	}
	else if(Config_Ptr->LeftAdjust==RIGHT_ADJUST)
	{
		ADC_REGS->ADMUX_r.Bitfield.B5=Config_Ptr->LeftAdjust;  //set left or right adjust
	}


	if(Config_Ptr->AutoTrigger==ON)
	{
		ADC_REGS->ADCSRA_r.Bitfield.B5=Config_Ptr->AutoTrigger;

	}


}

uint16 ADC_getDigitalValueSynchNonBlocking(channel_num channel_num)
{
	//	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */

	ADC_REGS->ADMUX_r.Reg = (ADC_REGS->ADMUX_r.Reg & 0xE0); /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */

	ADC_REGS->ADMUX_r.Reg = ADC_REGS->ADMUX_r.Reg | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */

	SET_BIT(ADC_REGS->ADCSRA_r.Reg,6); /* Start conversion write '1' to ADSC */
	//H_LCD_void_sendIntNum(8);

	while(BIT_IS_CLEAR(ADC_REGS->ADCSRA_r.Reg,4));
	//H_LCD_void_sendIntNum(8);

	SET_BIT(ADC_REGS->ADCSRA_r.Reg,4); /* Clear ADIF by write '1' to it :) */

	return ADC_REGS->ADCL_r; /* Read the digital value from the data register */

}


void ADC_getDigitalValueAsynchCallBack(channel_num channel_num,void(*ptrfn)(void))
{
	ADC_REGS->ADMUX_r.Reg = (ADC_REGS->ADMUX_r.Reg & 0xE0); /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */

	ADC_REGS->ADMUX_r.Reg = ADC_REGS->ADMUX_r.Reg | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */

	SET_BIT(SREG,PIN7_ID);

	ADC_REGS->ADCSRA_r.Bitfield.B3=1;

	ADC_REGS->ADCSRA_r.Bitfield.B6=1;

	ADC_ptr=ptrfn;


}

void __vector_16 (void)
{

	CLEAR_BIT(SREG,PIN7_ID);
	ADC_ptr();
	ADC_REGS->ADCSRA_r.Bitfield.B4=0;

}



