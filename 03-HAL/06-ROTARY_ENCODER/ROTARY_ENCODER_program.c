/**********************************************/
/* Author   : ...                             */
/* Date     : 2022-02-18                      */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "ROTARY_ENCODER_interface.h"
#include "ROTARY_ENCODER_config.h"
#include "ROTARY_ENCODER_private.h"

u8 Global_u8CLKValuePrev =0;
void ROT_voidInit()
{
    GPIO_voidSetPinDirection(ROT_DT_PORT,ROT_DT_PIN,INPUT,PULL_UP_PULL_DOWN);
    GPIO_voidSetPinDirection(ROT_CLK_PORT,ROT_CLK_PIN,INPUT,PULL_UP_PULL_DOWN);
    GPIO_voidSetPinDirection(ROT_SW_PORT,ROT_SW_PIN,INPUT,PULL_UP_PULL_DOWN);

    Global_u8CLKValuePrev = GPIO_u8GetPinValue(ROT_CLK_PORT,ROT_CLK_PIN);
}
u8 ROT_u8GetRotaryDirection()
{
    u8 Local_u8DTValue = GPIO_u8GetPinValue(ROT_DT_PORT,ROT_DT_PIN);
    u8 Local_u8CLKValue= GPIO_u8GetPinValue(ROT_CLK_PORT,ROT_CLK_PIN);
    if(Local_u8CLKValue != Global_u8CLKValuePrev)
    {
        Global_u8CLKValuePrev = Local_u8CLKValue;
        if(Local_u8DTValue == Local_u8CLKValue)
        {
            return ROT_COUNTERCLKWISE;
        }
        else
        {
            return ROT_CLKWISE;
        }
    }
    else
    {
        return ROT_NOROTATION;
    }
    
}
u8 ROT_u8GetPushValue()
{
    u8 Local_SWValue = GPIO_u8GetPinValue(ROT_SW_PORT,ROT_SW_PIN);
    if(Local_SWValue)
    {
        return ROT_SWPRESSED;
    }
    else
    {
        return ROT_SWNOTPRESSED;
    }
}