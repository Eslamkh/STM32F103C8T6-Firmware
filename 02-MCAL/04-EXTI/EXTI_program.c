/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-03                      */
/* Version  : V01                             */
/**********************************************/
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "EXTI_interface.h"
#include  "EXTI_config.h"
#include  "EXTI_private.h"

static void (*EXTI_Callback[16]) (void);

void EXTI_voidEnableInterrupt(u8 Copy_u8Line , void (*Copy_ptr)(void))
{
    SET_BIT(EXTI_IMR , Copy_u8Line);
    EXTI_Callback[Copy_u8Line] = Copy_ptr ;
}
void EXTI_voidEnableEvent(u8 Copy_u8Line)
{
    SET_BIT(EXTI_EMR , Copy_u8Line);
}
void EXTI_voidDisableInterrupt(u8 Copy_u8Line)
{
    CLR_BIT(EXTI_IMR , Copy_u8Line);
}
void EXTI_voidDisableEvent(u8 Copy_u8Line)
{
    CLR_BIT(EXTI_EMR , Copy_u8Line);
}
void EXTI_voidSetTriggerType (u8 Copy_u8Line , u8 Copy_u8TriggerType)
{
    switch (Copy_u8TriggerType)
    {
    case EXTI_RISING:
        SET_BIT(EXTI_RTSR , Copy_u8Line);
        break;

    case EXTI_FALLING:
        SET_BIT(EXTI_FTSR , Copy_u8Line);
        break;
    case EXTI_ON_CHANGE:
        SET_BIT(EXTI_RTSR , Copy_u8Line);
        SET_BIT(EXTI_FTSR , Copy_u8Line);
        break;
        
    default:
        break;
    }
}

/* ISRs */

void EXTI0_IRQHandler (void)
{
    EXTI_Callback[0]();
    SET_BIT(EXTI_PR , 0);
}
void EXTI1_IRQHandler (void)
{
    EXTI_Callback[1]();
    SET_BIT(EXTI_PR , 1);
}
void EXTI2_IRQHandler (void)
{
    EXTI_Callback[2]();
    SET_BIT(EXTI_PR , 2);
}
void EXTI3_IRQHandler (void)
{
    EXTI_Callback[3]();
    SET_BIT(EXTI_PR , 3);
}
void EXTI4_IRQHandler (void)
{
    EXTI_Callback[4]();
    SET_BIT(EXTI_PR , 4);
}
void EXTI5_IRQHandler (void)
{
    EXTI_Callback[5]();
    SET_BIT(EXTI_PR , 5);
}
void EXTI6_IRQHandler (void)
{
    EXTI_Callback[6]();
    SET_BIT(EXTI_PR , 6);
}
void EXTI7_IRQHandler (void)
{
    EXTI_Callback[7]();
    SET_BIT(EXTI_PR , 7);
}
void EXTI8_IRQHandler (void)
{
    EXTI_Callback[8]();
    SET_BIT(EXTI_PR , 8);
}
void EXTI9_IRQHandler (void)
{
    EXTI_Callback[9]();
    SET_BIT(EXTI_PR , 9);
}
void EXTI10_IRQHandler (void)
{
    EXTI_Callback[10]();
    SET_BIT(EXTI_PR , 10);
}
void EXTI11_IRQHandler (void)
{
    EXTI_Callback[11]();
    SET_BIT(EXTI_PR , 11);
}
void EXTI12_IRQHandler (void)
{
    EXTI_Callback[12]();
    SET_BIT(EXTI_PR , 12);
}
void EXTI13_IRQHandler (void)
{
    EXTI_Callback[13]();
    SET_BIT(EXTI_PR , 13);
}
void EXTI14_IRQHandler (void)
{
    EXTI_Callback[14]();
    SET_BIT(EXTI_PR , 14);
}
void EXTI15_IRQHandler (void)
{
    EXTI_Callback[15]();
    SET_BIT(EXTI_PR , 15);
}