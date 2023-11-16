/*
 * driver_7segment.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Ali Afifi
 */


#include "driver_7segment.h"



void segment_init(channel_number ch_num)
{
                      	  	  /***********************SET THE DIRECTION AS OUTPUT FOR ALL CHANNELS*********************/
	DIO_voidSetPinDirection(PORTB,PIN0_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN1_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN2_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN4_ID,OUTPUT);

	DIO_voidSetPinDirection(PORTA,PIN3_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN2_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN5_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN6_ID,OUTPUT);


							/********************INITIALIZE ALL CHHANNELS TO DISPLAY ZERO*****************************/
	DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_LOW);
	DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
	DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
	DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);


	switch(ch_num)
	{
												/***************SELECT THE FIRST CHANNEL AND DISABLE THE OTHERS*****************/

	case _1_channels:
		DIO_voidSetPinValue(PORTA,PIN3_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTA,PIN2_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN5_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN6_ID,LOGIC_HIGH);
		break;

												/***************SELECT THE FIRST & SECOND CHANNELS AND DISABLE THE OTHERS*****************/

	case _2_channels:
		DIO_voidSetPinValue(PORTA,PIN3_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTA,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN5_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN6_ID,LOGIC_HIGH);
		break;

												/***************SELECT THE FIRST,SECOND & THIRD CHANNEL AND DISABLE THE OTHER*****************/

	case _3_channels:
		DIO_voidSetPinValue(PORTA,PIN3_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTA,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN5_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN6_ID,LOGIC_HIGH);
		break;

												/***************SELECT ALL CHANNELS*****************/

	case _4_channels:
		DIO_voidSetPinValue(PORTA,PIN3_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTA,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN5_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN6_ID,LOGIC_LOW);
		break;

	}


};


void segment_num(number num)
{
	switch(num)
	{
													/********************DISPLAY ZERO*********************/
	case ZERO:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY ONE*********************/

	case ONE:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY TWO*********************/

	case TWO:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY THREE*********************/

	case THREE:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY FOUR*********************/

	case FOUR:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY FIVE*********************/

	case FIVE:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY SIX*********************/

	case SIX:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY SEVEN*********************/

	case SEVEN:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_LOW);
		break;
		/********************DISPLAY EIGHT*********************/

	case EIGHT:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_HIGH);
		break;
		/********************DISPLAY NINE*********************/

	case NINE:
		DIO_voidSetPinValue(PORTB,PIN0_ID,LOGIC_HIGH);
		DIO_voidSetPinValue(PORTB,PIN1_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN2_ID,LOGIC_LOW);
		DIO_voidSetPinValue(PORTB,PIN4_ID,LOGIC_HIGH);
		break;

	};


}
