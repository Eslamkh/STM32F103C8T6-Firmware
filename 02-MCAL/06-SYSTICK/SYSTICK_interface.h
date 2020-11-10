/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 25 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define SYSTICK_AHB                 1
#define SYSTICK_AHB_DIVIDED_BY_8    0 

#define SYSTICK_INT_ENABLE          1
#define SYSTICK_INT_DISABLE         0

#define SYSTICK_MULTI_SHOT          1
#define SYSTICK_SINGLE_SHOT         0

void SYSTICK_voidSelectClk  (u8 Copy_u8ClkSource);              // Select Clock [SYSTICK_AHB] or [SYSTICK_AHB_DIVIDED_BY_8]
void SYSTICK_voidSTKInterrupt(u8 Copy_u8InterruptState);        // Enable and Disable SysTick interrupt [SYSTICK_INT_ENABLE] or [SYSTICK_INT_DISABLE]
void SYSTICK_voidCounterEnable(void);                           // Enable Counter
u8 SYSTICK_u8ReadCountFlag(void);                               // Read the counter flag if 1 then the counter reached 0

void SYSTICK_voidReloadValue(u32 Copy_u32ReloadValue , u8 Copy_u8ShotsNumber ); // put count value in load register
void SYSTICK_voidClearLoadValue(void);                          // Clear load value to diasble counter

void SYSTICK_voidSetBusyWait(u32 Copy_u32ReloadValue);          // synchronous funtion will return after the counter flag == 0
void SYSTICK_voidSetIntervalSingle(u32 Copy_u32ReloadValue , void (*ptr)(void));    // Asynchronous funtion will generate interrupt when the counter flag == 0
void SYSTICK_voidSetIntervalPeriodic(u32 Copy_u32ReloadValue , void (*ptr)(void));                         // Asynchronous funtion will generate periodic interrupts everytime the counter flag == 0

u32 SYSTICK_u32GetElapsedTime();
u32 SYSTICK_u32GetRemainingTime();

#endif