#ifndef SERVO_H_
#define SERVO_H_ 
#include "dio.h"

#define Angle_0 500
#define Angle_90 1500
#define Angle_180 2500

#define PWM_Period 20000

void Servo_Init();
void Servo_SetAngle(u16 angle);
void Servo_MoveTo(u16 value);

#endif