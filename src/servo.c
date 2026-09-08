#include "servo.h"
#include <avr/io.h>
 
 void Servo_Init(){
	 DIO_voidSetPinDirection(DPORTD,PIN5,OUTPUT);
	 TCCR1A=0b10000010;
	 TCCR1B=0b00011010;
	 
	 ICR1=PWM_Period;
	 OCR1A=Angle_0;
 }
 
 void Servo_SetAngle(u16 angle){
	 u16 pulse_width;
	 pulse_width=500+(angle*2000)/180;
	 if(pulse_width<500){
		 pulse_width=500;
	 }
	 if(pulse_width>2500){
		 pulse_width=2500;
	 }
	 OCR1A=pulse_width;
 }
 
 void Servo_MoveTo(u16 value){
	 OCR1A=value;
 }