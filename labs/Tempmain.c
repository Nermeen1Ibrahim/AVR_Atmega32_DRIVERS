/*
 * GccApplication17.c
 *
 * Created: 9/7/2026 8:25:41 PM
 * Author : dell
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "ADC.h"


int main(void) {
	u16 adc_value = 0;
	f32 voltage = 0.0;
	f32 temp = 0.0;

	
	ADC_Init();

	DIO_voidSetPinDirection(DPORTC, PIN0,OUTPUT);  //YELLOW
	DIO_voidSetPinDirection(DPORTC, PIN1,OUTPUT); //GREEN
	DIO_voidSetPinDirection(DPORTC, PIN2,OUTPUT); //RED
	DIO_voidSetPinDirection(DPORTC, PIN3,OUTPUT); //BUZZER

	DIO_voidSetPinValue(DPORTC, PIN0,HIGH);  //YELLOW
	DIO_voidSetPinValue(DPORTC, PIN1,HIGH); //GREEN
	DIO_voidSetPinValue(DPORTC, PIN2,HIGH); //RED
	DIO_voidSetPinValue(DPORTC, PIN3,HIGH); //BUZZER

	while (1) {

		adc_value = ADC_Read(0);
		
		
		voltage = (adc_value * 5.0) / 1024.0;
		temp = voltage * 100.0;
		

		DIO_voidSetPinValue(DPORTC, PIN0,LOW);  //YELLOW
		DIO_voidSetPinValue(DPORTC, PIN1,LOW); //GREEN
		DIO_voidSetPinValue(DPORTC, PIN2,LOW); //RED
		DIO_voidSetPinValue(DPORTC, PIN3,LOW); //BUZZER

		
		if (temp < 20.0) {
			DIO_voidSetPinValue(DPORTC, PIN1,HIGH); //GREEN
		}

		else if (temp >= 20.0 && temp <= 40.0) {
			DIO_voidSetPinValue(DPORTC, PIN0,OUTPUT);  //YELLOW
		}
		
		else if (temp > 40.0) {
			DIO_voidSetPinValue(DPORTC, PIN2,HIGH); //RED
			DIO_voidSetPinValue(DPORTC, PIN3,HIGH); //BUZZER
		}

		_delay_ms(200);
	}

	return 0;
}

