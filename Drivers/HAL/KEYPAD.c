/*
 * KEYPAD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */

#include"KEYPAD.h"



void keypad_init()
{
	DIO_voidSetPinDirection(PORTC,PIN5_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN4_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN3_ID,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2_ID,OUTPUT);

	DIO_voidSetPinDirection(PORTD,PIN7_ID,INPUT);
	DIO_voidSetPinDirection(PORTD,PIN6_ID,INPUT);
	DIO_voidSetPinDirection(PORTD,PIN5_ID,INPUT);
	DIO_voidSetPinDirection(PORTD,PIN3_ID,INPUT);


}


uint8 keypad_getch()
{
	uint8 ch=0;
	//uint8 array[ROWS][COLUMNS];

	return ch ;

}

