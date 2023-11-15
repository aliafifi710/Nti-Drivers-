/*
 * UltraSonic.c
 *
 *  Created on: Nov 2, 2023
 *      Author: ali afifi
 */

#include "UltraSonic.h"
#include "ICU.h"
#include "DIO_interface.h"

#include <util/delay.h>   /* For the delay functions */

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
uint8  edgeCount = 0;
uint16 timeHigh = 0;
uint32 distance = 0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void Ultrasonic_init(void)
{
	// Create configuration structure for ICU driver
	Icu_ConfigType Icu_Config = {F_CPU_8,RISING};

	// Initialize the ICU driver
	DIO_voidSetPinDirection(ICU_PORT,ICP1_PIN,INPUT);    // Configure ECHO PIN/PD6 as input pin

	ICU_init(&Icu_Config);

	// Setup the ICU call back function
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	// Setup the direction for the trigger pin as output pin
	DIO_voidSetPinDirection(TRIGGER_PORT , TRIGGER_PIN , OUTPUT );
}



uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();    // Send the trigger pulse

	if(edgeCount == 2)
	{
		edgeCount = 0;
		// Calculate the measured distance in cm
		distance=(timeHigh/57.5);

		// To prevent ultrasonic reading to be different from the LCD reading:
		if (distance < 22)
		{
			distance++;
		}
		if (distance >= 137)
		{
			distance--;
		}
	    if (distance >= 254)
	    {
			distance--;
	    }
	    if (distance >= 367)
	    {
	    	distance--;
	    }
	}

	return distance;
}
void Ultrasonic_Trigger(void)
{
	// Send the trigger pulse to the ultrasonic
	DIO_voidSetPinValue(TRIGGER_PORT, TRIGGER_PIN,LOGIC_HIGH );
	_delay_us(10);
	DIO_voidSetPinValue(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);

}


void Ultrasonic_edgeProcessing(void)
{
	edgeCount++;
	if(edgeCount == 1)
	{
		/*
		 * reset the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		// Detect falling edge
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(edgeCount == 2)
	{
		// Store the High time value
		timeHigh = ICU_getInputCaptureValue();
		// Detect rising edge
		ICU_setEdgeDetectionType(RISING);
	}
}

