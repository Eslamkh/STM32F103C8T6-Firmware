/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-10-01                      */
/* Version  : V01                             */
/**********************************************/
#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_voidConnectWIFI(u8 *Copy_WIFIName , u8 *Copy_WIFIPass);
void ESP_voidConnectServer(u8 *Copy_ServerIP );
u8 ESP_u8GetDataFromLink(u8 *Copy_FileLink );

#endif