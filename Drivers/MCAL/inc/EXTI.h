/*
 * EXTI.h
 *
 *  Created on: Oct 22, 2023
 *      Author: user
 */

#ifndef EXTI_H_
#define EXTI_H_

#include"std_types.h"
#include "common_macros.h"
#include "MCU_HW.h"




							/**********************TRIGGER CONFIGURATIONS*********************************/
typedef enum
{
	low_level,
	any_change,
	falling_edge,
	rising_edge
}trigger;

							/**************************EXTI ID'S*****************************************/
typedef enum
{
	EXTI_INT0=6,
	EXTI_INT1=7,
	EXTI_INT2=5
}ID;

typedef enum
{
	OUT_OF_RANGE_VALUE,NULL_POINTER,NO_ERROR
}ERROR_STATE;
							/*****************************CONFIG STRUCT***********************************/
typedef struct
{
	trigger trigger_type;
	ID INT_ID;
	void(*ptr_call_back)(void);
}EXTI_CONFIG;

							/*******************************FUNCTIONS PROTOTYPES****************************/

ERROR_STATE EXTI_ENABLE(EXTI_CONFIG* ptr_config);

ERROR_STATE EXTI_DISABLE(EXTI_CONFIG* ptr_config);

void GIE_Enable();

void GIE_Disable();
/*********************************ISR PROTOTYPES*******************************/

void __vector_1 (void) __attribute__ ((signal));


void __vector_2 (void) __attribute__ ((signal));


void __vector_3 (void) __attribute__ ((signal));



#endif /* EXTI_H_ */
