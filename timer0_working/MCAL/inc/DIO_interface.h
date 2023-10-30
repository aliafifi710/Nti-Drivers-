/*
 * DIO_1.h
 *
 *  Created on: Oct 21, 2023
 *      Author: user
 */

#ifndef DIO_H_
#define DIO_H_



#include "std_types.h"
#include "MCU_HW.h"


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void DIO_voidSetPinDirection(Port_Def* ptr,uint8 Copy_u8PinId,uint8 Copy_u8Direction);

void DIO_voidSetPinValue(Port_Def* ptr,uint8 Copy_u8PinId,uint8 Copy_u8Value);

uint8 DIO_voidGetPinValue(Port_Def* ptr,uint8 Copy_u8PinId);

void DIO_voidSetPortDirection(Port_Def* ptr,uint8 Copy_u8Direction);

void DIO_voidSetPortValue(Port_Def* ptr,uint8 Copy_u8Value);

uint8 DIO_voidGetPortValue(Port_Def* ptr);



#endif /* DIO_H_ */
