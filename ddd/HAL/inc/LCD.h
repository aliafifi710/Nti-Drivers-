/*
 * LCD.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Ali Afifi
 */

#ifndef LCD_H_
#define LCD_H_

#include "DIO_interface.h"
#include "MCU_HW.h"
#include <stdlib.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 4
//#define GET_BIT(reg_name,bit_num)   ((reg_name & (1<<bit_num))>>bit_num)

#define LCD_D4_PIN     PIN0_ID
#define LCD_D5_PIN     PIN1_ID
#define LCD_D6_PIN     PIN2_ID
#define LCD_D7_PIN     PIN4_ID


#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#if (LCD_DATA_BITS_MODE == 4)

#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID         PIN4_ID
#else
#define LCD_FIRST_DATA_PIN_ID         PIN0_ID
#endif

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA
#define LCD_RS_PIN_ID                  PIN3_ID

//#define LCD_RW_PORT_ID                 PORTB
//#define LCD_RW_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTA
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTB

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_Entery_mode_set            0x04
#define LCD_DISPLAY_ON_CONTROL         0x0C
#define LCD_DISPLAY_OFF_CONTROL        0x08
#define LCD_CURSOR_ON                  0x0A
#define LCD_CURSOR_OFF                 0x0C
#define LCD_BLINK_ON                   0x09
#define LCD_BLINK_OFF                  0x08


#define LCD_TWO_LINES_EIGHT_BITS_MODE      0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE       0x28
#define LCD_FUNCTION_SET_8_BIT_MODE        0X30
#define LCD_FUNCTION_SET_4_BIT_MODE        0X20
#define LCD_FUNCTION_SET_2_LINES           0x30
#define LCD_FUNCTION_SET_4_LINES           0x38

#define LCD_SET_CURSOR_LOCATION        0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void H_LCD_void_Init(void);






void H_LCD_void_sendData(uint8 data );


/*
 * Description :
 * Send the required command to the screen
 */
void H_LCD_void_sendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */

void LCD_displayCharacter(uint8 data);



/*
 * Description :
 * Display the required string on the screen
 */
void H_LCD_void_sendString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void H_LCD_void_gotoXY(uint8 row,uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void H_LCD_void_sendIntNum(uint32 data);

/*
 * Description :
 * Send the clear screen command
 */


static void H_LCD_void_latchByte(uint8 Byte);



#endif /* LCD_H_ */
