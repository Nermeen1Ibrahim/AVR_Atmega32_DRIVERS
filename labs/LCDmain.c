/*
 * GccApplication7.c
 *
 * Created: 9/3/2026 7:10:54 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "util/delay.h"
#define  F_CPU 8000000UL
int main(void)
{
    LCD_init();
	LCD_SendCommand(0x80+2);
	LCD_SendString((u8*)" Nermeen");
    while (1) 
    {
    }
}

