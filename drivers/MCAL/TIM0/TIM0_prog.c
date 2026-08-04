#include "Std_Types.h"
#include "Bit_Math.h"

#include "TIM0_int.h"
#include "TIM0_private.h"
#include "TIM0_config.h"


static pf FunctionAddress1 = NULL;
static pf FunctionAddress2 = NULL;

void TIM0_voidinit(void)
{
	/* Select Mode */
	#if TIM0_MODE == NORMAL_MODE
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
	#elif TIM0_MODE == CTC_MODE
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
	#endif

	/* Clear Bit 4 -5 (Disconnect OC0 pin) */
	CLR_BIT(TCCR0, 4);
	CLR_BIT(TCCR0, 5);

	/* disable overflow interrupt */
	CLR_BIT(TIMSK, 0);

	/* disable on Compare match interrupt */
	CLR_BIT(TIMSK, 1);

	/* Clear overflow flag (By writing 1 to it) */
	SET_BIT(TIFR, 0);

	/* Clear on Compare match flag (By writing 1 to it) */
	SET_BIT(TIFR, 1);

	/* Clear TCNT0 */
	TCNT0 = 0;

	/* Clear OCR */
	OCR0 = 0;

	/* Select Prescaller */
	TCCR0 &= 0b11111000;      
	TCCR0 |= PRESCALLER;      
}

/********************************************************************/
/*                          Normal Mode                             */
/********************************************************************/

/* to Enable the interrupt of Over flow */
void TIM0_voidEnableOVInterrupt(void)
{
	SET_BIT(TIMSK, 0);
}

/* to Disable the interrupt of Over flow */
void TIM0_voidDisableOVInterrupt(void)
{
	CLR_BIT(TIMSK, 0);
}

/* to Set the overflow Register (TCNT0) with specific Value */
void TIM0_voidSetOVReg(u8 u8OVRegValue)
{
	TCNT0 = u8OVRegValue;
}

/* to read the overflow Register (TCNT0) */
u8 TIM0_u8ReadOVReg(void)
{
	return TCNT0;
}

/* to Set the Call Back Function of Overflow */
void TIM0_voidOVSetCallBack(pf OVFunctionAddress)
{
	if(OVFunctionAddress != NULL)
	{
		FunctionAddress1 = OVFunctionAddress;
	}
}

/* For Overflow Interrupt Vector */
void __vector_11(void)  __attribute__((signal, used));
void __vector_11(void)
{
	if(FunctionAddress1 != NULL)
	{
		FunctionAddress1();
	}
}

/********************************************************************/
/*                            CTC Mode                              */
/********************************************************************/

/* to Enable the interrupt of CTC */
void TIM0_voidEnableCTCInterrupt(void)
{
	SET_BIT(TIMSK, 1);
}

/* to Disable the interrupt of CTC */
void TIM0_voidDisableCTCInterrupt(void)
{
	CLR_BIT(TIMSK, 1);
}

/* to Set the CTC Register (OCR0) with specific Value */
void TIM0_voidSetCTCReg(u8 u8CTCRegValue)
{
	OCR0 = u8CTCRegValue;
}

/* to read the CTC Register (OCR0) */
u8 TIM0_u8ReadCTCReg(void)
{
	return OCR0;
}

/* to Set the Call Back Function of Compare Match */
void TIM0_voidCTCSetCallBack(pf CTCFunctionAddress)
{
	if(CTCFunctionAddress != NULL)
	{
		FunctionAddress2 = CTCFunctionAddress;
	}
}

/* for On Compare Match Interrupt Vector */
void __vector_10(void)  __attribute__((signal, used));
void __vector_10(void)
{
	if(FunctionAddress2 != NULL)
	{
		FunctionAddress2();
	}
}