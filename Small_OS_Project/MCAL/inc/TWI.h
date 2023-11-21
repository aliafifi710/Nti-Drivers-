/*
 * TWI.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Ali Afifi
 */


#ifndef TWI_H_
#define TWI_H_

#include "MCU_HW.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	F_CPU_1,F_CPU_4,F_CPU_16,F_CPU64
}TWI_Prescalar;

typedef enum
{
	 TWI_SPEED_100=72,
	 TWI_SPEED_400=12
}TWI_Speed;

typedef struct
{
	TWI_Prescalar prescalar;
	TWI_Speed speed;

}TWI_ConfigType;



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define TWI_START          		  0x08 /* start has been sent */
#define TWI_REP_START      		  0x10 /* repeated start */
#define TWI_LOST_Arbitration      0x38 /* Master transmit data and ACK has been received from Slave. */

/* I2C Status Bits in the TWSR Register for Transmitter */

#define TWI_MT_SLA_W_ACK   		  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_W_NoACK 		  0x20 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   		  0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MT_DATA_NoACK 		  0x30 /* Master transmit data and ACK has been received from Slave. */
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* I2C Status Bits in the TWSR Register for Receiver*/


#define TWI_MT_SLA_R_ACK    0x40 /* Master received data and send ACK to slave. */
#define TWI_MR_SLA_W_NoACK  0x48 /* Master received data but doesn't send ACK to slave. */
#define TWI_MR_DATA_ACK     0x50 /* Master received data but doesn't send ACK to slave. */
#define TWI_MR_DATA_NoACK   0x58 /* Master received data but doesn't send ACK to slave. */

/*******************************************************************************
 *                      \]Functions Prototypes                                   *
 *******************************************************************************/
void TWI_init(TWI_ConfigType *config_ptr);
void TWI_sendStart(void);
void TWI_sendStop(void);
void TWI_sendByte(uint8 data);


uint8 TWI_receiveByte_ACK(void);
uint8 TWI_receiveByte_NoACK(void);
uint8 TWI_getStatus(void);


#endif /* TWI_H_ */

