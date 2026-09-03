/*
 * GccApplication8.c
 *
 * Created: 9/3/2026 10:57:46 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include "keybad.h"
#include <util/delay.h>
#define F_CPU 1000000UL


int main(void)
{
    u8 ARR[10]={
		0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111
	};
	u8 key=0xFF;
	DIO_voidSetPortDirection(DPORTD,key);
	DIO_voidSetPortValue(DPORTD,LOW);
	keybad_init();
    while (1) 
    {
		key=keybadGetKey();
		if(key>='0'&& key<='9'){
			u8 number=key-'0';
			DIO_voidSetPortValue(DPORTD,ARR[number]);
		}
		
    }
}

