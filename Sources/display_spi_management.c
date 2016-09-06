#include "display_spi_management.h"
#include "spi.h"

//WE STILL HAVE WORK TO DO IN HERE

/*	This functions sends a number(max 8 digits) via spi to a display using a MAX7219 integrated display driver.
	ADRESSES:
*	0x01 address firset 7 segment display
	0x02 address second 7 segment display
	.....
	0x07 address seventh 7 segment display
	
	DATA:
	0X01 corresponds to a number 1
	0X02 corresponds to a number 2
	....
	0x09 corresponds to a number 9
	
*	(ADDRESS << 8) | Data sets a number in xxx 7segment display
*/

void send_number_display(unsigned long int display_score)
{
	unsigned char current_segment = 0x01; //first segments
	unsigned int two_bytes_send = 0x00;
	if(display_score > 99999999)
	  display_score = 99999999;
	for(current_segment = 1 ; current_segment <= MAX_DIGITS_SHOW ; current_segment++ )
	{
		two_bytes_send = display_score%10; //DATA HAS BEEN SET 
		display_score /= 10;
		two_bytes_send |= (current_segment << 8); // Result will be (address <<8 )| Data  
		putwspi0(two_bytes_send);
		putwspi0(two_bytes_send);
		//send the fucking shit
	}
}

/*
	This function configures a max7219 via spi to be used to manage an 8 digit
	7 segment display. 
*/
void configure_spi_max7219_display(void)
{
	init_SPI();

	putwspi0(INTENSITY_ADDRESS | MAX_INTENSITY); //Max intensity
	putwspi0(TEST_MODE_ADDRESS | NO_TEST_MODE); //TEST MODE off
	putwspi0(0x0BFF); //Scan all
	putwspi0(DECODE_ADDRESS | DECODE_MODE_ALL_DIGITS); //Decode
  	putwspi0(0x0C01); //Turn on
	//send via spi

}