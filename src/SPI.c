#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"

void SPI_MasterInit(void)
{
    set_bit(DDRB, PB4);  // SS
    set_bit(DDRB, PB5);  // MOSI
    set_bit(DDRB, PB7);  // SCK
    
    clr_bit(DDRB, PB6);  // MISO

    set_bit(SPCR, SPE);
    set_bit(SPCR, MSTR);
    set_bit(SPCR, SPR0);
}


void SPI_SlaveInit(void)
{
    
    set_bit(DDRB, PB6);  // MISO
    
    clr_bit(DDRB, PB5);  // MOSI
    clr_bit(DDRB, PB7);  // SCK
    clr_bit(DDRB, PB4);  // SS

    set_bit(SPCR, SPE);
}


void SPI_MasterTransmit(u8 data)
{
    clr_bit(PORTB, PB4);

    SPDR = data;

    while (!GET_BIT(SPSR, SPIF));

    set_bit(PORTB, PB4);
}

u8 SPI_SlaveReceive(void)
{
    while (!GET_BIT(SPSR, SPIF));

    return SPDR;
}