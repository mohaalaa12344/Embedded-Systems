#ifndef TIM0_CONFIG_H
#define TIM0_CONFIG_H

/* 
 * Select Timer0 Mode:
 * Options: NORMAL_MODE, CTC_MODE
 */
#define TIM0_MODE       NORMAL_MODE

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* 
 * Select Sync or Asych
 * Options: USART_ASYNC, USART_SYNC 
 */
#define USART_MODE              USART_ASYNC

/* 
 * Select Parity --> Disable - Even - ODD
 * Options: USART_PARITY_DISABLE, USART_PARITY_EVEN, USART_PARITY_ODD
 */
#define USART_PARITY            USART_PARITY_DISABLE

/* 
 * if ASYNC, Select Speed --> Normal or Double[cite: 12]
 * Options: USART_NORMAL_SPEED, USART_DOUBLE_SPEED
 */
#define USART_SPEED             USART_NORMAL_SPEED

/* 
 * if ASYNC --> Select Baudrate[cite: 12]
 * Example for 9600 bps with 8MHz CPU and Normal Speed: 51
 */
#define USART_BAUDRATE_VALUE    51

/* 
 * Select Data Size[cite: 12]
 * Options: USART_DATA_SIZE_5, USART_DATA_SIZE_6, USART_DATA_SIZE_7, USART_DATA_SIZE_8, USART_DATA_SIZE_9
 */
#define USART_DATA_SIZE         USART_DATA_SIZE_8

/* 
 * Select Stop Bit[cite: 12]
 * Options: USART_STOP_BIT_1, USART_STOP_BIT_2
 */
#define USART_STOP_BIT          USART_STOP_BIT_1

/* 
 * if Sycn, Select Falling or Rsisng Edge[cite: 12]
 * Options: USART_TX_RISING, USART_TX_FALLING
 */
#define USART_CLOCK_POLARITY    USART_TX_RISING

#endif