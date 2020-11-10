/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-21                      */
/* Version  : V01                             */
/**********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "TFT_interface.h"
#include  "TFT_config.h"
#include  "TFT_private.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

void TFT_voidInit(void)
{
    /* Reset Pulse */
    GPIO_voidSetPinValue(TFT_RESET_PIN , HIGH);
    SYSTICK_voidSetBusyWait(100);
    GPIO_voidSetPinValue(TFT_RESET_PIN , LOW);
    SYSTICK_voidSetBusyWait(1);
    GPIO_voidSetPinValue(TFT_RESET_PIN , HIGH);
    SYSTICK_voidSetBusyWait(100);
    GPIO_voidSetPinValue(TFT_RESET_PIN , LOW);
    SYSTICK_voidSetBusyWait(100);
    GPIO_voidSetPinValue(TFT_RESET_PIN , HIGH);
    SYSTICK_voidSetBusyWait(120000);

    /* Sleepout Command */
    WriteCommand(0x11);
    SYSTICK_voidSetBusyWait(150000);

    /* Color mode Command */
    WriteCommand(0x3A);
    WriteData(0x05);

    /* Display on Command */
    WriteCommand(0x29);
}
void TFT_voidDisplayImage(const u16 *Copy_Image)
{
    /* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);

	/* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);

	/* RAM Write */
	WriteCommand(0x2C);

	u16 Counter ;

	for(Counter = 0 ; Counter < 20480 ; Counter++)
	{
		WriteData(Copy_Image[Counter] >> 8);
		WriteData(Copy_Image[Counter] & 0x00ff);
	}
}

static void WriteCommand(u8 Copy_u8Command)
{
    u8 Local_u8Temp ;
    /* Set A0 Low */
    GPIO_voidSetPinValue(TFT_A0_PIN,LOW);
    /* Send Command with SPI */
    SPI_voidSendReceiveSynch(Copy_u8Command , &Local_u8Temp);
}
static void WriteData (u8 Copy_u8Data)
{
    u8 Local_u8Temp;
    /* Set A0 High */
    GPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
    /* Send Data with SPI */
    SPI_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp);
}
void TFT_voidFillColor(u16 Copy_u16Color)
{
    /* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);

	/* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);

	/* RAM Write */
	WriteCommand(0x2C);

	for(u16 Counter = 0 ; Counter < 20480 ; Counter++)
	{
		WriteData(Copy_u16Color >> 8);
		WriteData(Copy_u16Color & 0x00ff);
	}
}
void TFT_voidDrawRect(u8 Copy_u8XStart , u8 Copy_u8XEnd , u8 Copy_u8YStart , u8 Copy_u8YEnd , u16 Copy_u16Color)
{
    /* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(Copy_u8XStart);
	WriteData(0);
	WriteData(Copy_u8XEnd);

	/* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(Copy_u8YStart);
	WriteData(0);
	WriteData(Copy_u8YEnd);

	/* RAM Write */
	WriteCommand(0x2C);
    u16 RectSize = ( Copy_u8XEnd - Copy_u8XStart ) * ( Copy_u8YEnd - Copy_u8YStart );
	for(u16 Counter = 0 ; Counter < RectSize ; Counter++)
	{
		WriteData(Copy_u16Color >> 8);
		WriteData(Copy_u16Color & 0x00ff);
	}
}
void TFT_voidWritePixel (u8 Copy_u8X , u8 Copy_u8Y , u16 Copy_u16Color)
{
    /* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(Copy_u8X);
	WriteData(0);
	WriteData(Copy_u8X + 1);

	/* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(Copy_u8Y);
	WriteData(0);
	WriteData(Copy_u8Y + 1);

	/* RAM Write */
	WriteCommand(0x2C);
    WriteData(Copy_u16Color >> 8);
	WriteData(Copy_u16Color & 0x00ff);

}
void TFT_voidWriteChar(u8 Copy_u8Char , u8 Copy_u8X , u8 Copy_u8Y, u16 Copy_u16Color)
{
    /* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(Copy_u8X);
	WriteData(0);
	WriteData(Copy_u8X + 11);

	/* Set Y Address */
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(Copy_u8Y);
	WriteData(0);
	WriteData(Copy_u8Y + 8);

	/* RAM Write */
	WriteCommand(0x2C);
	u16 Local_u16Data[CHAR_WIDTH -1];
	u16 temp = 0;
	if( (Copy_u8Char >= 48) & (Copy_u8Char <= 57) )
	{
		for(u8 t=0 ; t <CHAR_WIDTH ; t++)
		{
		 Local_u16Data[t] = TFTNumbers [Copy_u8Char - 48][t];
		}
	}
    else if( (Copy_u8Char >= 65) & (Copy_u8Char <= 90) )
	{
		for(u8 t=0 ; t <CHAR_WIDTH ; t++)
		{
		 Local_u16Data[t] = TFTLetters [Copy_u8Char - 65][t];
		}
	}
	for(u8 y = 0 ; y < CHAR_WIDTH ; y++)
	{
        temp = Local_u16Data[y];
        for (u8 x = 0; x < 16; x++) // Loop on the nubmer of bits
        {
            if(temp & 1<<x) 
            {
                TFT_voidWritePixel(Copy_u8X + x , Copy_u8Y + y , Copy_u16Color); // write the pixel if it's 1
            }
        }
	}
}
void TFT_voidWriteString(u8 *Copy_u8String , u8 Copy_u8X , u8 Copy_u8Y , u16 Copy_u16Color)
{
    u8 Local_count = 0;
	while(*Copy_u8String)
	    {
	       Copy_u8String += 1;
	       Local_count += 1;
	    }
	Copy_u8String -= 1;
    for(u8 temp = 0 ; temp <Local_count ; temp++)
	    {
	        if(*Copy_u8String != ' ')
	        {
	            TFT_voidWriteChar(*Copy_u8String , Copy_u8X , Copy_u8Y , Copy_u16Color);
	        }
	        Copy_u8X += 10;
	        Copy_u8String -= 1;
	    }
}
