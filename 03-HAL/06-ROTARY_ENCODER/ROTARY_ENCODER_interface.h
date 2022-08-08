/**********************************************/
/* Author   : ...                             */
/* Date     : 2022-02-18                      */
/* Version  : V01                             */
/**********************************************/
#ifndef ROTARY_ENCODER_INTERFACE_H
#define ROTARY_ENCODER_INTERFACE_H

#define ROT_CLKWISE             2
#define ROT_COUNTERCLKWISE      3
#define ROT_NOROTATION          4
#define ROT_SWPRESSED           1
#define ROT_SWNOTPRESSED        0

void ROT_voidInit();
u8 ROT_u8GetRotaryDirection();
u8 ROT_u8GetPushValue();

#endif