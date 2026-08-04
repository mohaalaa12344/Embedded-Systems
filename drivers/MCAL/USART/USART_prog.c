#include "Std_Types.h"
#include "Bit_Math.h"

#include "USART_int.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_voidInitialization(void)
{
	

/* USART Registers Definition */
#define UDR       *((volatile u8*) 0x2C)
#define UCSRA     *((volatile u8*) 0x2B)
#define UCSRB     *((volatile u8*) 0x2A)
#define UCSRC     *((volatile u8*) 0x40)
#define UBRRL     *((volatile u8*) 0x29)
#define UBRRH     *((volatile u8*) 0x40)

/* UCSRA Bits */
#define RXC       7
#define TXC       6
#define UDRE      5

/* UCSRB Bits */
#define RXEN      4
#define TXEN      3
#define UCSZ2     2

/* UCSRC Bits */
#define URSEL     7
#define UMSEL     6
#define UPM1      5
#define UPM0      4
#define USBS      3
#define UCSZ1     2
#define UCSZ0     1
#define UCPOL     0

#endif