/*
 * ADC.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Ali Afifi
 */

#ifndef ADC_H_
#define ADC_H_

#include "MCU_HW.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*********************************************************
 *                    Types Declaration                  *
 *********************************************************/
typedef enum
{
	AREF,AVCC,Reserved,Internal_AREF
}ADC_ReferenceVoltage;

typedef enum
{
	Div_Factor2,Div_Factorr2,Div_Factor4,Div_Factor8,Div_Factor16,Div_Factor32,Div_Factor64,Div_Factor128
}ADC_Prescaler;
typedef enum
{
	RIGHT_ADJUST,LEFT_ADJUST
}ADC_LeftAdjust;
typedef enum
{
	OFF,ON
}ADC_AutoTrigger;

typedef enum
{
	DISABLE,ENABLE
}ADC_EnableOrDisable;

typedef enum
{
	channel_0,channel_1,channel_2,channel_3,channel_4,channel_5,channel_6,channel_7
}channel_num;

typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
	ADC_AutoTrigger AutoTrigger;
	ADC_EnableOrDisable EnableOrDisable;
	ADC_LeftAdjust LeftAdjust;

}ADC_ConfigType;


/*******************************************************************************
 *                   Function Prototypes                                       *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr);



uint16 ADC_getDigitalValueSynchNonBlocking(channel_num channel_num);



void ADC_getDigitalValueAsynchCallBack(uint8 channel_num,void(*ptrfn)(void));


void __vector_16 (void) __attribute__ ((signal));




#endif /* ADC_H_ */
