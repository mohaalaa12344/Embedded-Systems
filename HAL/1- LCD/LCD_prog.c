/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 30/07/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <avr/delay.h>

#include "DIO_int.h"

/***/
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"

void LCD_voidLCDInit(void)
{
	/**
	 1- Wait 30ms
	 2- Send Home Command, wait 1 ms
	 3- send Function set8 bit Command wait 1 ms
	 4- send Display on/off Command wait 1ms
	 5- Send Display Clear Command wait 1ms
	 6- Send Enty Mode Command, wait 1ms
	*/
	_delay_ms(35);

LCD_voidSendCommand(LCD_HOME);
_delay_ms(1);

LCD_voidSendCommand(LCD_FUNCTIONSET_8BIT);
_delay_ms(1);

LCD_voidSendCommand(LCD_DISPLAYON);
_delay_ms(1);

LCD_voidSendCommand(LCD_CLEAR);
_delay_ms(2);

LCD_voidSendCommand(LCD_ENTRY_MODE);
_delay_ms(1);
	
	
}

void LCD_voidSendCommand(u8 u8CMD)
{
    DIO_voidSetPinValue(LCD_RS, LOW);
    DIO_voidSetPinValue(LCD_RW, LOW);

    LCD_voidPutonBus(u8CMD);
	
}

void LCD_voidSendData(u8 u8Data)
{
	DIO_voidSetPinValue(LCD_RS, HIGH);
    DIO_voidSetPinValue(LCD_RW, LOW);

    LCD_voidPutonBus(u8Data);
	
}


static void LCD_voidPutonBus(u8 u8Char)
{
	DIO_voidSetPinValue(LCD_D0, GET_BIT(u8Char, 0));
    DIO_voidSetPinValue(LCD_D1, GET_BIT(u8Char, 1));
    DIO_voidSetPinValue(LCD_D2, GET_BIT(u8Char, 2));
    DIO_voidSetPinValue(LCD_D3, GET_BIT(u8Char, 3));
    DIO_voidSetPinValue(LCD_D4, GET_BIT(u8Char, 4));
    DIO_voidSetPinValue(LCD_D5, GET_BIT(u8Char, 5));
    DIO_voidSetPinValue(LCD_D6, GET_BIT(u8Char, 6));
    DIO_voidSetPinValue(LCD_D7, GET_BIT(u8Char, 7));

    DIO_voidSetPinValue(LCD_EN, HIGH);
    _delay_ms(2);

    DIO_voidSetPinValue(LCD_EN, LOW);
    _delay_ms(2);
}


void LCD_GotoXY(u8 x, u8 y)
{
    u8 Local_u8Address = 0;

    switch (y)
    {
        case 0:Local_u8Address = x;
            break;

        case 1:Local_u8Address = x + 0x40;
            break;
        default:
            return;
    }
    LCD_voidSendCommand(LCD_SETCURSOR | Local_u8Address);
}

void LCD_voidWriteString(u8 * u8string)
{
    u8 i = 0;
    while (u8string[i] != '\0')
    {
        LCD_voidSendData(u8string[i]);
        i++;
    }
}

void LCD_voidWriteNumber(u8 u8Number)
{
    if (u8Number == 0)
    {
        LCD_voidSendData('0');
        return;
    }
    
    u8 str[3];
    s8 i = 0;
    
    while (u8Number > 0)
    {
        str[i++] = (u8Number % 10) + '0';
        u8Number /= 10;
    }
    
    for (i = i - 1; i >= 0; i--)
    {
        LCD_voidSendData(str[i]);
    }
}