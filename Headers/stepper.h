#ifndef _STEPPER_H_
#define _STEPPER_H_
#include "dio.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define STEPPER_CW  0 
#define STEPPER_CCW 1
#define STEPPER_FULL_STEP 0
#define STEPPER_HALF_STEP 1
void stepperInit();
void stepperRotate(u8 direction,u8 mode, u8 degree,u8 delay);
void stepperStep(u8 direction,u8 mode);
#endif