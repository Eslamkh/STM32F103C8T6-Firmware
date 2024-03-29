/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-09                      */
/* Version  : V01                             */
/**********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "TIMER_interface.h"
#include  "TIMER_config.h"
#include  "TIMER_private.h"

static void (*TIMER_Callback[6]) (void) ;
static u8 TIMER_u8IntervalType[6] ;


void TIMER_voidSetPrescaler(u8 Copy_u8TimerNumber, u16 Copy_u8PrescalerValue)
{
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        TIM2_PSC = Copy_u8PrescalerValue - 1 ;
        break;

    case TIMER_TIMER3:
        TIM3_PSC = Copy_u8PrescalerValue - 1 ;
        break;

    case TIMER_TIMER4:
        TIM4_PSC = Copy_u8PrescalerValue - 1 ;
        break;

    case TIMER_TIMER5:
        TIM5_PSC = Copy_u8PrescalerValue - 1 ;
        break;

    default:
        break;
    }
}
void TIMER_voidSetBusyWait(u8 Copy_u8TimerNumber , u16 Copy_u16Value)
{
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        CLR_BIT(TIM2_CR1 , 4);     // Counter used as upcounter
        SET_BIT(TIM2_CR1 , 3);     // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM2_CR1 , 1);     // UEV enabled
        SET_BIT(TIM2_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        TIM2_ARR = Copy_u16Value ;
        SET_BIT(TIM2_CR1 , 0);    // Counter enabled
        while(GET_BIT(TIM2_SR , 0) == 0);  // Wait untill overflow
        SET_BIT(TIM2_CR1 , 1);     // UEV disabled
        CLR_BIT(TIM2_SR , 0) ;    // Clear Update Interrupt flag (UIF)
        break;

    case TIMER_TIMER3:
        CLR_BIT(TIM3_CR1 , 4);    // Counter used as upcounter
        SET_BIT(TIM3_CR1 , 3);    // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM3_CR1 , 1);     // UEV enabled
        SET_BIT(TIM3_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        TIM3_ARR = Copy_u16Value ;
        SET_BIT(TIM3_CR1 , 0);    // Counter enabled
        while(GET_BIT(TIM3_SR , 0) == 0);  // Wait untill overflow
        SET_BIT(TIM3_CR1 , 1);     // UEV disabled
        CLR_BIT(TIM3_SR , 0);     // Clear Update Interrupt flag (UIF)
        break;

    case TIMER_TIMER4:
        CLR_BIT(TIM4_CR1 , 4);    // Counter used as upcounter
        SET_BIT(TIM4_CR1 , 3);    // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM4_CR1 , 1);     // UEV enabled
        SET_BIT(TIM4_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        TIM4_ARR = Copy_u16Value ;
        SET_BIT(TIM4_CR1 , 0);    // Counter enabled
        while(GET_BIT(TIM4_SR , 0) == 0);  // Wait untill overflow
        SET_BIT(TIM4_CR1 , 1);     // UEV disabled
        CLR_BIT(TIM4_SR , 0);     // Clear Update Interrupt flag (UIF)
        break;

    case TIMER_TIMER5:
        CLR_BIT(TIM5_CR1 , 4);    // Counter used as upcounter
        SET_BIT(TIM5_CR1 , 3);    // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM5_CR1 , 1);     // UEV enabled
        SET_BIT(TIM5_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        TIM5_ARR = Copy_u16Value ;
        SET_BIT(TIM5_CR1 , 0);    // Counter enabled
        while(GET_BIT(TIM5_SR , 0) == 0);  // Wait untill overflow
        SET_BIT(TIM5_CR1 , 1);     // UEV disabled
        CLR_BIT(TIM5_SR , 0);     // Clear Update Interrupt flag (UIF)
        break;

    default:
        break;
    }
}
void TIMER_voidSetIntervalSingle(u8 Copy_u8TimerNumber , u16 Copy_u16Value , void (*Copy_ptr)(void))
{
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        CLR_BIT(TIM2_CR1 , 4);     // Counter used as upcounter
        SET_BIT(TIM2_CR1 , 3);     // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM2_CR1 , 1);     // UEV enabled
        SET_BIT(TIM2_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM2_DIER , 0);    // Update interrupt enabled.
        TIM2_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[2] = SINGLE_SHOT ;
        TIMER_Callback[2] = Copy_ptr ;
        SET_BIT(TIM2_CR1 , 0);    // Counter enabled
        break;

    case TIMER_TIMER3:
        CLR_BIT(TIM3_CR1 , 4);     // Counter used as upcounter
        SET_BIT(TIM3_CR1 , 3);     // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM3_CR1 , 1);     // UEV enabled
        SET_BIT(TIM3_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM3_DIER , 0);    // Update interrupt enabled.
        TIM3_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[3] = SINGLE_SHOT ;
        TIMER_Callback[3] = Copy_ptr ;
        SET_BIT(TIM3_CR1 , 0);    // Counter enabled
        break;

    case TIMER_TIMER4:
        CLR_BIT(TIM4_CR1 , 4);     // Counter used as upcounter
        SET_BIT(TIM4_CR1 , 3);     // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM4_CR1 , 1);     // UEV enabled
        SET_BIT(TIM4_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM4_DIER , 0);    // Update interrupt enabled.
        TIM4_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[4] = SINGLE_SHOT ;
        TIMER_Callback[4] = Copy_ptr ;
        SET_BIT(TIM4_CR1 , 0);    // Counter enabled
        break;

    case TIMER_TIMER5:
        CLR_BIT(TIM5_CR1 , 4);     // Counter used as upcounter
        SET_BIT(TIM5_CR1 , 3);     // Counter stops counting at the next update event (clearing the bit CEN)
        CLR_BIT(TIM5_CR1 , 1);     // UEV enabled
        SET_BIT(TIM5_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM5_DIER , 0);    // Update interrupt enabled.
        TIM5_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[5] = SINGLE_SHOT ;
        TIMER_Callback[5] = Copy_ptr ;
        SET_BIT(TIM5_CR1 , 0);    // Counter enabled
        break;

    default:
        break;
    }   

}
void TIMER_voidSetIntervalPeriodic(u8 Copy_u8TimerNumber , u16 Copy_u16Value , void (*Copy_ptr)(void))
{
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        CLR_BIT(TIM2_CR1 , 4);     // Counter used as upcounter
        CLR_BIT(TIM2_CR1 , 3);     // Counter is not stopped at update event
        CLR_BIT(TIM2_CR1 , 1);     // UEV enabled
        SET_BIT(TIM2_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM2_DIER , 0);    // Update interrupt enabled.
        TIM2_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[2] = MULTI_SHOT ;
        TIMER_Callback[2] = Copy_ptr ;
        SET_BIT(TIM2_CR1 , 0);    // Counter enabled
        break;

    case TIMER_TIMER3:
        CLR_BIT(TIM3_CR1 , 4);     // Counter used as upcounter
        CLR_BIT(TIM3_CR1 , 3);     // Counter is not stopped at update event
        CLR_BIT(TIM3_CR1 , 1);     // UEV enabled
        SET_BIT(TIM3_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM3_DIER , 0);    // Update interrupt enabled.
        TIM3_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[3] = MULTI_SHOT ;
        TIMER_Callback[3] = Copy_ptr ;
        SET_BIT(TIM3_CR1 , 0);    // Counter enabled
        break;

    case TIMER_TIMER4:
        CLR_BIT(TIM4_CR1 , 4);     // Counter used as upcounter
        CLR_BIT(TIM4_CR1 , 3);     // Counter is not stopped at update event
        CLR_BIT(TIM4_CR1 , 1);     // UEV enabled
        SET_BIT(TIM4_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM4_DIER , 0);    // Update interrupt enabled.
        TIM4_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[4] = MULTI_SHOT ;
        TIMER_Callback[4] = Copy_ptr ;
        SET_BIT(TIM4_CR1 , 0);    // Counter enabled
        break;

    case TIMER_TIMER5:
        CLR_BIT(TIM5_CR1 , 4);     // Counter used as upcounter
        CLR_BIT(TIM5_CR1 , 3);     // Counter is not stopped at update event
        CLR_BIT(TIM5_CR1 , 1);     // UEV enabled
        SET_BIT(TIM5_CR1 , 2);     // Only counter overflow/underflow generates an update interrupt or DMA request if enabled.
        SET_BIT(TIM5_DIER , 0);    // Update interrupt enabled.
        TIM5_ARR = Copy_u16Value ;
        TIMER_u8IntervalType[5] = MULTI_SHOT ;
        TIMER_Callback[5] = Copy_ptr ;
        SET_BIT(TIM5_CR1 , 0);    // Counter enabled
        break;

    default:
        break;
    }   
}
void TIM2_IRQHandler(void)
{
    if(TIMER_u8IntervalType[2] == SINGLE_SHOT)
    {
        SET_BIT(TIM2_CR1 , 1);     // UEV disabled
        TIM2_ARR = 0;
        CLR_BIT(TIM2_DIER , 0);    // Update interrupt disabled.
    }
    TIMER_Callback[2]();
    CLR_BIT(TIM2_SR , 0) ;    // Clear Update Interrupt flag (UIF)
    
}
void TIM3_IRQHandler(void)
{
    if(TIMER_u8IntervalType[3] == SINGLE_SHOT)
    {
        SET_BIT(TIM3_CR1 , 1);     // UEV disabled
        TIM3_ARR = 0;
        CLR_BIT(TIM3_DIER , 0);    // Update interrupt disabled.
    }
    TIMER_Callback[3]();
    CLR_BIT(TIM3_SR , 0) ;    // Clear Update Interrupt flag (UIF)
    
}
void TIM4_IRQHandler(void)
{
    if(TIMER_u8IntervalType[4] == SINGLE_SHOT)
    {
        SET_BIT(TIM4_CR1 , 1);     // UEV disabled
        TIM4_ARR = 0;
        CLR_BIT(TIM4_DIER , 0);    // Update interrupt disabled.
    }
    TIMER_Callback[4]();
    CLR_BIT(TIM4_SR , 0) ;    // Clear Update Interrupt flag (UIF)
    
}
void TIM5_IRQHandler(void)
{
    if(TIMER_u8IntervalType[5] == SINGLE_SHOT)
    {
        SET_BIT(TIM5_CR1 , 1);     // UEV disabled
        TIM5_ARR = 0;
        CLR_BIT(TIM5_DIER , 0);    // Update interrupt disabled.
    }
    TIMER_Callback[5]();
    CLR_BIT(TIM5_SR , 0) ;    // Clear Update Interrupt flag (UIF)
    
}
u16 TIMER_u16GetElapsedTime(u8 Copy_u8TimerNumber)
{
    u16 Local_u16Time = 0;
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        Local_u16Time = TIM2_CNT ;
        break;
    case TIMER_TIMER3:
        Local_u16Time = TIM3_CNT ;
        break;
    case TIMER_TIMER4:
        Local_u16Time = TIM4_CNT ;
        break;
    case TIMER_TIMER5:
        Local_u16Time = TIM5_CNT ;
        break;
    default:
        break;
    }
    return Local_u16Time ;
}
u16 TIMER_u16GetRemainingTime(u8 Copy_u8TimerNumber)
{
    u16 Local_u16Time = 0;
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        Local_u16Time = TIM2_ARR - TIM2_CNT ;
        break;
    case TIMER_TIMER3:
        Local_u16Time = TIM3_ARR - TIM3_CNT ;
        break;
    case TIMER_TIMER4:
        Local_u16Time = TIM4_ARR - TIM4_CNT ;
        break;
    case TIMER_TIMER5:
        Local_u16Time = TIM5_ARR - TIM5_CNT ;
        break;
    default:
        break;
    }
    return Local_u16Time ;
}
void TIMER_voidClearLoadValue(u8 Copy_u8TimerNumber)
{
    switch (Copy_u8TimerNumber)
    {
    case TIMER_TIMER2:
        TIM2_ARR = 0;
        TIM2_CNT = 0;
        break;
    case TIMER_TIMER3:
        TIM3_ARR = 0;
        TIM3_CNT = 0;
        break;
    case TIMER_TIMER4:
        TIM4_ARR = 0;
        TIM4_CNT = 0;
        break;
    case TIMER_TIMER5:
        TIM5_ARR = 0;
        TIM5_CNT = 0;
        break;
    default:
        break;
    }
}