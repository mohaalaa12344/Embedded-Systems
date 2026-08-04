#ifndef TIM0_PRIVATE_H
#define TIM0_PRIVATE_H


#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)
#define TIMSK   *((volatile u8*)0x59)
#define TIFR    *((volatile u#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


#define UDR       *((volatile u8*)0x2C)
#define UCSRA     *((volatile u8*)0x2B)
#define UCSRB     *((volatile u8*)0x2A)
#define UCSRC     *((volatile u8*)0x40)
#define UBRRL     *((volatile u8*)0x29)
#define UBRRH     *((volatile u8*)0x40)


#define USART_ASYNC             0
#define USART_SYNC              1


#define USART_NORMAL_SPEED      0
#define USART_DOUBLE_SPEED      1


#define USART_PARITY_DISABLE    0
#define USART_PARITY_EVEN       2
#define USART_PARITY_ODD        3


#define USART_DATA_SIZE_5       0
#define USART_DATA_SIZE_6       1
#define USART_DATA_SIZE_7       2
#define USART_DATA_SIZE_8       3
#define USART_DATA_SIZE_9       7


#define USART_STOP_BIT_1        0
#define USART_STOP_BIT_2        1


#define USART_TX_RISING         0
#define USART_TX_FALLING        1

#endif