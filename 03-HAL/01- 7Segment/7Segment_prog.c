/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 15 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "7Segment_interface.h"
#include "7Segment_config.h"
#include "7Segment_private.h"
#include "GPIO_interface.h"

void SEVEN_SEGMENT_Display(u8 Copy_u8SevenSegmentNumber)
{
    u8 Number_arr [10]= {0b00111111 , 0b00110000 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101
    , 0b00000111 , 0b01111111 , 0b01101111 };
    GPIO_voidSetPortDirection(SEVEN_SEGMENT_PORT , OUTPUT_10MHZ , PUSH_PULL , SEVEN_SEGMENT_PORT_PART);
    #if SEVEN_SEGMENT_TYPE == COMMON_ANODE
        GPIO_voidSetPortValue (SEVEN_SEGMENT_PORT , ~(Number_arr[Copy_u8SevenSegmentNumber]) , SEVEN_SEGMENT_PORT_PART);
    #elif SEVEN_SEGMENT_TYPE == COMMON_CATHODE
         GPIO_voidSetPortValue (SEVEN_SEGMENT_PORT , Number_arr[Copy_u8SevenSegmentNumber] , SEVEN_SEGMENT_PORT_PART);
	#endif
}
