/*
 * WatchDog.h
 *
 *  Created on: Nov 5, 2023
 *      Author: user
 */

#ifndef INC_WATCHDOG_H_
#define INC_WATCHDOG_H_

typedef enum
{
	_16_msec,_32_msec,_64_msec,_130_msec,_260_msec,_520_msec,_1000_msec,_2100_ms
}prescaler;

void WDT_Enable();

void WDT_Disable();

void WDT_sleep(prescaler );

void WDT_refresh();



#endif /* INC_WATCHDOG_H_ */
