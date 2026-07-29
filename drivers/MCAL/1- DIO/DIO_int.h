/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 29/07/2026   *****************/
/********* File: interface File  *****************/
/************************************************/


#ifndef  DIO_INT_H
#define  DIO_INT_H


#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


#define 	PIN0   				0
#define		PIN1				1
#define		PIN2				2
#define		PIN3				3
#define		PIN4				4
#define		PIN5				5
#define		PIN6				6
#define		PIN7				7

#define    OUTPUT				1
#define		INPUT				0

#define		LOW					0
#define		HIGH				1


void DIO_voidInitialization(void);
void   DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction);

#endif