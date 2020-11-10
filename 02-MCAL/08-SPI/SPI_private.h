/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-16                      */
/* Version  : V01                             */
/**********************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct 
{
    volatile u32 CR1     ;
    volatile u32 CR2     ;
    volatile u32 SR      ;
    volatile u32 DR      ;
    volatile u32 CRCPR   ;
    volatile u32 RXCRCR  ;
    volatile u32 TXCRCR  ;
    volatile u32 I2SCFGR ;
    volatile u32 I2SPR   ;
}SPI_Register;

#define SPI     ((SPI_Register*)0x40013000)

#define     SPI_DATA_8bit               0 
#define     SPI_DATA_16bit              1 

#define     SPI_TRANSMIT_AND_RECEIVE    0
#define     SPI_RECEIVE_ONLY            1

#define     SPI_HW                      0
#define     SPI_SW                      1

#define     SPI_MSB_FIRST               0
#define     SPI_LSB_FIRST               1

#define     SPI_CLK_DIV_BY_2            0
#define     SPI_CLK_DIV_BY_4            1
#define     SPI_CLK_DIV_BY_8            2
#define     SPI_CLK_DIV_BY_16           3
#define     SPI_CLK_DIV_BY_32           4
#define     SPI_CLK_DIV_BY_64           5
#define     SPI_CLK_DIV_BY_128          6
#define     SPI_CLK_DIV_BY_256          7

#define    SPI_SLAVE                    0
#define    SPI_MASTER                   1

#define  SPI_IDLE_0                     0
#define  SPI_IDLE_1                     1

#define  SPI_READ_WRITE                 0
#define  SPI_WRITE_READ                 1

#endif
