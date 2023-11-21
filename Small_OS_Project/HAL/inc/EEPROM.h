/*
 * EEPROM.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Ali Afifi
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_
#include "std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void EEPROM_Init(void);
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);


#endif /* INC_EEPROM_H_ */
