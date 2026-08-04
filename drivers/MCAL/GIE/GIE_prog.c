#include "Std_Types.h"
#include "Bit_Math.h"

#include "GIE_int.h"
#include "GIE_private.h"

void GIE_voidEnable(void)
{

    SET_BIT(SREG, SREG_I);
}

void GIE_voidDisable(void)
{

    CLR_BIT(SREG, SREG_I);
}