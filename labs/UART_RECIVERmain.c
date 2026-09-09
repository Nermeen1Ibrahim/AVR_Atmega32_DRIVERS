/*
 * GccApplication25.c
 *
 * Created: 9/9/2026 7:49:16 PM
 * Author : dell
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Uart.h"

int main(void)
{
	u8 ReceivedData;

	UART_voidInit();

	while (1)
	{
		ReceivedData = UART_u8ReceiveByte();

		switch (ReceivedData)
		{
			case '1':
			clr_bit(PORTA,PIN1);
			toggle_bit(PORTA, PIN0);
			break;

			case '2':
			clr_bit(PORTA,PIN0);
			toggle_bit(PORTA, PIN1);
			break;


			default:
			break;
		}
	}

	return 0;
}

