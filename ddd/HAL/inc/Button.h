/*
 * Button.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ali Afifi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "DIO_interface.h"
#include "MCU_HW.h"
typedef enum
{

	released,
	pressed
}Key_status;



Key_status Single_press(Port_Def* GPIO, pins pin);

#endif /* INC_BUTTON_H_ */
