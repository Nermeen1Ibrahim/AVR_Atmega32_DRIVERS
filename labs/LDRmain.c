/*
 * GccApplication18.c
 *
 * Created: 9/7/2026 9:32:36 PM
 * Author : dell
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "ADC.h"

int main(void) {
	ADC_Init();
	
	DIO_voidSetPinDirection(DPORTB, PIN0,OUTPUT);
	u16 adc_val = 0;
	u16 threshold = 1000;

	while (1) {
		adc_val = ADC_Read(0);
		
		if (adc_val < threshold) {
			DIO_voidSetPinValue(DPORTB, PIN0, HIGH);
			} else {
			DIO_voidSetPinValue(DPORTB, PIN0, LOW);
		}
		
		_delay_ms(100);
	}
}