#ifndef TIMER0_H
#define TIMER0_H
#include "dio.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void TIMER0_Init(void);
void TIMER0_SetDelay(u32 Delay);

void TIMER0_InitCTC();
void TIMER0_SetOCR0(u8 Value);
#endif