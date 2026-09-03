#include "avr/io.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "ASS.h"
#include <util/delay.h>

void LCD_init(){
	DIO_voidSetPortDirection(DPORTD, OUTPUT);

	DIO_voidSetPinDirection(DPORTB, RS, OUTPUT);
	DIO_voidSetPinDirection(DPORTB, RW, OUTPUT);
	DIO_voidSetPinDirection(DPORTB, EN, OUTPUT);

	_delay_ms(40);

	LCD_SendCommand(0b00111000);
	_delay_ms(1);

	LCD_SendCommand(0b00001100);
	_delay_ms(1);

	LCD_SendCommand(0b00000001);
	_delay_ms(2);
}


void LCD_sendChar(u8 Data){
	DIO_voidSetPinValue(DPORTB,RS,HIGH);
	DIO_voidSetPinValue(DPORTB,EN,HIGH);
	
	DIO_voidSetPortValue(DPORTD,Data);
	DIO_voidSetPinValue(DPORTB,EN,LOW);
	_delay_ms(5);
}

void LCD_SendCommand(u8 command){
	DIO_voidSetPinValue(DPORTB,RS,LOW);
	DIO_voidSetPortValue(DPORTD,command);
	DIO_voidSetPinValue(DPORTB,EN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(DPORTB,EN,LOW);
}

void LCD_SendString (u8 *str){
	while(*str != '\0'){
		LCD_sendChar( *str);
		str++;
	}
}

u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};

keybad_init(){
	u8 i,j;
	for(i=PIN0;i<=PIN3;i++){
		DIO_voidSetPinDirection(DPORTC,i,OUTPUT);
		DIO_voidSetPinValue(DPORTC,i,HIGH);
	}
	for(j=PIN4;j<=PIN7;j++){
		DIO_voidSetPinDirection(DPORTC,j,INPUT);
		DIO_voidSetPinValue(DPORTC,j,HIGH);
	}
}

u8 keybadGetKey(){
	u8 row,col,result,pressedKey=LOW;
	for(row=0;row<4;row++){
		DIO_voidSetPinValue(DPORTC,row,LOW);
		for(col=0;col<4;col++){
			result=DIO_u8GetPinValue(DPORTC,col+PIN4);
			if(result==LOW){
				_delay_ms(20);
				pressedKey=arr[row][col];
				while(result==LOW){
					result=DIO_u8GetPinValue(DPORTC,col+PIN4);
				}
			}
		}
		DIO_voidSetPinValue(DPORTC,row,HIGH);
	}
	return pressedKey;
}