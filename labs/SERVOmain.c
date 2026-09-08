/*
 * GccApplication22.c
 *
 * Created: 9/8/2026 10:06:34 PM
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"

int main(void) {
	Servo_Init();
	TIMER0_Init();
	
	while(1) {
		for(int angle = 0; angle <= 180; angle += 2) {
			Servo_SetAngle(angle);
			TIMER0_SetDelay(20);
		}
		
		for(int angle = 180; angle >= 0; angle -= 2) {
			Servo_SetAngle(angle);
			TIMER0_SetDelay(20);
		}
	}
}

