#include "spi.h"
#include <avr/io.h>

#define DDR_SPI DDRB
#define DD_SPIPORT PORTB
#define DD_MISO 4
#define DD_MOSI 3
#define DD_SCK 5
#define DD_SS 2

// Driver Init
void init_SPI(void)
{
	// Set MOSI, SS and SCK output, all others inputs
	DDR_SPI = 1 << DD_MOSI | 1 << DD_SS | 1 << DD_SCK;
	//Enable SPI, Master, set clock rate fck/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

// Driver ISR, send word to MAX7219
void putwspi0 (unsigned int word)
{

	char high,low;
	high = (char)(word >> 8);
	low = (char)word;
	//SS
	DD_SPIPORT &= ~(1 << DD_SS);
	//Output High Byte
	SPDR = high;
	//Wail until write is finished
	while(!(SPSR & (1<<SPIF)));
	//Output Low Byte
	SPDR = low;
	//Wail until write is finished
	while(!(SPSR & (1<<SPIF)));
	//SS
	DD_SPIPORT |= (1 << DD_SS);
}
