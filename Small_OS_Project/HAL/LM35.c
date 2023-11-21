/*
 * LM35.c
 *
 *  Created on: Nov 8, 2023
 *      Author: user
 */

#include "LM35.h"
#include "LCD.h"

void Init_temp(void)
{

	ADC_ConfigType ADC_Object;

	ADC_Object.ref_volt=Internal_AREF;
	ADC_Object.prescaler=Div_Factor128;
	ADC_Object.AutoTrigger=OFF;
	ADC_init(&ADC_Object);
}
uint16 Read_Temp(void)
{
	uint16 digital_value;
	uint8 Temp;
	digital_value=	ADC_getDigitalValueSynchNonBlocking(channel_1);

	Temp = (uint8)(((uint32)digital_value*150*2.65)/(ADC_MAXIMUM_VALUE*1.5));

	//	temp=(float32)((digital_value*((float32)ADC_REF_VOLT_VALUE/(float32)ADC_MAXIMUM_VALUE)))*1000;
	//	Temp = temp / 10;
	return Temp;
}

