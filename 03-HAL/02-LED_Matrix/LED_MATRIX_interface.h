/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-01                      */
/* Version  : V01                             */
/**********************************************/
#ifndef LED_MATRIX_INTERFACE_H
#define LED_MATRIX_INTERFACE_H

void LED_MATRIX_voidInit(void);
void LED_MATRIX_voidDisplay(u8 *Copy_u8Data);
void LED_MATRIX_voidDisplayShiftLeft(u8 *Copy_u8Data , u8 Copy_SizeOfData, u8 Copy_u8Speed , u8 *LEDMatrixShiftEnable );

#endif
