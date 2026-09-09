/*
 * GccApplication26.c
 *
 * Created: 9/9/2026 9:51:21 PM
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"

int main(void)
{
	SPI_MasterInit();

	while (1)
	{
		
		SPI_MasterTransmit('1');
		_delay_ms(1000);

		SPI_MasterTransmit('0');
		_delay_ms(1000);
	}

	return 0;
}

