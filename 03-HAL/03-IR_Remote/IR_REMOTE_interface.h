/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-12                      */
/* Version  : V01                             */
/**********************************************/
#ifndef IR_REMOTE_INTERFACE_H
#define IR_REMOTE_INTERFACE_H

#define IR_REMOTE_SYSTICK           4
#define IR_REMOTE_TIMER2            0
#define IR_REMOTE_TIMER3            1
#define IR_REMOTE_TIMER4            2

#define IR_REMOTE_PORTA             0b0000
#define IR_REMOTE_PORTB             0b0001
#define IR_REMOTE_PORTC             0b0010



void IR_REMOTE_voidInit(void);
void IR_REMOTE_voidButtonFunction (u8 Copy_u8Button , void (*Copy_ptr)(void));

#define IR_REMOTE_BUTTON_POWER         0
#define IR_REMOTE_BUTTON_MODE          1
#define IR_REMOTE_BUTTON_MUTE          2
#define IR_REMOTE_BUTTON_PLAY          3
#define IR_REMOTE_BUTTON_BACKWARD      4
#define IR_REMOTE_BUTTON_FORWARD       5
#define IR_REMOTE_BUTTON_EQ            6
#define IR_REMOTE_BUTTON_VOLDOWN       7
#define IR_REMOTE_BUTTON_VOLUP         8
#define IR_REMOTE_BUTTON_0             9
#define IR_REMOTE_BUTTON_RPT           10
#define IR_REMOTE_BUTTON_USD           11
#define IR_REMOTE_BUTTON_1             12
#define IR_REMOTE_BUTTON_2             13
#define IR_REMOTE_BUTTON_3             14
#define IR_REMOTE_BUTTON_4             15
#define IR_REMOTE_BUTTON_5             16
#define IR_REMOTE_BUTTON_6             17
#define IR_REMOTE_BUTTON_7             18
#define IR_REMOTE_BUTTON_8             19
#define IR_REMOTE_BUTTON_9             20


#endif
