/**********************************************/
/* Author   : ...                             */
/* Date     : 2022-02-18                      */
/* Version  : V01                             */
/**********************************************/
#ifndef LOAD_CELL_INTERFACE_H
#define LOAD_CELL_INTERFACE_H

void LC_voidInit();
void LC_voidAutoCalibrate();
u32 LC_u32GetValue();
u32 LC_u32GetValueAVG(u16 Copy_u16LocalNumberOfReadings);
#endif