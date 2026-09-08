/*
 * GccApplication20.c
 *
 * Created: 9/8/2026 5:43:45 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include "TIMER0.h"
#define F_CPU 8000000UL
int main(void)
{
	DIO_voidSetPinDirection(DPORTB,PIN0,OUTPUT);
	TIMER0_Init();
    while (1) 
    {
	
		toggle_bit(PORTB,PIN0);
		TIMER0_SetDelay(1000);
    }
}


