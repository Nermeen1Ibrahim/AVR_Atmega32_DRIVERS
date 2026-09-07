#include "ADC.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void ADC_Init (void){
	set_bit(ADMUX_Reg,6);
	clr_bit(ADMUX_Reg,7);
	set_bit(ADCSRA_Reg,7);
	
	set_bit(ADCSRA_Reg,0);
	set_bit(ADCSRA_Reg,1);
	set_bit(ADCSRA_Reg,2);
	
}
u16 ADC_Read (u8 ch){
	clr_bit(ADMUX_Reg,0);
	clr_bit(ADMUX_Reg,1);
	clr_bit(ADMUX_Reg,2);
	if(GET_BIT(ch,0)==1) set_bit(ADMUX_Reg,0);
	if(GET_BIT(ch,1)==1) set_bit(ADMUX_Reg,1);
	if(GET_BIT(ch,2)==1) set_bit(ADMUX_Reg,2);
	
	set_bit(ADCSRA_Reg,6);
	while(GET_BIT(ADCSRA_Reg,6)==1);
	u16 adc_val = ADCL_Reg;
	adc_val +=(ADCH_Reg*256);
	return adc_val;
}