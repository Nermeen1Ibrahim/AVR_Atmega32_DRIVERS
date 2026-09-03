#include "keybad.h"
#include <util/delay.h>
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