/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-16                      */
/* Version  : V01                             */
/**********************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI1_voidInit(void);
void SPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8ptrDataToReceive);

#endif
