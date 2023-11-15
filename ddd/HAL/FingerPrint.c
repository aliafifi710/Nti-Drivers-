/*
 * FingerPrint.c
 *
 *  Created on: Nov 4, 2023
 *      Author: user
 */
#include "FingerPrint.h"
const char ShackHand[]			= {0xEF ,0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0x40, 0x00, 0x44,'\0'};
const char Aura_Blue[]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF ,0x01 ,0x00 ,0x07 ,0x35 ,0x02 ,0x0F ,0x02 ,0x7D ,0x00 ,0xCD,'\0'};

void FingerPS_handShake(void)
{
//    /*2 Bytes Header*/
//	UART_sendByte(0xEF);
//	UART_sendByte(0x01);
//
//    /*4 Bytes Module Address*/
//	UART_sendByte(0xFF);
//	UART_sendByte(0xFF);
//	UART_sendByte(0xFF);
//	UART_sendByte(0xFF);
//
//    /*1 Byte Package Identifier*/
//	UART_sendByte(0x01);
//
//    /*2 Byte Package Length*/
//	UART_sendByte(0x00);
//	UART_sendByte(0x03);
//
//    /*1 Byte Instruction Code*/
//	UART_sendByte(0x40);
//
//    /*2 Bytes Checksum*/
//	UART_sendByte(0x00);
//	UART_sendByte(0x44);

	UART_sendString(ShackHand);

}

void H_FingerPS_GenImg(void)
{
    /*2 Bytes Header*/
	UART_sendByte(0xEF);
	UART_sendByte(0x01);

    /*4 Bytes Module Address*/
	UART_sendByte(0xFF);
	UART_sendByte(0xFF);
	UART_sendByte(0xFF);
	UART_sendByte(0xFF);

    /*1 Byte Package Identifier*/
	UART_sendByte(0x01);

    /*2 Byte Package Length*/
	UART_sendByte(0x00);
	UART_sendByte(0x03);

    /*1 Byte Instruction Code*/
	UART_sendByte(0x01);

    /*2 Bytes Checksum*/
	UART_sendByte(0x00);
	UART_sendByte(0x05);
}

void H_FingerPS_ConvertImg2CharFile(void)
{
    /*2 Bytes Header*/
	UART_sendByte(0xEF);
    UART_sendByte(0x01);

    /*4 Bytes Module Address*/
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);

    /*1 Byte Package Identifier*/
    UART_sendByte(0x01);

    /*2 Byte Package Length*/
    UART_sendByte(0x00);
    UART_sendByte(0x04);

    /*1 Byte Instruction Code*/
    UART_sendByte(0x01);

    /*1 Byte Buffer Number*/
    UART_sendByte(0x01);

    /*2 Bytes Checksum*/
    UART_sendByte(0x00);
    UART_sendByte(0x08);
}

void H_FingerPS_GenTemplate(void)
{
    /*2 Bytes Header*/
    UART_sendByte(0xEF);
    UART_sendByte(0x01);

    /*4 Bytes Module Address*/
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);

    /*1 Byte Package Identifier*/
    UART_sendByte(0x01);

    /*2 Byte Package Length*/
    UART_sendByte(0x00);
    UART_sendByte(0x03);

    /*1 Byte Instruction Code*/
    UART_sendByte(0x05);

    /*2 Bytes Checksum*/
    UART_sendByte(0x00);
    UART_sendByte(0x09);
}

void H_FingerPS_strTemplate(void)

{
    /*2 Bytes Header*/
    UART_sendByte(0xEF);
    UART_sendByte(0x01);

    /*4 Bytes Module Address*/
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);
    UART_sendByte(0xFF);

    /*1 Byte Package Identifier*/
    UART_sendByte(0x01);

    /*2 Byte Package Length*/
    UART_sendByte(0x00);
    UART_sendByte(0x06);

    /*1 Byte Instruction Code*/
    UART_sendByte(0x06);

    /*1 Byte Buffer Number*/
    UART_sendByte(0x01);

    /*2 Bytes Location Number*/
    UART_sendByte(0x00);
    UART_sendByte(0x01);

    /*2 Bytes Checksum*/
    UART_sendByte(0x00);
    UART_sendByte(0x0F);
}

void Aura_blue(void)
{
//	UART_sendByte(0xEF);
//	UART_sendByte(0x01);
//	UART_sendByte(0xFF);
//	UART_sendByte(0xFF);
//	UART_sendByte(0xFF);
//	UART_sendByte(0xFF);
//	UART_sendByte(0x01);
//	UART_sendByte(0x00);
//	UART_sendByte(0x07);
//	UART_sendByte(0x35);

	UART_sendString(Aura_Blue);

}








