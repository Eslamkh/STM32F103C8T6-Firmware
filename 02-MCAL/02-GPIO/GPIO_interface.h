/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 12 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/
#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#define HIGH                  1
#define LOW                   0

#define PORTA                 0
#define PORTB                 1
#define PORTC                 2

/* Pin Mode */
#define INPUT                 0
#define OUTPUT_10MHZ          1
#define OUTPUT_2MHZ           2
#define OUTPUT_50MHZ          3

/* Pin Configuration Input Mode */
#define ANALOG                0
#define FLOATING              1
#define PULL_UP_PULL_DOWN     2

/* Pin Configuration Output Mode */
#define PUSH_PULL             0
#define OPEN_DRAIN            1
#define AF_PUSH_PULL          2
#define AF_OPEN_DRAIN         3

/* Port Direction */
#define LOW_PORT              0
#define HIGH_PORT             1
#define FULL_PORT             2

void GPIO_voidSetPinDirection(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinMode , u8 Copy_u8PinConfig);
void GPIO_voidSetPinValue    (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinValue);
void GPIO_voidTogglePinValue    (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber );
u8 GPIO_u8GetPinValue        (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber);

void GPIO_voidSetPortDirection (u8 Copy_u8PortNumber , u8 Copy_u8PortMode , u8 Copy_u8PortConfig , u8 Copy_u8PortPart);
void GPIO_voidSetPortValue     (u8 Copy_u8PortNumber , u16 Copy_u8PortValue , u8 Copy_u8PortPart);

#endif
