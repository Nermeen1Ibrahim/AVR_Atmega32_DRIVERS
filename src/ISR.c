#include "avr/io.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "ISR.h"
#include <util/delay.h>
#include <avr/interrupt.h>


void initExternalInterupts(void){
	clr_bit(MCUCR,ISC01);
	set_bit(MCUCR,ISC00);
	
	clr_bit(MCUCR,ISC11);
	set_bit(MCUCR,ISC10);
	
	set_bit(GICR,INT0);
	set_bit(GICR,INT1);
	sei();
}