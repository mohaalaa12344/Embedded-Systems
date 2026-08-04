/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 04/08/2026   *****************/
/********* File: KPAD_prog.c    *****************/
/************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "KPAD_int.h"
#include "KPAD_config.h"
#include "KPAD_private.h"

static u8 KPAD_u8RowPins[ROW_NUM] = {KPAD_ROW0_PIN, KPAD_ROW1_PIN, KPAD_ROW2_PIN, KPAD_ROW3_PIN};
static u8 KPAD_u8ColPins[COL_NUM] = {KPAD_COL0_PIN, KPAD_COL1_PIN, KPAD_COL2_PIN, KPAD_COL3_PIN};

void KPAD_voidInit(void)
{
	u8 Local_u8Index;


	for(Local_u8Index = 0; Local_u8Index < ROW_NUM; Local_u8Index++)
	{
		DIO_voidSetPinDirection(KPAD_PORT, KPAD_u8RowPins[Local_u8Index], INPUT);
		DIO_voidSetpinValue(KPAD_PORT, KPAD_u8RowPins[Local_u8Index], HIGH);
	}


	for(Local_u8Index = 0; Local_u8Index < COL_NUM; Local_u8Index++)
	{
		DIO_voidSetPinDirection(KPAD_PORT, KPAD_u8ColPins[Local_u8Index], OUTPUT);
		DIO_voidSetpinValue(KPAD_PORT, KPAD_u8ColPins[Local_u8Index], HIGH);
	}
}

u8 KPAD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPAD_NOT_PRESSED;
	u8 Local_u8ColIndex, Local_u8RowIndex, Local_u8KeyIndex;


	for(Local_u8ColIndex = 0; Local_u8ColIndex < COL_NUM; Local_u8ColIndex++)
	{

		DIO_voidSetpinValue(KPAD_PORT, KPAD_u8ColPins[Local_u8ColIndex], LOW);

		for(Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUM; Local_u8RowIndex++)
		{
			if(DIO_u8GetPinValue(KPAD_PORT, KPAD_u8RowPins[Local_u8RowIndex]) == LOW)
			{

				Local_u8KeyIndex = (Local_u8RowIndex * 4) + Local_u8ColIndex;


				switch(Local_u8KeyIndex)
				{
					case 0:  Local_u8PressedKey = '7'; break;
					case 1:  Local_u8PressedKey = '8'; break;
					case 2:  Local_u8PressedKey = '9'; break;
					case 3:  Local_u8PressedKey = '/'; break;
					
					case 4:  Local_u8PressedKey = '4'; break;
					case 5:  Local_u8PressedKey = '5'; break;
					case 6:  Local_u8PressedKey = '6'; break;
					case 7:  Local_u8PressedKey = '*'; break;
					
					case 8:  Local_u8PressedKey = '1'; break;
					case 9:  Local_u8PressedKey = '2'; break;
					case 10: Local_u8PressedKey = '3'; break;
					case 11: Local_u8PressedKey = '-'; break;
					
					case 12: Local_u8PressedKey = 'C'; break; /* Clear */
					case 13: Local_u8PressedKey = '0'; break;
					case 14: Local_u8PressedKey = '='; break;
					case 15: Local_u8PressedKey = '+'; break;
				}

				
				while(DIO_u8GetPinValue(KPAD_PORT, KPAD_u8RowPins[Local_u8RowIndex]) == LOW);

				
				DIO_voidSetpinValue(KPAD_PORT, KPAD_u8ColPins[Local_u8ColIndex], HIGH);

				return Local_u8PressedKey;
			}
		}

		DIO_voidSetpinValue(KPAD_PORT, KPAD_u8ColPins[Local_u8ColIndex], HIGH);
	}

	return Local_u8PressedKey;
}