/*
 * GccApplication11.c
 *
 * Created: 9/5/2026 4:58:25 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include "dio.h"
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN3,OUTPUT);
	while (1)
	{
		DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		DIO_voidSetPinValue(DPORTC,PIN2,LOW);
		DIO_voidSetPinValue(DPORTC,PIN3,HIGH);
		_delay_ms(5000);
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN3,LOW);
		_delay_ms(5000);
	}
}

