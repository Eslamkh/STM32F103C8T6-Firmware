/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-16                      */
/* Version  : V01                             */
/**********************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_SLAVE_PIN       PORTA,4
/* Write it in pair port,pin */
#define SPI_DATA_SIZE       SPI_DATA_8bit       
/* Options */
/*
    SPI_DATA_8bit  
    SPI_DATA_16bit 
*/
#define SPI_TRANSFER_DIRECTION      SPI_TRANSMIT_AND_RECEIVE
/* Options */
/*
    SPI_TRANSMIT_AND_RECEIVE
    SPI_RECEIVE_ONLY        
*/
#define SPI_SLAVE_MANAGEMENT        SPI_SW
/* Options */
/*
    SPI_HW 
    SPI_SW 
*/
#define  SPI_FRAME_FORMAT           SPI_MSB_FIRST
/* Options */
/*
    SPI_MSB_FIRST
    SPI_LSB_FIRST
*/
#define  SPI_PRESCALER              SPI_CLK_DIV_BY_2
/* Options */
/*
    SPI_CLK_DIV_BY_2
    SPI_CLK_DIV_BY_4
    SPI_CLK_DIV_BY_8
    SPI_CLK_DIV_BY_16
    SPI_CLK_DIV_BY_32
    SPI_CLK_DIV_BY_64
    SPI_CLK_DIV_BY_128
    SPI_CLK_DIV_BY_256
*/
#define  SPI_NODE_CONFIGURATION      SPI_MASTER
/* Options */
/*
    SPI_MASTER
    SPI_SLAVE
*/
#define  SPI_CLK_PRIORITY           SPI_IDLE_1
/* Options */
/*
    SPI_IDLE_0
    SPI_IDLE_1
*/
#define  SPI_CLK_PHASE              SPI_WRITE_READ
/* Options */
/*
    SPI_READ_WRITE
    SPI_WRITE_READ
*/
#endif
