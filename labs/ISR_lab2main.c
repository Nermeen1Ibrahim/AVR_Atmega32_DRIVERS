/*
 * GccApplication14.c
 *
 * Created: 9/6/2026 8:11:41 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ISR.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "STD_TYPES.h"
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	DIO_voidSetPortDirection(DPORTC,0xFF);
	
	DIO_voidSetPinDirection(DPORTD,PIN2,INPUT);
	DIO_voidSetPinDirection(DPORTD,PIN3,INPUT);
	
	DIO_voidSetPinValue(DPORTD,PIN2,HIGH);
	
	initExternalInterupts();
	while (1)
	{
		for(u8 i=0;i<8;i++){
			DIO_voidSetPinValue(DPORTC,i,HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(DPORTC,i,LOW);
			_delay_ms(10);
		}
	}
}
ISR(INT0_vect){
	DIO_voidSetPortValue(DPORTC,0x00);
	for(u8 i=7;i>=0;i--){
		DIO_voidSetPinValue(DPORTC,i,HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DPORTC,i,LOW);
		_delay_ms(10);
	}
}

