/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-16                      */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "SPI_interface.h"
#include  "SPI_config.h"
#include  "SPI_private.h"

#include "GPIO_interface.h"

void SPI1_voidInit(void)
{
	SPI -> CR1 = 0x0040 ;
    #if SPI_DATA_SIZE == SPI_DATA_16bit
        SET_BIT(SPI->CR1 , 11);
    #endif
    #if SPI_TRANSFER_DIRECTION == SPI_RECEIVE_ONLY
        SET_BIT(SPI->CR1 , 10);
    #endif 
    #if SPI_FRAME_FORMAT == SPI_LSB_FIRST  
        SET_BIT(SPI->CR1 , 7);
    #endif 
    #if SPI_PRESCALER == SPI_CLK_DIV_BY_4  
        SET_BIT(SPI->CR1 , 3);
    #elif SPI_PRESCALER == SPI_CLK_DIV_BY_8 
        SET_BIT(SPI->CR1 , 4);
    #elif SPI_PRESCALER == SPI_CLK_DIV_BY_16  
        SET_BIT(SPI->CR1 , 3);
        SET_BIT(SPI->CR1 , 4);
    #elif SPI_PRESCALER == SPI_CLK_DIV_BY_32
        SET_BIT(SPI->CR1 , 5);
    #elif SPI_PRESCALER == SPI_CLK_DIV_BY_64
        SET_BIT(SPI->CR1 , 3);
        SET_BIT(SPI->CR1 , 5);
    #elif SPI_PRESCALER == SPI_CLK_DIV_BY_128
        SET_BIT(SPI->CR1 , 4);
        SET_BIT(SPI->CR1 , 5);
    #elif SPI_PRESCALER == SPI_CLK_DIV_BY_256
        SET_BIT(SPI->CR1 , 3);
        SET_BIT(SPI->CR1 , 4);
        SET_BIT(SPI->CR1 , 5);
    #endif
    #if SPI_NODE_CONFIGURATION == SPI_MASTER
        SET_BIT(SPI -> CR1 , 2);
        SET_BIT(SPI -> CR1 , 8);
    #endif
    #if SPI_CLK_PRIORITY == SPI_IDLE_1
        SET_BIT(SPI -> CR1 , 1);
    #endif
    #if SPI_CLK_PHASE == SPI_WRITE_READ
        SET_BIT(SPI -> CR1 , 0);
    #endif 
    #if SPI_SLAVE_MANAGEMENT == SPI_SW
        SET_BIT(SPI ->CR1 , 9);
    #endif

}
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8ptrDataToReceive)
{
    GPIO_voidSetPinValue(SPI_SLAVE_PIN , LOW);
    SPI -> DR = Copy_u8DataToTransmit ;
    while (GET_BIT(SPI -> SR , 7) == 1);
    *Copy_u8ptrDataToReceive = SPI -> DR ;
    GPIO_voidSetPinValue(SPI_SLAVE_PIN , HIGH);

}
