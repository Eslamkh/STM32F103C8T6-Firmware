/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 12 Aug 2020                     */
/* Version  : V01                             */
/**********************************************/

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H
/* Registers Addresses */
#define PORTA_CRL     *(( volatile u32 *)0x40010800)
#define PORTA_CRH	  *(( volatile u32 *)0x40010804)
#define PORTA_IDR     *(( volatile u32 *)0x40010808)
#define PORTA_ODR	  *(( volatile u32 *)0x4001080C)

#define PORTB_CRL     *(( volatile u32 *)0x40010C00)
#define PORTB_CRH	  *(( volatile u32 *)0x40010C04)
#define PORTB_IDR     *(( volatile u32 *)0x40010C08)
#define PORTB_ODR	  *(( volatile u32 *)0x40010C0C)

#define PORTC_CRL     *(( volatile u32 *)0x40011000)
#define PORTC_CRH	  *(( volatile u32 *)0x40011004)
#define PORTC_IDR     *(( volatile u32 *)0x40011008)
#define PORTC_ODR	  *(( volatile u32 *)0x4001100C)

/* Pin Direction Values*/
#define PIN_INPUT_ANALOG                   0b0000
#define PIN_INPUT_FLOATING                 0b0100
#define PIN_INPUT_PULLUP_PULLDOWN          0b1000

#define PIN_OUTPUT_10MHZ_PUSHPULL          0b0001
#define PIN_OUTPUT_10MHZ_OPEN_DRAIN        0b0101
#define PIN_OUTPUT_10MHZ_AF_PUSHPULL       0b1001
#define PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN     0b1101

#define PIN_OUTPUT_2MHZ_PUSHPULL           0b0010
#define PIN_OUTPUT_2MHZ_OPEN_DRAIN         0b0110
#define PIN_OUTPUT_2MHZ_AF_PUSHPULL        0b1010
#define PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN      0b1110

#define PIN_OUTPUT_50MHZ_PUSHPULL          0b0011
#define PIN_OUTPUT_50MHZ_OPEN_DRAIN        0b0111
#define PIN_OUTPUT_50MHZ_AF_PUSHPULL       0b1011    
#define PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN     0b1111

/* PORT Direction Values*/
#define PORT_INPUT_ANALOG                   0x00000000
#define PORT_INPUT_FLOATING                 0x44444444
#define PORT_INPUT_PULLUP_PULLDOWN          0x88888888

#define PORT_OUTPUT_10MHZ_PUSHPULL          0x11111111
#define PORT_OUTPUT_10MHZ_OPEN_DRAIN        0x55555555
#define PORT_OUTPUT_10MHZ_AF_PUSHPULL       0x99999999
#define PORT_OUTPUT_10MHZ_AF_OPEN_DRAIN     0xDDDDDDDD

#define PORT_OUTPUT_2MHZ_PUSHPULL           0x22222222
#define PORT_OUTPUT_2MHZ_OPEN_DRAIN         0x66666666
#define PORT_OUTPUT_2MHZ_AF_PUSHPULL        0xAAAAAAAA
#define PORT_OUTPUT_2MHZ_AF_OPEN_DRAIN      0xEEEEEEEE

#define PORT_OUTPUT_50MHZ_PUSHPULL          0x33333333
#define PORT_OUTPUT_50MHZ_OPEN_DRAIN        0x77777777
#define PORT_OUTPUT_50MHZ_AF_PUSHPULL       0xBBBBBBBB    
#define PORT_OUTPUT_50MHZ_AF_OPEN_DRAIN     0xFFFFFFFF


#endif
