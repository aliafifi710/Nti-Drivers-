/*
 * WatchDog.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Ali Afifi
 */
#include "WatchDog.h"
#include "MCU_HW.h"

void WDT_Enable()
{
	WDTCR |= 1<<PIN3_ID;
}

void WDT_Disable()
{
	WDTCR |= 1<<PIN3_ID | 1<<PIN4_ID;
	WDTCR&= ~ 1<<PIN4_ID;

}

void WDT_sleep(prescaler prescaler )
{
	WDTCR =(WDTCR&0xF8) |(prescaler&0x07);
}

void WDT_refresh()
{
	asm("WDR");
}


