/*
 * GccApplication16.c
 *
 * Created: 9/7/2026 7:03:47 PM
 * Author : dell
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "ADCandLCD.h"

int main(void) {
	ADC_Init();
	LCD_init();
    _delay_ms(50);
	
	while (1) {
		u16 adc_val = ADC_Read(0);
		u32 volt_mv = ((u32)adc_val * 5000) / 1024;
 
		LCD_SendCommand(0x80);
		LCD_SendString((u8*)" Voltage Value: ");
		
		LCD_SendCommand(0xC0);
		
		LCD_sendChar((volt_mv/1000) + '0');           
		LCD_sendChar(((volt_mv/100)%10) + '0');   
		LCD_sendChar(((volt_mv/10)% 10) + '0'); 
		LCD_sendChar((volt_mv%10)+'0');
		
		LCD_SendString((u8*)" mV ");

		_delay_ms(200);
	}
}
