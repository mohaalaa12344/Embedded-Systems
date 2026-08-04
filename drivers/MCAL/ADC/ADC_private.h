#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


#define ADMUX           *((volatile u8*)0x27)
#define ADCSRA          *((volatile u8*)0x26)
#define ADCH            *((volatile u8*)0x25)
#define ADCL            *((volatile u8*)0x24)
#define ADC_DATA        *((volatile u16*)0x24)
#define SFIOR           *((volatile u8*)0x50)


#define ADC0            0
#define ADC1            1
#define ADC2            2
#define ADC3            3
#define ADC4            4
#define ADC5            5
#define ADC6            6
#define ADC7            7


#define LEFT_ADJUSTMENT     1
#define RIGHT_ADJUSTMENT    2


#define FREE_RUNNING                   0
#define ANALOG_COMPARATOR              1
#define EXTI0                          2
#define TIM0_COMPARE_MATCH             3
#define TIM0_OVF                       4
#define TIM1_COMPARE_MATCH_B           5
#define TIM1_OVF                       6
#define TIM1_CAPTURE_EVENT             7

#endif