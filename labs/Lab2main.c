/*
 * GccApplication6.c
 *
 * Created: 9/2/2026 8:04:05 PM
 * Author : dell
 */ 

#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "util/delay.h"
#include "avr/io.h"
// #include "dio.c"


int main(void)
{
    DIO_voidSetPortDirection(DPORTA,INPUT);
	
	DIO_voidSetPinDirection(DPORTB,PIN2,INPUT);
	
	DIO_voidSetPinValue(DPORTA, PIN0, HIGH);
	DIO_voidSetPinValue(DPORTA, PIN1, HIGH);
	DIO_voidSetPinValue(DPORTA, PIN2, HIGH);
	DIO_voidSetPinValue(DPORTA, PIN7, HIGH);
	
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
    while (1) 
    {
		if(DIO_u8GetPinValue(DPORTA,PIN7) == LOW){
			DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
			DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		}
		
		else{
			DIO_voidSetPinValue(DPORTC,PIN0,!DIO_u8GetPinValue(DPORTA,PIN0));
			DIO_voidSetPinValue(DPORTC,PIN1,!DIO_u8GetPinValue(DPORTA,PIN1));
			DIO_voidSetPinValue(DPORTC,PIN2,!DIO_u8GetPinValue(DPORTA,PIN2));
		}
    }
}
