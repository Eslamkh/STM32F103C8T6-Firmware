/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-12                      */
/* Version  : V01                             */
/**********************************************/
#ifndef IR_REMOTE_PRIVATE_H
#define IR_REMOTE_PRIVATE_H

static void IR_Remote_GetFrame(void);
static void IR_Remote_GetButtonData(void);
void (*IR_REMOTE_Callback[21])(void);

static volatile u8 StartFlag = 0 ;
static volatile u16 FramData[50] = {0};
static volatile u8 Counter = 0;

#define BUTTON_POWER         69
#define BUTTON_MODE          70
#define BUTTON_MUTE          71
#define BUTTON_PLAY          68
#define BUTTON_BACKWARD      64
#define BUTTON_FORWARD       67
#define BUTTON_EQ            7
#define BUTTON_VOLDOWN       21
#define BUTTON_VOLUP         9
#define BUTTON_0             22
#define BUTTON_RPT           25
#define BUTTON_USD           13
#define BUTTON_1             12
#define BUTTON_2             24
#define BUTTON_3             94
#define BUTTON_4             8
#define BUTTON_5             28
#define BUTTON_6             6
#define BUTTON_7             66
#define BUTTON_8             82
#define BUTTON_9             74

#endif
