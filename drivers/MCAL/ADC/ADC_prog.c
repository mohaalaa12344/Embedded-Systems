#include "Std_Types.h"
#include "Bit_Math.h"

#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"

static pf ADC_CallBack = NULL;

void ADC_voidInit(void)
{
	/* 1. Disable ADC */
	CLR_BIT(ADCSRA, 7);
	
	/* 2. Disable Start Conversion */
	CLR_BIT(ADCSRA, 6);
	
	/* 3. Disable Auto Trigger */
	CLR_BIT(ADCSRA, 5);
	
	/* 4. Clear Interrupt Flag (By writing 1 to it) */
	SET_BIT(ADCSRA, 4);
	
	/* 5. Disable ADC Interrupt */
	CLR_BIT(ADCSRA, 3);
	
	/* 6. Select Left or Right Adjustment */
	#if REG_ADJ == LEFT_ADJUSTMENT
		SET_BIT(ADMUX, 5);
	#elif REG_ADJ == RIGHT_ADJUSTMENT
		CLR_BIT(ADMUX, 5);
	#endif
	
	/* 7. Select ADC Channel */
	ADMUX &= 0b11100000;          
	ADMUX |= ADC_CHANNEL;         
	
	/* 8. Select Clock Prescaler (Assuming 128 for general safety) */
	SET_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 0);
}

void ADC_voidADCEnable(void)
{
	/* ADC Enable */
	SET_BIT(ADCSRA, 7);
}

void ADC_voidADCDisable(void)
{
	/* ADC Disable */
	CLR_BIT(ADCSRA, 7);
}

u16 ADC_u16Read(void)
{
	
	 
	#if REG_ADJ == LEFT_ADJUSTMENT
		
		return ADCH;
		
	#elif REG_ADJ == RIGHT_ADJUSTMENT
		return ADC_DATA;
		
	#endif
}

void ADC_voidStartConversion(void)
{
	/* بدء عملية التحويل */
	SET_BIT(ADCSRA, 6);
}

void ADC_voidAutoTrigger(void)
{
	/* 1. Set auto Trigger Enable */
	SET_BIT(ADCSRA, 5);
	
	/* 2. set the source of auto Trigger in SFIOR Register (Bits 5,6,7) */
	SFIOR &= 0b00011111;                      
	SFIOR |= (TRIGGER_SELECT << 5);           
}

void ADC_voidInterruptEnable(void)
{
	/* Enable ADC Interrupt */
	SET_BIT(ADCSRA, 3);
}

void ADC_voidInterruptDisable(void)
{
	/* Disable ADC Interrupt */
	CLR_BIT(ADCSRA, 3);
}

void ADC_voidSetCallBack(pf FunctionAddress)
{
	
	if(FunctionAddress != NULL)
	{
		ADC_CallBack = FunctionAddress;
	}
}


void __vector_16(void) __attribute__((signal, used));
void __vector_16(void)
{
	if(ADC_CallBack != NULL)
	{
		ADC_CallBack();
	}
}