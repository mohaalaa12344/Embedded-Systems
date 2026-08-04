/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 03/08/2026   *****************/
/********* File: KPAD_int.h     *****************/
/************************************************/

#ifndef KPAD_INT_H
#define KPAD_INT_H

#define KPAD_NOT_PRESSED  0xFF

/* Function Prototypes */
void KPAD_voidInit(void);
u8   KPAD_u8GetPressedKey(void);

#endif