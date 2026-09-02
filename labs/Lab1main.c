/*
 * GccApplication5.c
 *
 * Created: 9/2/2026 7:09:57 PM
 * Author : dell
 */ 
#define F_CPU 1000000
#include <util/delay.h>
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

int main(void)
{
	 DDRA=0b00000010;
	 PORTA=0b00000001;
    /* Replace with your application code */
    while (1) 
    {
		if(GET_BIT(PINA,0)==0){
			PORTA=0b00000011;
		}
		else{
			PORTA=0b00000001;
		}
    }
}