#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0.h"
#include <avr/interrupt.h>

void TIMER0_Init(void) {
	clr_bit(TCCR0, WGM00);
	clr_bit(TCCR0, WGM01);
	
	set_bit(TCCR0, CS02);
	clr_bit(TCCR0, CS01);
	set_bit(TCCR0, CS00);
}

void TIMER0_SetDelay(u32 Delay) {
	u32 OverflowCounter = 0;
	
	u32 MaxOverflows = (Delay * 1000UL) / 32768UL;
	
	TCNT0=0;
	set_bit(TIFR, TOV0);

	while (OverflowCounter < MaxOverflows) {
		
		while (GET_BIT(TIFR, TOV0) == 0);

		set_bit(TIFR, TOV0);

		OverflowCounter++;
	}
}

void TIMER0_InitCTC(){
	set_bit(TCCR0,WGM01);
	clr_bit(TCCR0,WGM00);
	
	set_bit(TCCR0, CS02);
	clr_bit(TCCR0, CS01);
	set_bit(TCCR0, CS00);
	
	
	set_bit(TIMSK,OCIE0);
	sei();
}

void TIMER0_SetOCR0(u8 Value){
	OCR0 = Value;
}