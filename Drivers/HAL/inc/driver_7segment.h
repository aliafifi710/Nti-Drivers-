/*
 * driver_7segment.h
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */

#ifndef DRIVER_7SEGMENT_H_
#define DRIVER_7SEGMENT_H_
#include "DIO_interface.h"

typedef enum
{
	_1_channels,_2_channels,_3_channels,_4_channels 			   //SELECT 1,2,3, OR 4   _7_SEGMENTS
}channel_number;

typedef enum
{
	ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE
}number;



void segment_init(channel_number ch_num);           	//SELECT WHICH CHANNEL TO INITIALIZE


void segment_num(number num);							//DISPLAY ANY NUMBER BY PASSING THE NUMBER TO THIS FUNCTION


#endif /* DRIVER_7SEGMENT_H_ */
