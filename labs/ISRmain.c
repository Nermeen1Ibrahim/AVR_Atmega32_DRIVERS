/*
 * GccApplication13.c
 *
 * Created: 9/6/2026 7:17:51 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ISR.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "STD_TYPES.h"
#define F_CPU 1000000UL

int main(void)
{
    DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	
	DIO_voidSetPinDirection(DPORTD,PIN2,INPUT);
	DIO_voidSetPinDirection(DPORTD,PIN3,INPUT);
	
	DIO_voidSetPinValue(DPORTD,PIN2,HIGH);
	DIO_voidSetPinValue(DPORTD,PIN3,HIGH);
	
	initExternalInterupts();
    while (1) 
    {
    }
}
ISR(INT0_vect){
	toggle_bit(PORTC,PIN0);
}
ISR(INT1_vect){
	toggle_bit(PORTC,PIN1);
}

