/**********************************************/
/* Author   : ...                             */
/* Date     : 2022-02-18                      */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include  "LOAD_CELL_interface.h"
#include  "LOAD_CELL_config.h"
#include  "LOAD_CELL_private.h"

u32 Global_u32CalibrationValue ;
void LC_voidInit()
{
    GPIO_voidSetPinDirection(LC_DOUT_PORT,LC_DOUT_PIN,INPUT,FLOATING);
    GPIO_voidSetPinDirection(LC_SCK_PORT,LC_SCK_PIN,OUTPUT_10MHZ,PUSH_PULL);
    GPIO_voidSetPinValue(LC_SCK_PORT,LC_SCK_PIN,LOW);
}
u32 LC_u32GetValue()
{
    u32 Local_u32Value = 0;
    while (GPIO_u8GetPinValue(LC_DOUT_PORT,LC_DOUT_PIN) == HIGH);
    for (u8 i=0; i<24 ; i++)
    {
        GPIO_voidSetPinValue(LC_SCK_PORT,LC_SCK_PIN,HIGH);
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        if(GPIO_u8GetPinValue(LC_DOUT_PORT,LC_DOUT_PIN) == HIGH)
        {
            Local_u32Value += 1;
        }
        GPIO_voidSetPinValue(LC_SCK_PORT,LC_SCK_PIN,LOW);
        Local_u32Value = Local_u32Value<<1;
    }
    Local_u32Value = Local_u32Value>>1;
    if(Local_u32Value & 0x00800000)
    {
    	Local_u32Value |= 0xFF000000;
    }
    GPIO_voidSetPinValue(LC_SCK_PORT,LC_SCK_PIN,HIGH);
    Local_u32Value = Local_u32Value - Global_u32CalibrationValue;
    GPIO_voidSetPinValue(LC_SCK_PORT,LC_SCK_PIN,LOW);



    return Local_u32Value;
}
void LC_voidAutoCalibrate()
{
    Global_u32CalibrationValue = LC_u32GetValue();
}
u32 LC_u32GetValueAVG(u16 Copy_u16LocalNumberOfReadings)
{
    u32 Local_u32ValueAVG = 0;
    for (u16 i = 0; i < Copy_u16LocalNumberOfReadings; i++)
    {
        Local_u32ValueAVG += LC_u32GetValue;
    }
    Local_u32ValueAVG = Local_u32ValueAVG/Copy_u16LocalNumberOfReadings;
    return Local_u32ValueAVG;
}
u32 AntiTwosComp(u32 Copy_u32Value)
{
	u32 Local_value =0;
	Local_value = ~(Copy_u32Value-1);
	return Local_value;
}
