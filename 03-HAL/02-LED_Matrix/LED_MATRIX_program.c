/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-01                      */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "LED_MATRIX_interface.h"
#include  "LED_MATRIX_config.h"
#include  "LED_MATRIX_private.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

void LED_MATRIX_voidInit(void)
{
    GPIO_voidSetPinDirection(LED_MATRIX_ROW0 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW1 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW2 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW3 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW4 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW5 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW6 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_ROW7 , OUTPUT_2MHZ , PUSH_PULL);

    GPIO_voidSetPinDirection(LED_MATRIX_COL0 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL1 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL2 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL3 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL4 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL5 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL6 , OUTPUT_2MHZ , PUSH_PULL);
    GPIO_voidSetPinDirection(LED_MATRIX_COL7 , OUTPUT_2MHZ , PUSH_PULL);
}
static void LED_MATRIX_voidDisableAllColumns(void)
{
    GPIO_voidSetPinValue(LED_MATRIX_COL0 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL1 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL2 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL3 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL4 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL5 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL6 , HIGH);
    GPIO_voidSetPinValue(LED_MATRIX_COL7 , HIGH); 
}
static void LED_MATRIX_voidSetRowValue(u8 Copy_u8RowValue)
{
    GPIO_voidSetPinValue(LED_MATRIX_ROW0 , GET_BIT(Copy_u8RowValue, 0));
    GPIO_voidSetPinValue(LED_MATRIX_ROW1 , GET_BIT(Copy_u8RowValue, 1));
    GPIO_voidSetPinValue(LED_MATRIX_ROW2 , GET_BIT(Copy_u8RowValue, 2));
    GPIO_voidSetPinValue(LED_MATRIX_ROW3 , GET_BIT(Copy_u8RowValue, 3));
    GPIO_voidSetPinValue(LED_MATRIX_ROW4 , GET_BIT(Copy_u8RowValue, 4));
    GPIO_voidSetPinValue(LED_MATRIX_ROW5 , GET_BIT(Copy_u8RowValue, 5));
    GPIO_voidSetPinValue(LED_MATRIX_ROW6 , GET_BIT(Copy_u8RowValue, 6));
    GPIO_voidSetPinValue(LED_MATRIX_ROW7 , GET_BIT(Copy_u8RowValue, 7));
}
void LED_MATRIX_voidDisplay(u8 *Copy_u8Data)
{
    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Enable Column 0
    GPIO_voidSetPinValue(LED_MATRIX_COL0,LOW);
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[0]);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[1]);
    //Enable Column 1
    GPIO_voidSetPinValue(LED_MATRIX_COL1,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[2]);
    //Enable Column 2
    GPIO_voidSetPinValue(LED_MATRIX_COL2,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[3]);
    //Enable Column 3
    GPIO_voidSetPinValue(LED_MATRIX_COL3,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[4]);
    //Enable Column 4
    GPIO_voidSetPinValue(LED_MATRIX_COL4,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[5]);
    //Enable Column 5
    GPIO_voidSetPinValue(LED_MATRIX_COL5,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[6]);
    //Enable Column 6
    GPIO_voidSetPinValue(LED_MATRIX_COL6,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);

    // Disable All Columns
    LED_MATRIX_voidDisableAllColumns();
    //Set Rows Value
    LED_MATRIX_voidSetRowValue(Copy_u8Data[7]);
    //Enable Column 7
    GPIO_voidSetPinValue(LED_MATRIX_COL7,LOW);
    //Delay 2.5ms for 50 Hz
    SYSTICK_voidSetBusyWait(2500);
}
void LED_MATRIX_voidDisplayShiftLeft(u8 *Copy_u8Data, u8 Copy_SizeOfData , u8 Copy_u8Speed , u8 *LEDMatrixShiftEnable )
{
    u8 Local_8bit_Data [8] = {0};
    Data = Copy_u8Data ;
     arrsize = Copy_SizeOfData - 1 ;
    while(*(LEDMatrixShiftEnable))
    {
		for(u8 i =0 ; i<8 ; i++)
		{
			Local_8bit_Data[i] = Data[i];
		}
		for(u16 i =0 ; i<Copy_u8Speed ; i++)
		{
			LED_MATRIX_voidDisplay(Local_8bit_Data);
		}
		LED_Matrix_rotate_arr();
    }
}
static void LED_Matrix_rotate_arr (void)
{
    u8 temp ;
    for(u8 i = 0 ; i<arrsize ; i++)
    {
        temp = Data[i];
        Data[i] = Data[i+1];
        Data[i+1] = temp;
    }
}
