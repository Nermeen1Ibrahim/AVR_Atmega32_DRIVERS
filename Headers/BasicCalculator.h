#ifndef _ASS_H_
#define _ASS_H_
#include "dio.h"

#define D0 PD0
#define D1 PD1
#define D2 PD2
#define D3 PD3
#define D4 PD4
#define D5 PD5
#define D6 PD6
#define D7 PD7

#define RS PB0
#define RW PB1
#define EN  PB2

//init
void LCD_init();

//char
void LCD_sendChar(u8 Data);

//send command
void LCD_SendCommand(u8 command);

//Send String
void LCD_SendString (u8 *str);

void keybad_init();
u8 keybadGetKey();

#endif
