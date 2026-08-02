/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 3/08/2026   *****************/
/********* File: interface File  *****************/
/************************************************/

#ifndef EXTI_INT_H
#define EXTI_INT_H

#define EXTI_INT0   0
#define EXTI_INT1   1
#define EXTI_INT2   2

void EXTI_voidInit(void);
void EXTI_voidEnable(u8 Copy_u8IntID);
void EXTI_voidDisable(u8 Copy_u8IntID);

#endif