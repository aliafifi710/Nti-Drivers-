/*
 * Motor.c
 *
 *  Created on: Nov 9, 2023
 *      Author: user
 */
#include "Motor.h"

//#include <avr/io.h>
#include "Timer0.h"
#include "DIO_interface.h"
#include "common_macros.h"

/*******************************************************************************
 *                         Function Definitions                                *
 *******************************************************************************/
//TIMER0_CONFIG timer = {FAST_PWM,CLEAR_OC0,INVERTING_MODE,CLK_DIV_1024};

void DcMotor_Init(void)
{
	TIMER0_CONFIG timer;
	timer.TIMER0_MODES=FAST_PWM;
	timer.PRESCALER=CLK_DIV_1024;
	timer.PWM_MODE=NON_INVERTING_MODE;

	//timer.NON_PWM_MODE = TOGGLE_OC0;
	//timer.NON_PWM_MODE= SET_OC0;
	Timer_Init(&timer);


	/* Setup the direction for the two motor pins through the GPIO driver */
	DIO_voidSetPinDirection(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN1,OUTPUT);
	DIO_voidSetPinDirection(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN2 ,OUTPUT);


	/* Stop the DC-Motor at the beginning through the GPIO driver */
	DIO_voidSetPinValue(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN1,LOGIC_LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT_ID ,DC_MOTOR_PIN_IN2 ,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	DIO_voidSetPinDirection(PORTB ,PIN3_ID ,OUTPUT);  //OC0 AS OUTPUT

	//uint8 duty = ((float)speed/100)*255;
	setFastPWM(speed,NON_INVERTING_MODE);
	//	setphaseCorrectPWM(speed);
	if (state == Stop)
	{
		// Stop the motor
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
		//DIO_voidSetPinValue(PORTA,PIN5_ID,LOGIC_HIGH);

	}
	else if (state == Clockwise)
	{
		// Rotate the motor --> clock wise
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_HIGH);
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW);
	}
	else if (state == Anti_Clockwise)
	{
		// Rotate the motor --> anti-clock wise
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW);
		DIO_voidSetPinValue(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_HIGH);
	}

}




