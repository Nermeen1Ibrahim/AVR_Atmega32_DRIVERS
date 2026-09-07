#include "ADCandLCD.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 16000000UL

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
void LCD_init(){
    DIO_voidSetPortDirection(DPORTB, OUTPUT);

    DIO_voidSetPinDirection(DPORTA, RS, OUTPUT);
    DIO_voidSetPinDirection(DPORTA, RW, OUTPUT);
    DIO_voidSetPinDirection(DPORTA, EN, OUTPUT);

    _delay_ms(40);

    LCD_SendCommand(0b00111000);
    _delay_ms(1);

    LCD_SendCommand(0b00001100);
    _delay_ms(1);

    LCD_SendCommand(0b00000001);
    _delay_ms(2);
}


void LCD_sendChar(u8 Data){
	DIO_voidSetPinValue(DPORTA,RS,HIGH);
	DIO_voidSetPinValue(DPORTA,RW,LOW);
	DIO_voidSetPortValue(DPORTB,Data);
	DIO_voidSetPinValue(DPORTA,EN,HIGH);
    _delay_ms(1);
	DIO_voidSetPinValue(DPORTA,EN,LOW);
	_delay_ms(5);
}

void LCD_SendCommand(u8 command){
	DIO_voidSetPinValue(DPORTA,RS,LOW);
	DIO_voidSetPinValue(DPORTA,RW,LOW);
	DIO_voidSetPortValue(DPORTB,command);
	DIO_voidSetPinValue(DPORTA,EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DPORTA,EN,LOW);
	_delay_ms(5);  
}

void LCD_SendString (u8 *str){
	while(*str != '\0'){
		LCD_sendChar( *str);
		str++;
	}
}