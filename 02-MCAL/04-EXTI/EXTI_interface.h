/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-03                      */
/* Version  : V01                             */
/**********************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void EXTI_voidEnableInterrupt(u8 Copy_u8Line , void (*Copy_ptr)(void));
void EXTI_voidEnableEvent(u8 Copy_u8Line);

void EXTI_voidDisableInterrupt(u8 Copy_u8Line);
void EXTI_voidDisableEvent(u8 Copy_u8Line);

void EXTI_voidSetTriggerType (u8 Copy_u8Line , u8 Copy_u8TriggerType);

#define EXTI_RISING         0
#define EXTI_FALLING        1
#define EXTI_ON_CHANGE      2
#endif