/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 12 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinMode , u8 Copy_u8PinConfig)
{
    switch (Copy_u8PortNumber)
    {
    case PORTA:
        {
            if(Copy_u8PinMode == INPUT) 
            {
                if(Copy_u8PinConfig == ANALOG) // 0b0000
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_INPUT_ANALOG <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_INPUT_ANALOG <<( (Copy_u8PinNumber-8) *4));
                    }

                }
                else if (Copy_u8PinConfig == FLOATING) // 0b0100
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_INPUT_FLOATING <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_INPUT_FLOATING <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == PULL_UP_PULL_DOWN) // 0b1000
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_INPUT_PULLUP_PULLDOWN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_INPUT_PULLUP_PULLDOWN <<( (Copy_u8PinNumber-8) *4));
                    }
                }

            }
            else if (Copy_u8PinMode == OUTPUT_10MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0001
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_10MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_10MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0101
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_10MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_10MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1001
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_10MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_10MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1101
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                
                
            }
            else if (Copy_u8PinMode == OUTPUT_2MHZ)
            {
               if(Copy_u8PinConfig == PUSH_PULL) // 0b0010
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_2MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_2MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0110
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_2MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_2MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1010
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_2MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_2MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1110
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
            }
            else if (Copy_u8PinMode == OUTPUT_50MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0011
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_50MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_50MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0111
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_50MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_50MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1011
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_50MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_50MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1111
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTA_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTA_CRL |=  (PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTA_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTA_CRH |=  (PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
            }
            
        }
        break;
    case PORTB:
        {
            if(Copy_u8PinMode == INPUT) 
            {
                if(Copy_u8PinConfig == ANALOG) // 0b0000
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_INPUT_ANALOG <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_INPUT_ANALOG <<( (Copy_u8PinNumber-8) *4));
                    }

                }
                else if (Copy_u8PinConfig == FLOATING) // 0b0100
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_INPUT_FLOATING <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_INPUT_FLOATING <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == PULL_UP_PULL_DOWN) // 0b1000
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_INPUT_PULLUP_PULLDOWN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_INPUT_PULLUP_PULLDOWN <<( (Copy_u8PinNumber-8) *4));
                    }
                }

            }
            else if (Copy_u8PinMode == OUTPUT_10MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0001
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_10MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_10MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0101
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_10MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_10MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1001
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_10MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_10MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1101
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                
                
            }
            else if (Copy_u8PinMode == OUTPUT_2MHZ)
            {
               if(Copy_u8PinConfig == PUSH_PULL) // 0b0010
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_2MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_2MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0110
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_2MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_2MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1010
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_2MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_2MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1110
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
            }
            else if (Copy_u8PinMode == OUTPUT_50MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0011
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_50MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_50MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0111
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_50MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_50MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1011
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_50MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_50MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1111
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTB_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTB_CRL |=  (PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTB_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTB_CRH |=  (PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
            }
            
            
        }
        break;
    case PORTC:
        {
            if(Copy_u8PinMode == INPUT) 
            {
                if(Copy_u8PinConfig == ANALOG) // 0b0000
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_INPUT_ANALOG <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_INPUT_ANALOG <<( (Copy_u8PinNumber-8) *4));
                    }

                }
                else if (Copy_u8PinConfig == FLOATING) // 0b0100
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_INPUT_FLOATING <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_INPUT_FLOATING <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == PULL_UP_PULL_DOWN) // 0b1000
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_INPUT_PULLUP_PULLDOWN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_INPUT_PULLUP_PULLDOWN <<( (Copy_u8PinNumber-8) *4));
                    }
                }

            }
            else if (Copy_u8PinMode == OUTPUT_10MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0001
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_10MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_10MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0101
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_10MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_10MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1001
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_10MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_10MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1101
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                
                
            }
            else if (Copy_u8PinMode == OUTPUT_2MHZ)
            {
               if(Copy_u8PinConfig == PUSH_PULL) // 0b0010
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_2MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_2MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0110
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_2MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_2MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1010
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_2MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_2MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1110
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
            }
            else if (Copy_u8PinMode == OUTPUT_50MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0011
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_50MHZ_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_50MHZ_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0111
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_50MHZ_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_50MHZ_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1011
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_50MHZ_AF_PUSHPULL <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_50MHZ_AF_PUSHPULL <<( (Copy_u8PinNumber-8) *4));
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1111
                {
                    if(Copy_u8PinNumber <= 7)
                    {
                        PORTC_CRL &= ~(0b1111 <<(Copy_u8PinNumber*4));
                        PORTC_CRL |=  (PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN <<(Copy_u8PinNumber*4));
                    }
                    else 
                    {
                        PORTC_CRH &= ~(0b1111 <<( (Copy_u8PinNumber-8) *4));
                        PORTC_CRH |=  (PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN <<( (Copy_u8PinNumber-8) *4));
                    }
                }
            }
            
        }
        break;
    default:
        break;
    }

}
void GPIO_voidSetPinValue    (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinValue)
{
    switch (Copy_u8PortNumber)
    {
    case PORTA:
        {
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(PORTA_ODR,Copy_u8PinNumber);
            }
            else
            {
                CLR_BIT(PORTA_ODR,Copy_u8PinNumber);
            }
        }
        break;
    case PORTB:
        {
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(PORTB_ODR,Copy_u8PinNumber);
            }
            else
            {
                CLR_BIT(PORTB_ODR,Copy_u8PinNumber);
            }
        }
        break;
    case PORTC:
        {
            if(Copy_u8PinValue == HIGH)
            {
                SET_BIT(PORTC_ODR,Copy_u8PinNumber);
            }
            else
            {
                CLR_BIT(PORTC_ODR,Copy_u8PinNumber);
            }
        }
        break;
    default:
        break;
    }
}
void GPIO_voidTogglePinValue    (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber )
{
    switch (Copy_u8PortNumber)
    {
    case PORTA:
        {
            TOG_BIT(PORTA_ODR,Copy_u8PinNumber);
        }
        break;
    case PORTB:
        {
            TOG_BIT(PORTB_ODR,Copy_u8PinNumber);
        }
        break;
    case PORTC:
        {
            TOG_BIT(PORTC_ODR,Copy_u8PinNumber);
        }
        break;
    default:
        break;
    }    
}
u8 GPIO_u8GetPinValue        (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber)
{
    u8 PinValue = 0 ;
    switch (Copy_u8PortNumber)
    {
    case PORTA:
        {
           PinValue = GET_BIT(PORTA_IDR , Copy_u8PinNumber);
        }
        break;
    case PORTB:
        {
           PinValue = GET_BIT(PORTB_IDR , Copy_u8PinNumber);
        }
        break;
    case PORTC:
        {
           PinValue = GET_BIT(PORTB_IDR , Copy_u8PinNumber);
        }
        break;
    default:
        break;
    }
    return PinValue ;
}
void GPIO_voidSetPortDirection (u8 Copy_u8PortNumber , u8 Copy_u8PinMode , u8 Copy_u8PinConfig , u8 Copy_u8PortPart)
{
    switch (Copy_u8PortNumber)
    {
    case PORTA:
        {
            if(Copy_u8PinMode == INPUT) 
            {
                if(Copy_u8PinConfig == ANALOG) // 0b0000
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_INPUT_ANALOG;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_INPUT_ANALOG;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_INPUT_ANALOG;
                        PORTA_CRH =  PORT_INPUT_ANALOG;
                    }

                }
                else if (Copy_u8PinConfig == FLOATING) // 0b0100
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_INPUT_FLOATING;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_INPUT_FLOATING;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_INPUT_FLOATING;
                        PORTA_CRH =  PORT_INPUT_FLOATING;
                    }
                }
                else if (Copy_u8PinConfig == PULL_UP_PULL_DOWN) // 0b1000
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_INPUT_PULLUP_PULLDOWN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_INPUT_PULLUP_PULLDOWN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_INPUT_PULLUP_PULLDOWN;
                        PORTA_CRH =  PORT_INPUT_PULLUP_PULLDOWN;
                    }
                }

            }
            else if (Copy_u8PinMode == OUTPUT_10MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0001
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_PUSHPULL;
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0101
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1001
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1101
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                        PORTA_CRH =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                    }
                }
                
                
            }
            else if (Copy_u8PinMode == OUTPUT_2MHZ)
            {
               if(Copy_u8PinConfig == PUSH_PULL) // 0b0010
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_PUSHPULL;
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0110
                {
                   if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1010
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1110
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                        PORTA_CRH =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                    }
                }
            }
            else if (Copy_u8PinMode == OUTPUT_50MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0011
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_PUSHPULL;
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0111
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1011
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1111
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTA_CRL =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                        PORTA_CRH =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                    }
                }
            }
        }
        break;
    case PORTB:
        {
            if(Copy_u8PinMode == INPUT) 
            {
                if(Copy_u8PinConfig == ANALOG) // 0b0000
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_INPUT_ANALOG;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_INPUT_ANALOG;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_INPUT_ANALOG;
                        PORTB_CRH =  PORT_INPUT_ANALOG;
                    }

                }
                else if (Copy_u8PinConfig == FLOATING) // 0b0100
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_INPUT_FLOATING;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_INPUT_FLOATING;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_INPUT_FLOATING;
                        PORTB_CRH =  PORT_INPUT_FLOATING;
                    }
                }
                else if (Copy_u8PinConfig == PULL_UP_PULL_DOWN) // 0b1000
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_INPUT_PULLUP_PULLDOWN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_INPUT_PULLUP_PULLDOWN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_INPUT_PULLUP_PULLDOWN;
                        PORTB_CRH =  PORT_INPUT_PULLUP_PULLDOWN;
                    }
                }

            }
            else if (Copy_u8PinMode == OUTPUT_10MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0001
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_PUSHPULL;
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0101
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_OPEN_DRAIN;
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1001
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_AF_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1101
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                        PORTB_CRH =  PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN;
                    }
                }
                
                
            }
            else if (Copy_u8PinMode == OUTPUT_2MHZ)
            {
               if(Copy_u8PinConfig == PUSH_PULL) // 0b0010
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_PUSHPULL;
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0110
                {
                   if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_OPEN_DRAIN;
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1010
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_AF_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1110
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                        PORTB_CRH =  PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN;
                    }
                }
            }
            else if (Copy_u8PinMode == OUTPUT_50MHZ)
            {
                if(Copy_u8PinConfig == PUSH_PULL) // 0b0011
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_PUSHPULL;
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == OPEN_DRAIN) // 0b0111
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_OPEN_DRAIN;
                    }
                }
                else if (Copy_u8PinConfig == AF_PUSH_PULL) // 0b1011
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_AF_PUSHPULL;
                    }
                }
                else if (Copy_u8PinConfig == AF_OPEN_DRAIN) // 0b1111
                {
                    if(Copy_u8PortPart == LOW_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                    }
                   else if(Copy_u8PortPart == HIGH_PORT)
                    {
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                    }
                    else if(Copy_u8PortPart == FULL_PORT)
                    {
                        PORTB_CRL =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                        PORTB_CRH =  PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN;
                    }
                }
            }
        }
        break;    
    
    default:
        break;
    }
}
void GPIO_voidSetPortValue (u8 Copy_u8PortNumber , u16 Copy_u8PortValue , u8 Copy_u8PortPart)
{
    switch (Copy_u8PortNumber)
    {
    case PORTA:
        {
            if(Copy_u8PortPart == LOW_PORT)
            {
                PORTA_ODR &= 0xFFFFFF00;
                PORTA_ODR |= (0x00000000 + Copy_u8PortValue) ;
            }
            else if (Copy_u8PortPart == HIGH_PORT)
            {
                PORTA_ODR &= 0xFFFF00FF;
                PORTA_ODR |= ( 0x00000000 + (Copy_u8PortValue<<8) );
            }
            else if (Copy_u8PortPart == FULL_PORT)
            {
                PORTA_ODR &= 0xFFFF0000;
                PORTA_ODR |= (0x00000000 + Copy_u8PortValue);
            }
        }
        break;
    case PORTB:
        {
            if(Copy_u8PortPart == LOW_PORT)
            {
                PORTB_ODR &= 0xFFFFFF00;
                PORTB_ODR |= (0x00000000 + Copy_u8PortValue) ;
            }
            else if (Copy_u8PortPart == HIGH_PORT)
            {
                PORTB_ODR &= 0xFFFF00FF;
                PORTB_ODR |= ( 0x00000000 + (Copy_u8PortValue<<8) );
            }
            else if (Copy_u8PortPart == FULL_PORT)
            {
                PORTB_ODR &= 0xFFFF0000;
                PORTB_ODR |= (0x00000000 + Copy_u8PortValue);
            }
        }
        break;
    case PORTC:
        {
            if(Copy_u8PortPart == LOW_PORT)
            {
                PORTC_ODR &= 0xFFFFFF00;
                PORTC_ODR |= (0x00000000 + Copy_u8PortValue) ;
            }
            else if (Copy_u8PortPart == HIGH_PORT)
            {
                PORTC_ODR &= 0xFFFF00FF;
                PORTC_ODR |= ( 0x00000000 + (Copy_u8PortValue<<8) );
            }
            else if (Copy_u8PortPart == FULL_PORT)
            {
                PORTC_ODR &= 0xFFFF0000;
                PORTC_ODR |= (0x00000000 + Copy_u8PortValue);
            }
        }
        break;
    default:
        break;

    }
}
