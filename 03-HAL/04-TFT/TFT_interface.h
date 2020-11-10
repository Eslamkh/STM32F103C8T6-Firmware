/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-21                      */
/* Version  : V01                             */
/**********************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H
void TFT_voidInit(void);
void TFT_voidDisplayImage(const u16 *Copy_Image);
void TFT_voidFillColor(u16 Copy_u16Color);
void TFT_voidDrawRect(u8 Copy_u8XStart , u8 Copy_u8XEnd , u8 Copy_u8YStart , u8 Copy_u8YEnd , u16 Copy_u16Color);
void TFT_voidWritePixel (u8 Copy_u8X , u8 Copy_u8Y , u16 Copy_u16Color);
void TFT_voidWriteChar(u8 Copy_u8Char , u8 Copy_u8X , u8 Copy_u8Y , u16 Copy_u16Color);
void TFT_voidWriteString(u8 *Copy_u8String , u8 Copy_u8X , u8 Copy_u8Y , u16 Copy_u16Color);

#endif
