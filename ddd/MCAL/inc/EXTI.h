/*
 * EXTI.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ali Afifi
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "MCU_HW.h"
#include "GEI.h"


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
	OUT_OF_RANGE,NULL_Ptr,NO_ERR
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


/*********************************ISR PROTOTYPES*******************************/

void __vector_1 (void) __attribute__ ((signal));


void __vector_2 (void) __attribute__ ((signal));


void __vector_3 (void) __attribute__ ((signal));



#endif /* EXTI_H_ */
