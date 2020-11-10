/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-09                      */
/* Version  : V01                             */
/**********************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#define TIMER_TIMER2       0
#define TIMER_TIMER3       1
#define TIMER_TIMER4       2
#define TIMER_TIMER5       3

void TIMER_voidSetPrescaler(u8 Copy_u8TimerNumber, u16 Copy_u8PrescalerValue);
void TIMER_voidSetBusyWait(u8 Copy_u8TimerNumber , u16 Copy_u16Value);
void TIMER_voidSetIntervalSingle(u8 Copy_u8TimerNumber , u16 Copy_u16Value , void (*Copy_ptr)(void));
void TIMER_voidSetIntervalPeriodic(u8 Copy_u8TimerNumber , u16 Copy_u16Value , void (*Copy_ptr)(void));

u16 TIMER_u16GetElapsedTime(u8 Copy_u8TimerNumber);
u16 TIMER_u16GetRemainingTime(u8 Copy_u8TimerNumber);

void TIMER_voidClearLoadValue(u8 Copy_u8TimerNumber);
#endif