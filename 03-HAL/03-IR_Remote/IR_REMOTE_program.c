/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-12                      */
/* Version  : V01                             */
/**********************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include  "IR_REMOTE_interface.h"
#include  "IR_REMOTE_config.h"
#include  "IR_REMOTE_private.h"

#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

#if IR_REMOTE_TIMER == IR_REMOTE_SYSTICK
    #include "SYSTICK_interface.h"
#else
    #include "TIMER_interface.h"
#endif

void IR_REMOTE_voidInit(void)
{
    AFIO_voidSetEXTIConfig(IR_REMOTE_PIN ,IR_REMOTE_PORT);
    NVIC_voidEnableInterrupt(IR_REMOTE_PIN + 6);
    #if IR_REMOTE_TIMER == IR_REMOTE_SYSTICK

        SYSTICK_voidSelectClk(SYSTICK_AHB_DIVIDED_BY_8);
    #else
        TIMER_voidSetPrescaler(IR_REMOTE_TIMER , 8);
        NVIC_voidEnableInterrupt(IR_REMOTE_TIMER + 28);
    #endif
    EXTI_voidSetTriggerType(IR_REMOTE_PIN ,EXTI_FALLING);
	EXTI_voidEnableInterrupt(IR_REMOTE_PIN , IR_Remote_GetFrame);
}
static void IR_Remote_GetFrame(void)
{
    if(StartFlag == 0)
	{
        #if IR_REMOTE_TIMER == IR_REMOTE_SYSTICK
            SYSTICK_voidSetIntervalSingle(1000000 , IR_Remote_GetButtonData);
        #else
            TIMER_voidSetIntervalSingle(IR_REMOTE_TIMER , 0xffff ,IR_Remote_GetButtonData);
        #endif
		
		
		StartFlag = 1;
	}
	else
	{
        #if IR_REMOTE_TIMER == IR_REMOTE_SYSTICK
            FramData[Counter]= SYSTICK_u32GetElapsedTime();
		    SYSTICK_voidClearLoadValue();
		    SYSTICK_voidSetIntervalSingle(1000000 , IR_Remote_GetButtonData);
        #else
            FramData[Counter]= TIMER_u16GetElapsedTime(IR_REMOTE_TIMER);
		    TIMER_voidClearLoadValue(IR_REMOTE_TIMER);
		    TIMER_voidSetIntervalSingle(IR_REMOTE_TIMER , 0xffff , IR_Remote_GetButtonData);
        #endif
		
		
		Counter += 1;
	}
}
static void IR_Remote_GetButtonData(void)
{
	IR_REMOTE_ButtonData = 0 ;
	for(u8 i = 0; i <8 ; i++)
	{
		if( (FramData[17+i] >= 2000) && (FramData[17+i] < 2300) )
		{
			SET_BIT(IR_REMOTE_ButtonData , i);
		}
		else
		{
			CLR_BIT(IR_REMOTE_ButtonData , i);
		}
	}
	switch (IR_REMOTE_ButtonData)
	{
	case BUTTON_POWER:
		IR_REMOTE_Callback[0]();
		break;
	case BUTTON_MODE:
		IR_REMOTE_Callback[1]();
		break;
	case BUTTON_MUTE:
		IR_REMOTE_Callback[2]();
		break;
	case BUTTON_PLAY:
		IR_REMOTE_Callback[3]();
		break;
	case BUTTON_BACKWARD:
		IR_REMOTE_Callback[4]();
		break;
	case BUTTON_FORWARD:
		IR_REMOTE_Callback[5]();
		break;
	case BUTTON_EQ:
		IR_REMOTE_Callback[6]();
		break;
	case BUTTON_VOLDOWN:
		IR_REMOTE_Callback[7]();
		break;
	case BUTTON_VOLUP:
		IR_REMOTE_Callback[8]();
		break;
	case BUTTON_0:
		IR_REMOTE_Callback[9]();
		break;
	case BUTTON_RPT:
		IR_REMOTE_Callback[10]();
		break;
	case BUTTON_USD:
		IR_REMOTE_Callback[11]();
		break;
	case BUTTON_1:
		IR_REMOTE_Callback[12]();
		break;
	case BUTTON_2:
		IR_REMOTE_Callback[13]();
		break;
	case BUTTON_3:
		IR_REMOTE_Callback[14]();
		break;
	case BUTTON_4:
		IR_REMOTE_Callback[15]();
		break;
	case BUTTON_5:
		IR_REMOTE_Callback[16]();
		break;
	case BUTTON_6:
		IR_REMOTE_Callback[17]();
		break;
	case BUTTON_7:
		IR_REMOTE_Callback[18]();
		break;
	case BUTTON_8:
		IR_REMOTE_Callback[19]();
		break;
	case BUTTON_9:
		IR_REMOTE_Callback[20]();
		break;
	default:
		break;
	}
    StartFlag = 0 ;
	Counter = 0 ;
	FramData[0] = 0;
}
void IR_REMOTE_voidButtonFunction(u8 Copy_u8Button ,void (*Copy_ptr)(void))
{
    IR_REMOTE_Callback[Copy_u8Button]  = Copy_ptr ;
}
