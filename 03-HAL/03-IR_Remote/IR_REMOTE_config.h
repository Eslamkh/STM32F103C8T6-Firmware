/**********************************************/
/* Author   : Eslam Khaled                    */
/* Date     : 2020-09-12                      */
/* Version  : V01                             */
/**********************************************/
#ifndef IR_REMOTE_CONFIG_H
#define IR_REMOTE_CONFIG_H

#define IR_REMOTE_TIMER         IR_REMOTE_SYSTICK
/* Options */
/*
 IR_REMOTE_SYSTICK           
 IR_REMOTE_TIMER2            
 IR_REMOTE_TIMER3            
 IR_REMOTE_TIMER4                      
*/

#define IR_REMOTE_PORT          IR_REMOTE_PORTB
/* Options */
/*
 IR_REMOTE_PORTA  
 IR_REMOTE_PORTB  
 IR_REMOTE_PORTC                          
*/

#define IR_REMOTE_PIN           0
/* Options */
// 0 1 2 3 4 //

#define REMOTE_COLUMNS          3
#define REMOTE_RAWS             7
/*
    (0,0)   (0,1)     .    .    .   (0,COLUMNS)
      .       .       .    .    .      .
      .       .       .    .    .      .
      .       .       .    .    .      .
      .       .       .    .    .      .
      .       .       .    .    .      .
      .       .       .    .    .      .
      .       .       .    .    .      .
      .       .       .    .    .      .
   (RAWS,0) (RAWS,1)  .    .    .   (RAWS,COLUMNS)
*/  

#endif
