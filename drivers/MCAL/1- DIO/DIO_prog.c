/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 29/07/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidInitialization(void)
{
	DDRA = DIO_PORTA_DIRECTIONS;
	DDRB = DIO_PORTB_DIRECTIONS;
	DDRC = DIO_PORTC_DIRECTIONS;
	DDRD = DIO_PORTD_DIRECTIONS;
}

void   DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
	if(PortID < 4 && PinID < 8)
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case PORTA: SET_BIT(DDRA_REG, PinID); break;
				case PORTB: SET_BIT(DDRB_REG, PinID); break;
				case PORTC: SET_BIT(DDRC_REG, PinID); break;
				case PORTD: SET_BIT(DDRD_REG, PinID); break;
			}
		}
		else if(Direction == INPUT)
		{
			switch(PortID)
			{
				case PORTA: CLR_BIT(DDRA_REG, PinID); break;
				case PORTB: CLR_BIT(DDRB_REG, PinID); break;
				case PORTC: CLR_BIT(DDRC_REG, PinID); break;
				case PORTD: CLR_BIT(DDRD_REG, PinID); break;
			}
		}
		else
		{
			
			/** thiselse for any valye not input or output */
		}
	}
	else
	{
		// No Code
	}
}



 

/** Output Mode */
void DIO_voidSetpinValue(u8 PortID , u8 PinID , u8 Value)
{
	
	if(PortID < 4 && PinID < 8 )
	{
		if(Value == 1)
		{
		switch(PortID)
		{
			case PORTA: SET_BIT(PORTA,PinID); break;
			case PORTB: SET_BIT(PORTB,PinID); break;
			case PORTC: SET_BIT(PORTC,PinID); break;
			case PORTD: SET_BIT(PORTD,PinID); break;
		}				
		}
		else if(Value == 0)
		{
		switch(PortID)
		{
			case PORTA: CLR_BIT(PORTA,PinID); break;
			case PORTB: CLR_BIT(PORTB,PinID); break;
			case PORTC: CLR_BIT(PORTC,PinID); break;
			case PORTD: CLR_BIT(PORTD,PinID); break;
		}
		}
		else 
		{
			/** ..... */
		}
		
		
	}

else 
		{
			/** ..... */
		}
}


/** Input Mode*/
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID)
{
	u8 Local_u8PinValue = 0;

	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
		{
			case PORTA: Local_u8PinValue = GET_BIT(PORTA, PinID); break;
			case PORTB: Local_u8PinValue = GET_BIT(PORTB, PinID); break;
			case PORTC: Local_u8PinValue = GET_BIT(PORTC, PinID); break;
			case PORTD: Local_u8PinValue = GET_BIT(PORTD, PinID); break;
		}
	}

	return Local_u8PinValue;
}


/** Output Mode */
void DIO_voidTogglePin(u8 PortID, u8 PinID)
{
	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
		{
			case PORTA: TOG_BIT(PORTA, PinID); break;
			case PORTB: TOG_BIT(PORTB, PinID); break;
			case PORTC: TOG_BIT(PORTC, PinID); break;
			case PORTD: TOG_BIT(PORTD, PinID); break;
		}
	}
}
/** output - input*/
void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{
	if(PortID < 4)
	{
		switch(PortID)
		{
			case PORTA: DDRA = Direction; break;
			case PORTB: DDRB = Direction; break;
			case PORTC: DDRC = Direction; break;
			case PORTD: DDRD = Direction; break;
		}
	}
}
/** High - Low*/
void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
	if(PortID < 4)
	{
		switch(PortID)
		{
			case PORTA: PORTA = Value; break;
			case PORTB: PORTB = Value; break;
			case PORTC: PORTC = Value; break;
			case PORTD: PORTD = Value; break;
		}
	}
}