#include "avr/io.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "LCD.h"

void LCD_init(){
    DIO_voidSetPortDirection(DPORTC, OUTPUT);

    DIO_voidSetPinDirection(DPORTD, RS, OUTPUT);
    DIO_voidSetPinDirection(DPORTD, RW, OUTPUT);
    DIO_voidSetPinDirection(DPORTD, EN, OUTPUT);

    _delay_ms(40);

    LCD_SendCommand(0b00111000);
    _delay_ms(1);

    LCD_SendCommand(0b00001100);
    _delay_ms(1);

    LCD_SendCommand(0b00000001);
    _delay_ms(2);
}


void LCD_sendChar(u8 Data){
	DIO_voidSetPinValue(DPORTD,RS,HIGH);
	DIO_voidSetPinValue(DPORTD,EN,HIGH);
	
	DIO_voidSetPortValue(DPORTC,Data);
	DIO_voidSetPinValue(DPORTD,EN,LOW);
	_delay_ms(5);
}

void LCD_SendCommand(u8 command){
	DIO_voidSetPinValue(DPORTD,RS,LOW);
	DIO_voidSetPortValue(DPORTC,command);
	DIO_voidSetPinValue(DPORTD,EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DPORTD,EN,LOW);
}

void LCD_SendString (u8 *str){
	while(*str != '\0'){
		LCD_sendChar( *str);
		str++;
	}
}