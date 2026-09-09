/*
 * GccApplication27.c
 *
 * Created: 9/9/2026 9:56:32 PM
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"

int main(void)
{
	u8 received_data;


	set_bit(DDRA, PIN0);

	SPI_SlaveInit();

	while (1)
	{
		
		received_data = SPI_SlaveReceive();

		if (received_data == '1')
		{
			set_bit(PORTA, PIN0);  
		}
		else if (received_data == '0')
		{
			clr_bit(PORTA, PIN0); 
		}
	}

	return 0;
}
