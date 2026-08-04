#ifndef TIM0_PRIVATE_H
#define TIM0_PRIVATE_H


#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)
#define TIMSK   *((volatile u8*)0x59)
#define TIFR    *((volatile u8*)0x58)


#define NORMAL_MODE     1
#define CTC_MODE        2


#define NO_CLOCK                0
#define PRESCALER_1             1
#define PRESCALER_8             2
#define PRESCALER_64            3
#define PRESCALER_256           4
#define PRESCALER_1024          5
#define EXT_CLK_FALLING_EDGE    6
#define EXT_CLK_RISING_EDGE     7

#endif