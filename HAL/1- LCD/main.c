/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 30/07/2026   *****************/
/********* File  : Main Program     *************/
/************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"

int main(void)
{
    DIO_voidSetPinDirection(PORTC, PIN5, OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN6, OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN7, OUTPUT);

    DIO_voidSetPortDirection(PORTD, OUTPUT);

    LCD_voidLCDInit();

    
    LCD_GotoXY(0, 0);
    LCD_voidWriteString((u8*)"LCD Test OK!");

    LCD_GotoXY(0, 1);
    LCD_voidWriteString((u8*)"Count: ");
    LCD_voidWriteNumber(2026);

    while (1)
    {
        
    }

    return 0;
}