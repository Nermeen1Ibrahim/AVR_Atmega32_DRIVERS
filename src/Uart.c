#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Uart.h"

void UART_voidInit(void)
{
	// Baud Rate = 9600 at F_CPU = 8MHz
	UBRRH = 0;
	UBRRL = 51;

	// Enable Receiver and Transmitter
	set_bit(UCSRB, RXEN);
	set_bit(UCSRB, TXEN);

	//Frame: 8 Data bits, 1 Stop bit, No Parity

	set_bit(UCSRC, URSEL);

	clr_bit(UCSRC, UMSEL);

	clr_bit(UCSRC, UPM1);
	clr_bit(UCSRC, UPM0);

	clr_bit(UCSRC, USBS);

	set_bit(UCSRC, UCSZ1);
	set_bit(UCSRC, UCSZ0);

	clr_bit(UCSRB, UCSZ2);
}

void UART_voidSendByte(u8 Data)
{
	// Wait until transmit buffer is empty
	while (GET_BIT(UCSRA, UDRE) == 0);

	UDR =Data;
}

u8 UART_u8ReceiveByte(void)
{
	// Wait until data is received
	while (GET_BIT(UCSRA, RXC) == 0);

	return UDR;
}