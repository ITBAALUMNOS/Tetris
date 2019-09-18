#ifndef SPI_DISPLAY_H
#define SPI_DISPLAY_H

//WE STILL HAVE WORK TO DO IN HERE

#define SHUTDOWN_REGISTRY 		0x0C00
#define NORMAL_MODE				0x0001

#define DECODE_ADDRESS 			0x0900
#define DECODE_MODE_ALL_DIGITS	0x00FF

#define TEST_MODE_ADDRESS 		0x0F00
#define NO_TEST_MODE  			0x0000

#define INTENSITY_ADDRESS 		0x0A00
#define MIN_INTENSITY			0x0001
#define MID_INTENSITY			0x0007
#define MAX_INTENSITY			0x000F

#define DIGIT_BLANK      		0x000F

#define MAX_DIGITS_SHOW				8

void send_number_display(unsigned long int display_score);
void configure_spi_max7219_display(void);

#endif