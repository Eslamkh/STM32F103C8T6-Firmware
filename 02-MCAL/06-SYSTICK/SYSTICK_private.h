/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 25 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

// 0xE000E010
#define STK_CTRL            *((volatile u32*)0xE000E010)
#define STK_LOAD            *((volatile u32*)0xE000E014)
#define STK_VAL             *((volatile u32*)0xE000E018)
#define STK_CALIB           *((volatile u32*)0xE000E01C)

#define STK_CTRL_COUNTFLAG           16
#define STK_CTRL_CLKSOURCE           2
#define STK_CTRL_TICKINT             1
#define STK_CTRL_ENABLE              0

#endif