/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 24 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableInterrupt (u8 Copy_u8InterruputID)
{
    if(Copy_u8InterruputID <= 31)
    {
        NVIC_ISER0 = 1<<Copy_u8InterruputID ;
    }
    else if (Copy_u8InterruputID <= 63)
    {
        NVIC_ISER1 = 1<<(Copy_u8InterruputID - 32) ;
    }
    else
    {
        //#error ("Invalid Interrupt ID")
    }
    
}
void NVIC_voidDisableInterrupt (u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID <= 31)
    {
        NVIC_ICER0 = 1<<Copy_u8InterruptID ;
    }
    else if (Copy_u8InterruptID <= 63)
    {
        NVIC_ICER1 = 1<<(Copy_u8InterruptID - 32) ;
    }
    else
    {
        //#error ("Invalid Interrupt ID")
    }  
}
void NVIC_voidSetPenddingFlag  (u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID <= 31)
    {
        NVIC_ISPR0 = 1<<Copy_u8InterruptID ;
    }
    else if (Copy_u8InterruptID <= 63)
    {
        NVIC_ISPR1 = 1<<(Copy_u8InterruptID - 32) ;
    }
    else
    {
        //#error ("Invalid Interrupt ID")
    }     
}

void NVIC_voidClearPenddingFlag  (u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID <= 31)
    {
        NVIC_ICPR0 = 1<<Copy_u8InterruptID ;
    }
    else if (Copy_u8InterruptID <= 63)
    {
        NVIC_ICPR1 = 1<<(Copy_u8InterruptID - 32) ;
    }
    else
    {
        //#error ("Invalid Interrupt ID")
    }       
}
u8 NVIC_GetActiveFlage (u8 Copy_u8InterruptID)
{
    u8 Local_u8ActiveFlag = 0 ;
    if(Copy_u8InterruptID <= 31)
    {
        Local_u8ActiveFlag = GET_BIT(NVIC_IABR0 , Copy_u8InterruptID);
    }
    else if (Copy_u8InterruptID <= 63)
    {
        Local_u8ActiveFlag = GET_BIT(NVIC_IABR1 , (Copy_u8InterruptID -32));
    }
    else
    {
       // #error ("Invalid Interrupt ID")
    }
    return Local_u8ActiveFlag;       
}
void NVIC_voidSetGroupsSubs(void)
{
    SCB_AIRCR = GROUP_SUB_SELECT ;
}
void NVIC_voidSetPriority(u8 Copy_u8PeripheralIndex , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority)
{
    if(Copy_u8PeripheralIndex < 60)
    {
        #if GROUP_SUB_SELECT == NVIC_GROUP4_SUB0
            NVIC_IPR[Copy_u8PeripheralIndex] = Copy_u8GroupPriority<<4;

        #elif GROUP_SUB_SELECT == NVIC_GROUP3_SUB1
             NVIC_IPR[Copy_u8PeripheralIndex] = ((Copy_u8GroupPriority<<1)+Copy_u8SubPriority)<<4 ;

        #elif GROUP_SUB_SELECT == NVIC_GROUP2_SUB2
             NVIC_IPR[Copy_u8PeripheralIndex] = ((Copy_u8GroupPriority<<2)+Copy_u8SubPriority)<<4 ;
        
        #elif GROUP_SUB_SELECT == NVIC_GROUP1_SUB3
            NVIC_IPR[Copy_u8PeripheralIndex] = ((Copy_u8GroupPriority<<3)+Copy_u8SubPriority)<<4 ;

        #elif GROUP_SUB_SELECT == NVIC_GROUP0_SUB4
            NVIC_IPR[Copy_u8PeripheralIndex] = Copy_u8SubPriority<<4;

        #endif
    }
}
