 #ifndef SPI_H
 #define SPI_H

 void init_SPI(void);               //Initializes spi for MAX7219
 void putwspi0(unsigned int word);  //Sends word to MAX7219
 
 #endif