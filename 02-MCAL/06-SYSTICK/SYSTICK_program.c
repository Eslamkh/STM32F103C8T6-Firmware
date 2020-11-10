/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 25 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

static void (*SYSTICK_Callback) (void) ;
static u8 SYSTICK_u8IntervalType ;

void SYSTICK_voidSelectClk  (u8 Copy_u8ClkSource)
{
    if(Copy_u8ClkSource == SYSTICK_AHB)
    {
        SET_BIT(STK_CTRL , STK_CTRL_CLKSOURCE);
    }
    else if (Copy_u8ClkSource == SYSTICK_AHB_DIVIDED_BY_8)
    {
        CLR_BIT(STK_CTRL , STK_CTRL_CLKSOURCE);
    }
    
}
void SYSTICK_voidSTKInterrupt(u8 Copy_u8InterruptState)
{
    if(Copy_u8InterruptState == SYSTICK_INT_ENABLE)
    {
        SET_BIT(STK_CTRL , STK_CTRL_TICKINT);
    }
    else if (Copy_u8InterruptState == SYSTICK_INT_DISABLE)
    {
        CLR_BIT(STK_CTRL , STK_CTRL_TICKINT);
    }

}
void SYSTICK_voidCounterEnable(void)
{
    SET_BIT(STK_CTRL , STK_CTRL_ENABLE);
}
u8 SYSTICK_u8ReadCountFlag(void)
{
    u8 Local_u8CountFlag;
    Local_u8CountFlag = GET_BIT(STK_CTRL , STK_CTRL_COUNTFLAG);
    return Local_u8CountFlag ;
}
void SYSTICK_voidReloadValue(u32 Copy_u32ReloadValue , u8 Copy_u8ShotsNumber )
{
    Copy_u32ReloadValue &= 0x00FFFFFF ;
    Copy_u32ReloadValue -= Copy_u8ShotsNumber ;
    STK_LOAD = Copy_u32ReloadValue ;
}
void SYSTICK_voidClearLoadValue(void)
{
    STK_LOAD = 0;
    STK_VAL  = 0;
}
void SYSTICK_voidSetBusyWait(u32 Copy_u32ReloadValue)
{
    Copy_u32ReloadValue &= 0x00FFFFFF ;
    STK_LOAD = Copy_u32ReloadValue ;
    SYSTICK_voidCounterEnable();
    while(SYSTICK_u8ReadCountFlag() == 0);
    SYSTICK_voidClearLoadValue();
}
void SYSTICK_voidSetIntervalSingle(u32 Copy_u32ReloadValue , void (*Copy_ptr)(void))
{
    Copy_u32ReloadValue &= 0x00FFFFFF ;
    STK_LOAD = Copy_u32ReloadValue ;
    SYSTICK_voidSTKInterrupt(SYSTICK_INT_ENABLE);
    SYSTICK_voidCounterEnable();
    SYSTICK_Callback = Copy_ptr ;
    SYSTICK_u8IntervalType = SYSTICK_SINGLE_SHOT ;
}
void SYSTICK_voidSetIntervalPeriodic(u32 Copy_u32ReloadValue , void (*Copy_ptr)(void))
{
    Copy_u32ReloadValue &= 0x00FFFFFF ;
    STK_LOAD = Copy_u32ReloadValue-1;
    SYSTICK_voidSTKInterrupt(SYSTICK_INT_ENABLE);
    SYSTICK_voidCounterEnable();
    SYSTICK_Callback = Copy_ptr ;
    SYSTICK_u8IntervalType = SYSTICK_MULTI_SHOT ;
}
u32 SYSTICK_u32GetRemainingTime()
{
    u32 Local_u32RemainingTime = STK_VAL ;
    return  Local_u32RemainingTime;
}
u32 SYSTICK_u32GetElapsedTime()
{
    u32 Local_u32ElapsedTime = STK_LOAD - STK_VAL ;
    return Local_u32ElapsedTime;
}
void SysTick_Handler(void)
{
    u8 Local_u8Temp ;
    if(SYSTICK_u8IntervalType == SYSTICK_SINGLE_SHOT)
    {
        SYSTICK_voidSTKInterrupt(SYSTICK_INT_DISABLE);
        SYSTICK_voidClearLoadValue();
    }
    SYSTICK_Callback();
    Local_u8Temp = SYSTICK_u8ReadCountFlag();
}