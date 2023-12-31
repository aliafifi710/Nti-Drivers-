/*
 * LCD_priv.h
 *
 *  Created on: Nov 9, 2023
 *      Author: user
 */

#ifndef INC_LCD_PRIV_H_
#define INC_LCD_PRIV_H_

//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD PINS////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_RS_PIN				PIN3_ID
#define		LCD_EN_PIN				PIN2_ID
#define		LCD_D4_PIN				PIN0_ID
#define		LCD_D5_PIN				PIN1_ID
#define		LCD_D6_PIN				PIN2_ID
#define		LCD_D7_PIN				PIN4_ID
//////////////////////////////////////////////////////////////////////
///////////////////////// DEFINING LCD Port////////////////////////////////
//////////////////////////////////////////////////////////////////////
#define		LCD_CONTROL_PORT		PORTA
#define		LCD_DATA_PORT			PORTB


#define _8_BIT_MODE                   8
#define _4_BIT_MODE                   4

//////////////////////////////////////////////////////////////////////
///////////////////////// Configure Mode DEFINING LCD MODE////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define MODE 						_4_BIT_MODE



#endif /* INC_LCD_PRIV_H_ */
