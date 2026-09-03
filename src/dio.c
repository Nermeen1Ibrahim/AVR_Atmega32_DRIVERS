#include "avr/io.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
void DIO_voidSetPinDirection		(u8 PortId,u8 PinId,u8 Direction){
	if(Direction==OUTPUT){
		switch(PortId){
			case DPORTA:set_bit(DDRA,PinId);break;
			case DPORTB:set_bit(DDRB,PinId);break;
			case DPORTC:set_bit(DDRC,PinId);break;
			case DPORTD:set_bit(DDRD,PinId);break;
			
		}
	}else if(Direction==INPUT){
		switch(PortId){
			case DPORTA:clr_bit(DDRA,PinId);break;
			case DPORTB:clr_bit(DDRB,PinId);break;
			case DPORTC:clr_bit(DDRC,PinId);break;
			case DPORTD:clr_bit(DDRD,PinId);break;
			
		}
	}
}

void	DIO_voidSetPinValue			(u8 PortId,u8 PinId,u8 Value){
	if(PortId< 4 &&PinId<8){
		if(Value==HIGH){
			switch(PortId){
			case DPORTA: set_bit(PORTA,PinId);break;
			case DPORTB: set_bit(PORTB,PinId);break;
			case DPORTC: set_bit(PORTC,PinId);break;
			case DPORTD: set_bit(PORTD,PinId);break;
			
		   }
		}
		else if(Value==LOW){
			switch(PortId){
			case DPORTA: clr_bit(PORTA,PinId);break;
			case DPORTB: clr_bit(PORTB,PinId);break;
			case DPORTC: clr_bit(PORTC,PinId);break;
			case DPORTD: clr_bit(PORTD,PinId);break;
			
		   }
		}
		else{}
	}
	else{}
}

u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId){
	u8 result=0;
	if(PortId<4&&PinId<8){
			switch(PortId){
			case DPORTA:result= GET_BIT(PINA,PinId);break;
			case DPORTB:result= GET_BIT(PINB,PinId);break;
			case DPORTC:result= GET_BIT(PINC,PinId);break;
			case DPORTD:result= GET_BIT(PIND,PinId);break;
			
		   }
		
	}
	else{}
	return result;
}


void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction){
	if(PortId<4){
		switch(PortId){
			case DPORTA:DDRA=Direction;break;
			case DPORTB:DDRB=Direction;break;
			case DPORTC:DDRC=Direction;break;
			case DPORTD:DDRD=Direction;break;
		}
	}
}

void	DIO_voidSetPortValue		(u8 PortId,u8 Value){
	if(PortId<4){
		switch(PortId){
			case DPORTA:PORTA=Value;break;
			case DPORTB:PORTB=Value;break;
			case DPORTC:PORTC=Value;break;
			case DPORTD:PORTD=Value;break;
		}
	}
	else{}
}
