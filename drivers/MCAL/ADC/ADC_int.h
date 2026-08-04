#ifndef ADC_INT_H
#define ADC_INT_H


typedef void (*pf)(void);

void ADC_voidInit(void);
void ADC_voidADCEnable(void);
void ADC_voidADCDisable(void);
u16  ADC_u16Read(void);
void ADC_voidStartConversion(void);
void ADC_voidAutoTrigger(void);
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
void ADC_voidSetCallBack(pf FunctionAddress);

#endif