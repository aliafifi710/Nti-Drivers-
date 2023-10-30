/*
 * GEI.c
 *
 *  Created on: Oct 29, 2023
 *      Author: user
 */
#include "GEI.h"

void GIE_Enable()
{
	SET_BIT(SREG,PIN7_ID);
}

void GIE_Disable()
{
	CLEAR_BIT(SREG,PIN7_ID);
}



