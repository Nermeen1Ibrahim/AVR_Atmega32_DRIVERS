#ifndef ADCANDLCD_H_
#define ADCANDLCD_H_
#include "dio.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register


extern void ADC_Init (void); // ADC Initialization And Enable
extern u16 ADC_Read (u8 ch); // Read From The ADC Channel

#define RS PIN7
#define RW PIN6
#define EN PIN5

//init
void LCD_init();
 
//char
void LCD_sendChar(u8 Data);
 
//send command
void LCD_SendCommand(u8 command);
 
//Send String
void LCD_SendString (u8 *str);


#endif /* ADC_INITIALIZATION_H_ */