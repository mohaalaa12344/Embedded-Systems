/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 29/07/2026   *****************/
/********* File: interface File  ****************/
/************************************************/

#ifndef  DIO_INT_H
#define  DIO_INT_H

/* Renamed to avoid hardware register conflicts */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define OUTPUT  1
#define INPUT   0

#define LOW     0
#define HIGH    1

/* Function Prototypes */
void DIO_voidInitialization(void);
void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction);
void DIO_voidSetpinValue(u8 PortID, u8 PinID, u8 Value);
u8   DIO_u8GetPinValue(u8 PortID, u8 PinID);
void DIO_voidTogglePin(u8 PortID, u8 PinID);
void DIO_voidSetPortDirection(u8 PortID, u8 Direction);
void DIO_voidSetPortValue(u8 PortID, u8 Value);

#endif