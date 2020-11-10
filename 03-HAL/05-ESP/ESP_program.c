/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-10-01                      */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "ESP_interface.h"
#include  "ESP_config.h"
#include  "ESP_private.h"

#include "UART_interface.h"

volatile u8 Global_u8Response [100] = {0};

void ESP_voidInit(void)
{
    u8 Local_validateFlag = 0 ;
    while (Local_validateFlag == 0)
    {
        UART_voidTransmit(1,"ATE0/r/n");            // Stop echo
        Local_validateFlag = ValidateCmd();
    }
    Local_validateFlag = 0 ;
    while (Local_validateFlag == 0)
    {
         UART_voidTransmit(1,"AT+CWMODE=1\r\n");      // Set Station Mode
         Local_validateFlag = ValidateCmd();
    }
}
void ESP_voidConnectWIFI(u8 *Copy_WIFIName , u8 *Copy_WIFIPass)
{
    u8 Local_validateFlag = 0 ;
    while (Local_validateFlag == 0)
    {
        UART_voidTransmit(1,"AT+CWJAP_CUR=,\"");
        UART_voidTransmit(1,Copy_WIFIName);   
        UART_voidTransmit(1,"\",\""); 
        UART_voidTransmit(1,Copy_WIFIPass);
        UART_voidTransmit(1,"\"\r\n");           
        Local_validateFlag = ValidateCmd();
    }   
}
void ESP_voidConnectServer(u8 *Copy_ServerIP )
{
    u8 Local_validateFlag = 0 ;
    
    while (Local_validateFlag == 0)
    {
        UART_voidTransmit(1,"AT+CIPSTART=\"TCP\",\"");
        UART_voidTransmit(1,Copy_ServerIP);   
        UART_voidTransmit(1,",\","); 
        UART_voidTransmit(1,80);
        UART_voidTransmit(1,"\r\n");           
        Local_validateFlag = ValidateCmd();
    }
}
u8 ESP_u8GetDataFromLink(u8 *Copy_FileLink )
{
    u8 Local_validateFlag = 0 ;
    u8 Local_u8Length = 0 ;
    u8 * Link = Copy_FileLink ;
    u8 DataReceived = 0;
    while (*Link)
    {
        Local_u8Length += 1;
    }
    Local_u8Length += 2;
    while (Local_validateFlag == 0)
    {
        UART_voidTransmit(1,"AT+CIPSEND=");
        UART_voidTransmit(1,Local_u8Length);              
        Local_validateFlag = ValidateCmd();
    }
    Local_validateFlag = 0 ;
    while (Local_validateFlag == 0)
    {
        UART_voidTransmit(1,"GET ");
        UART_voidTransmit(1,Copy_FileLink);    
        Local_validateFlag = ValidateCmd();
    }
    u8 i = 0 ;
    while(Global_u8Response[i] != ':')
    {
        i += 1;
    }
    DataReceived = Global_u8Response[i+1];
    return DataReceived;
    
}
u8 ValidateCmd (void)
{
    u8 Global_u8Response [100] = {0};
    u8 i = 0 ;
    u8 Dumb = 0 ;
    u8 Local_u8Flag = 0;
    while(Dumb != 255)
    {
        Dumb = UART_u8Receive(1);
        Global_u8Response[i] = Dumb ;
        i += 1;   
    }
    if( ( (Global_u8Response[0] == 'O') & (Global_u8Response[1] == 'K') )
        |( (Global_u8Response[10] == 'O') & (Global_u8Response[11] == 'K') )
        |( (Global_u8Response[11] == 'O') & (Global_u8Response[12] == 'K') )
        |( (Global_u8Response[20] == 'O') & (Global_u8Response[21 ] == 'K') ) )
        Local_u8Flag = 1;
    else if( (Global_u8Response[5] == 'C') & (Global_u8Response[6] == 'O') & (Global_u8Response[7] == 'N')
            & (Global_u8Response[8] == 'E') & (Global_u8Response[9] == 'C') & (Global_u8Response[10] == 'T')
            & (Global_u8Response[11] == 'E') & (Global_u8Response[12] == 'D') )
        Local_u8Flag = 1;
    return Local_u8Flag ;
}
