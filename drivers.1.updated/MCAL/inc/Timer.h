/*
 * Timer.h
 *
 *  Created on: Oct 27, 2023
 *      Author: user
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include"MCU_HW.h"

typedef enum
{
	NORMAL_MODE,PWM_MODE,CTC_MODE,FAST_PWM
}TIMER0_MODES;

typedef enum
{
	NORMAL_1,TOGGLE_OC0,CLEAR_OC0,SET_OC0
}NON_PWM_MODE;

typedef enum
{
	NORMAL_2,RESERVED_2,CLEAR_OC0_ON_COMPARE_NON_INVERTING_MODE,SET_OC0_ON_COMPARE_NON_INVERTING_MODE
}FAST_PWM_MODE;

typedef enum
{
	NORMAL_3,RESERVED_3,CLEAR_OC0_ON_COMPARE,SET_OC0_ON_COMPARE
}NORMAL_PWM_MODE;

typedef enum
{
	NO_CLK,CLK_DIV_1,CLK_DIV_8,CLK_DIV_64,CLK_DIV_256,CLK_DIV_1024,CLK_ON_FALLING,CLK_ON_RISING
}PRESCALER;

typedef enum
{
	RELOAD_VALUE,COMPARE_VALUE
}RELOAD_VALUES;

typedef struct
{
	TIMER0_MODES TIMER0_MODES;
	NON_PWM_MODE NON_PWM_MODE;
	FAST_PWM_MODE FAST_PWM_MODE;
	NORMAL_PWM_MODE NORMAL_PWM_MODE;
	PRESCALER PRESCALER;
	RELOAD_VALUES VALUE;

}TIMER0_CONFIG;


/*****************************function_prototypes********************/


void Timer_Init(TIMER0_CONFIG *Timer_Config);

void Timer_Resume(TIMER0_CONFIG *Timer_Config);

void Timer_Stop(TIMER0_CONFIG *Timer_Config);

RELOAD_VALUES Timer_GetCounts(TIMER0_CONFIG *Timer_Config);

void Timer_setDelayTimeMilliSec(uint32 time);

void EnableInt(/*takes ptr to fn*/);

void DisableInt(/*takes ptr to fn*/);



#endif /* INC_TIMER_H_ */
