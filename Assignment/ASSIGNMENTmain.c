/*
 * GccApplication9.c
 *
 * Created: 9/4/2026 12:03:45 AM
 * Author : dell
 */ 
#include <avr/io.h>
#include "ASS.h"
#include <util/delay.h>

#define F_CPU 1000000UL

void LCD_PrintNumber(u32 num)
{
	u8 str[10];
	s8 i = 0;

	if (num == 0)
	{
		LCD_sendChar('0');
		return;
	}

	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		LCD_sendChar(str[i]);
	}
}

int main(void)
{
	u8 key = 0xFF;
	u32 num1 = 0, num2 = 0, result = 0;
	u8 op = 0;

	keybad_init();
	LCD_init();

	while (1)
	{
		key = keybadGetKey();

		if (key != 0xFF)
		{
			if (key == 'C')
			{
				LCD_SendCommand(0x01);
				num1 = 0;
				num2 = 0;
				op = 0;
			}
			else if (key >= '0' && key <= '9')
			{
				LCD_sendChar(key);
				if (op == 0)
				{
					num1 = (num1 * 10) + (key - '0');
				}
				else
				{
					num2 = (num2 * 10) + (key - '0');
				}
			}
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				LCD_sendChar(key);
				op = key;
			}
			else if (key == '=')
			{
				LCD_sendChar('=');

				if (op == '+')      result = num1 + num2;
				else if (op == '-') result = num1 - num2;
				else if (op == '*') result = num1 * num2;
				else if (op == '/') result = (num2 != 0) ? (num1 / num2) : 0;

				LCD_PrintNumber(result); 
			}

			_delay_ms(250);
		}
	}
}

