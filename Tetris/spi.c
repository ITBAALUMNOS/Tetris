#include "spi.h"
//#include "mc9s12xdp512.h"

// Driver Init
void init_SPI(void)
{
	/*
  // LOAD Out  (latch for MAX7219)
	DDRA |= (1 << 0);
	PORTA |= (1 << 0);
  // Bus Clock 40MHz
  // set baud BusCLk / 40   1MHz  (MAX7219, up to 10MHz, it may be a good idea lo set it to a lower frequency)
	SPI0BR = ( 0b100 << SPI0BR_SPPR_BITNUM ) | ( 0b011 << SPI0BR_SPR_BITNUM );
  //latched on rising edge, data transferred msb first
	SPI0CR1=SPI0CR1_SPE_MASK | SPI0CR1_MSTR_MASK;
	SPI0CR2=0x00;  */
}

// Driver ISR, send word to MAX7219
void putwspi0 (unsigned int word)
{

//  char high,low,temp;
//	high = (char)(word >> 8);
//	low = (char)word;
//	//HC12 is BIG ENDIAN
//	PORTA &= ~(1 << 0);
//  while(!(SPI0SR & SPI0SR_SPTEF_MASK)); 	/* wait until write is permissible */
//  SPI0DR = high;             	            /* output HIGH BYTE to the SPI */
//  while(!(SPI0SR & SPI0SR_SPIF_MASK));  	/* wait until write operation is complete */
//  while(!(SPI0SR & SPI0SR_SPTEF_MASK)); 	/* wait until write is permissible */
//  SPI0DR = low;              	            /* output LOW BYTE to the SPI */
//  while(!(SPI0SR & SPI0SR_SPIF_MASK));  	/* wait until write operation is complete */
//  temp 	= SPI0DR;	                        /* clear the SPIF flag */
//	PORTA |= (1 << 0);
//	//Are these NOPS still necessary?
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
//	_asm NOP;
}
