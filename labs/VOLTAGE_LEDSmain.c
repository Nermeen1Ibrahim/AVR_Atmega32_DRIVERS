/*
 * GccApplication15.c
 *
 * Created: 9/7/2026 6:07:12 PM
 * Author : dell
 */ 

#include <avr/io.h>
#include "ADC.h"
#include <util/delay.h>
#define F_CPU 16000000 UL

int main(void)
{
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
	ADC_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		u16 adcval=ADC_Read(0);
		f32 voltage= (adcval*5.0)/1024.0;
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		DIO_voidSetPinValue(DPORTC,PIN2,LOW);
		
		if(voltage >0.0 && voltage<1.5){
	       DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		}
		else if(voltage >=1.5 && voltage<3){
			DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
		}
		else if(voltage >=3&&voltage<5 ){
			DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		}	
    }
}

