/*
 * Button.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Ali Afifi
 */


#include "Button.h"
#include <util/delay.h>

void Button_Init(Port_Def* GPIO,pins pin)
{
	DIO_voidSetPinDirection(GPIO, pin, INPUT);
}



Key_status Single_press(Port_Def* GPIO, pins pin)
{
	DIO_voidSetPinDirection(GPIO, pin, INPUT);
	static uint8 flag=0 ;
	if(!DIO_voidGetPinValue(GPIO, pin))
	{

		_delay_ms(50);
		if(!DIO_voidGetPinValue(GPIO, pin))
		{
			if(flag == 0)
			{
				flag =1;
				return pressed;
			}

		}

	}
	else
	{
		flag = 0;
	}

	return released;
}
