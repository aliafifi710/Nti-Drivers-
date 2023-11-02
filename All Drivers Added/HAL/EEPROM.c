/*
 * EEPROM.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Ali Afifi
 */
#include "EEPROM.h"
#include "TWI.h"

uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data)
{
	TWI_ConfigType obj;
	obj.prescalar=F_CPU64;
	/* Send the Start Bit */
	TWI_init(&obj);
    if (TWI_getStatus() != TWI_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_sendByte((uint8)((0xA0) | ((u16addr & 0x0700)>>7)));
    if (TWI_getStatus() != TWI_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_sendByte((uint8)(u16addr));
    if (TWI_getStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* Send the Repeated Start Bit */
    TWI_sendStart();
    if (TWI_getStatus() != TWI_REP_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    TWI_sendByte((uint8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));
    if (TWI_getStatus() != TWI_MT_SLA_R_ACK)
        return ERROR;

    /* Read Byte from Memory without send ACK */
    *u8data = TWI_receiveByte_NoACK();
    if (TWI_getStatus() != TWI_MR_DATA_NoACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_sendStop();

    return SUCCESS;
}


uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data)
{
	/* Send the Start Bit */
	TWI_sendStart();
    if (TWI_getStatus() != TWI_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_sendByte((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));
    if (TWI_getStatus() != TWI_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_sendByte((uint8)(u16addr));
    if (TWI_getStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* write byte to eeprom */
    TWI_sendByte(u8data);
    if (TWI_getStatus() != TWI_MT_DATA_ACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_sendStop();

    return SUCCESS;
}



