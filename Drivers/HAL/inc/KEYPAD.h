/*
 * KEYPAD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_interface.h"


#define ROWS 4
#define COLUMNS 4

void keypad_init();


uint8 keypad_getch();

#endif /* KEYPAD_H_ */
