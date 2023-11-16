/*
 * FingerPrint.h
 *
 *  Created on: Nov 4, 2023
 *      Author: user
 */

#ifndef INC_FINGERPRINT_H_
#define INC_FINGERPRINT_H_
#include "UART.h"

void Aura_blue(void);

void FingerPS_handShake(void);

void FingerPS_genImg();

void FingerPS_convertImg2CharFile();

void FingerPS_genTemplate();

void FingerPS_strTemplate();

void FingerPS_searchFinger();

void FingerPS_emptyLibrary(); /*all templates*/

void FingerPS_deleteFinger(/*certin template*/);

void FingerPS_LoadCharFile(); /*load template in a char file*/






#endif /* INC_FINGERPRINT_H_ */
