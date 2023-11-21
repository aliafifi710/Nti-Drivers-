/*
 * Keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Ahmed Yasser
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <Dio_INTERFACE.h>

///////////////////////////////////////////////////////////////////////
///////////////////////// KeyPad Configuration ////////////////////////////////
//////////////////////////////////////////////////////////////////////
/*Keypad Row Pins and Ports configuration*/
#define ROW_PORT				PORTC
#define R1_PIN					PIN5_ID
#define R2_PIN					PIN4_ID
#define R3_PIN					PIN3_ID
#define R4_PIN					PIN2_ID

/*Keypad COL Pins and Ports configuration*/
#define COL_PORT				PORTD
#define C1_PIN					PIN7_ID
#define C2_PIN					PIN6_ID
#define C3_PIN					PIN5_ID
#define C4_PIN					PIN3_ID


/* Keypad Types*/
#define KEYPAD_ARR1				{{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*',0,'#','D'}}
#define KEYPAD_ARR2				{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define KEYPAD_ARR3				{{1,2,3,'A'},{4,5,6,'B'},{7,8,9,'C'},{'*',0,'#','D'}}


/* Keypad Type Configuration */
#define KEYPAD					KEYPAD_ARR1
typedef enum
{
	NO_ERROR,
	NULL_POINTER,
	OUT_OF_RANGE_VALUE
}ERROR_Status_t;

void KEYPAD_INIT();
//uint8_t KEYPAD_GET_CHAR();
uint8_t KEYPAD_Get_Pressed_Key(void);


#endif /* KEYPAD_H_ */
