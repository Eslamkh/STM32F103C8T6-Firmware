/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-01                      */
/* Version  : V01                             */
/**********************************************/
#ifndef LED_MATRIX_PRIVATE_H
#define LED_MATRIX_PRIVATE_H

static void LED_MATRIX_voidDisableAllColumns(void);
static void LED_MATRIX_voidSetRowValue(u8 Copy_u8RowValue);
static void LED_Matrix_rotate_arr (void);
static volatile u8 *Data ;
static volatile u8 arrsize;
#endif
