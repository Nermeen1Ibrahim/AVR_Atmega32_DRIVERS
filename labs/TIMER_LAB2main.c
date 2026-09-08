/*
 * GccApplication21.c
 *
 * Created: 9/8/2026 7:06:36 PM
 * Author : dell
 */ 

#include "STD_TYPES.h"
#include "ADC.h"
#include "TIMER0.h"
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMP_vect)
{
	static u8 state=0;
	state =!state;
	 
		DIO_voidSetPinValue(DPORTC, PIN0, state);
}

int main(void){
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);

    ADC_Init();
	TIMER0_InitCTC();
    sei();
	while (1)
	{
		u16 pot_value = ADC_Read(0);
		u8 compare_value = (u8)(pot_value / 4);
        
		if(compare_value==0){
			compare_value=1;
		}
		TIMER0_SetOCR0(compare_value);
	}
}
