#ifndef WS2812B_H
#define WS2812B_H

//Always call set data length and set data pointer before each call to send data
void WS2812B_Set_Data_Length( unsigned int length );
void WS2812B_Set_Data_pointer( unsigned char *data_ptr );
void WS2812B_Send_data(void);
void WS2812B_Init(void);

#endif