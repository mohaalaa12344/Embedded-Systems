/************************************************/
/********* Author: Mohamed Alaa *****************/
/********* Date  : 3/08/2026   *****************/
/********* File: Program File  *****************/
/********* File: Program File  *****************/
/************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidInit(void)
{
    /*--INT0 Configuration-- */
    if (INT0_SENSE_CONTROL == LOW_LEVEL)
    {
        CLR_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
    }
    else if (INT0_SENSE_CONTROL == ON_CHANGE)
    {
        SET_BIT(MCUCR, 0);
        CLR_BIT(MCUCR, 1);
    }
    else if (INT0_SENSE_CONTROL == FALLING_EDGE)
    {
        CLR_BIT(MCUCR, 0);
        SET_BIT(MCUCR, 1);
    }
    else if (INT0_SENSE_CONTROL == RISING_EDGE)
    {
        SET_BIT(MCUCR, 0);
        SET_BIT(MCUCR, 1);
    }

    /*--INT1 Configuration-- */
    if (INT1_SENSE_CONTROL == LOW_LEVEL)
    {
        CLR_BIT(MCUCR, 2);
        CLR_BIT(MCUCR, 3);
    }
    else if (INT1_SENSE_CONTROL == ON_CHANGE)
    {
        SET_BIT(MCUCR, 2);
        CLR_BIT(MCUCR, 3);
    }
    else if (INT1_SENSE_CONTROL == FALLING_EDGE)
    {
        CLR_BIT(MCUCR, 2);
        SET_BIT(MCUCR, 3);
    }
    else if (INT1_SENSE_CONTROL == RISING_EDGE)
    {
        SET_BIT(MCUCR, 2);
        SET_BIT(MCUCR, 3);
    }

    /*--INT2 Configuration-- */
    if (INT2_SENSE_CONTROL == FALLING_EDGE)
    {
        CLR_BIT(MCUCSR, 6);
    }
    else if (INT2_SENSE_CONTROL == RISING_EDGE)
    {
        SET_BIT(MCUCSR, 6);
    }
}
void EXTI_voidEnable(u8 Copy_u8IntID)
{
    if (Copy_u8IntID == EXTI_INT0)
    {
        SET_BIT(GICR, 6);
    }
    else if (Copy_u8IntID == EXTI_INT1)
    {
        SET_BIT(GICR, 7);
    }
    else if (Copy_u8IntID == EXTI_INT2)
    {
        SET_BIT(GICR, 5);
    }
}

void EXTI_voidDisable(u8 Copy_u8IntID)
{
    if (Copy_u8IntID == EXTI_INT0)
    {
        CLR_BIT(GICR, 6);
    }
    else if (Copy_u8IntID == EXTI_INT1)
    {
        CLR_BIT(GICR, 7);
    }
    else if (Copy_u8IntID == EXTI_INT2)
    {
        CLR_BIT(GICR, 5);
    }
}