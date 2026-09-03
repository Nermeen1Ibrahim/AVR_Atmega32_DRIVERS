#ifndef _LCD_H_
#define _LCD_H_
#include "dio.h"

#define D0 PC0
#define D1 PC1
#define D2 PC2
#define D3 PC3
#define D4 PC4
#define D5 PC5
#define D6 PC6
#define D7 PC7

#define RS PD0
#define RW PD1
#define EN  PD2

//init
void LCD_init();
 
//char
void LCD_sendChar(u8 Data);
 
//send command
void LCD_SendCommand(u8 command);
 
//Send String
void LCD_SendString (u8 *str);


#endif