
#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dio.h"
#include "stepper.h"

u8 full_steps[4]= {
	0b00000001,0b00000010,0b00000100,0b00001000
};
u8 half_steps[8]={0b00001001,0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000};
s8 step_index = 0;

void stepperInit(void) {
	
	DIO_voidSetPinDirection(DPORTC, PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN2,OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN3,OUTPUT);
	
	DIO_voidSetPinValue(DPORTC, PIN0,LOW);
	DIO_voidSetPinValue(DPORTC, PIN1,LOW);
	DIO_voidSetPinValue(DPORTC, PIN2,LOW);
	DIO_voidSetPinValue(DPORTC, PIN3,LOW);
}

void stepperStep(u8 direction,u8 mode) {
	u8 current_step=0;
	if(mode==STEPPER_FULL_STEP){
		if (direction == STEPPER_CW) {
			step_index++;
			if (step_index > 3) {
				step_index = 0;
			}
			} else {
			step_index--;
			if (step_index < 0) {
				step_index = 3;
			}
		}
		current_step=full_steps[step_index];
	}
	else if(mode==STEPPER_HALF_STEP){
		if (direction == STEPPER_CW) {
			step_index++;
			if (step_index > 7) {
				step_index = 0;
			}
			} else {
			step_index--;
			if (step_index < 0) {
				step_index = 7;
			}
		}
		current_step=half_steps[step_index];
	}
	DIO_voidSetPinValue(DPORTC, PIN0,  GET_BIT(current_step,0));
	DIO_voidSetPinValue(DPORTC, PIN1, GET_BIT(current_step,1));
	DIO_voidSetPinValue(DPORTC, PIN2, GET_BIT(current_step,2));
	DIO_voidSetPinValue(DPORTC, PIN3, GET_BIT(current_step,3));
}

void stepperRotate(u8 direction,u8 mode, u8 degree, u8 delay) {
	u16 total_steps = 0;
	if(mode==STEPPER_FULL_STEP){
		total_steps=((u16)degree * 200) / 360;
	}
	else{
		total_steps=((u16)degree * 400) / 360;
	}
	for (u16 i = 0; i < total_steps; i++) {
		stepperStep(direction,mode);

		for (u8 d = 0; d < delay; d++) {
			_delay_ms(1);
		}
	}
}