#ifndef DIO_H
#define DIO_H

#define INPUT 0
#define OUTPUT 1

 #define HIGH 1
 #define LOW 0
 
#define DPORTA 0
#define DPORTB 1
#define DPORTC 2
#define DPORTD 3
 
#define PIN0 0
#define PIN1 1 
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6 
#define PIN7 7

#include "STD_TYPES.h"
 
 
void	DIO_voidSetPinDirection		(u8 PortId,u8 PinId,u8 Direction); //DDR FOR EVERY PIN
 
void	DIO_voidSetPinValue			(u8 PortId,u8 PinId,u8 Value);//PORT FOR EVERY PIN
 
u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId);//RETURN PIN VALUE
 
 
void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction);//DDR FOR ALL PINS , PORT
void	DIO_voidSetPortValue		(u8 PortId,u8 Value);//PORT_REGISTER FOR ALL PINS
#endif
