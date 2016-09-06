#include "LEDdisplay.h"
#include "WS2812B.h"
#include <stdlib.h>

//This will be initialized in zero!
static color display_raw_data[DISPLAY_HEIGHT][DISPLAY_WIDTH];

// Display initialization
void LEDdisplay_init()
{
    WS2812B_Init(); //Initialize real display
}

static color* get_pointer_to_pixel(unsigned char x, unsigned char y) 
{
    //ZIG-ZAG display!!
    color* return_value = NULL;
    if((x < DISPLAY_WIDTH) && (y < DISPLAY_HEIGHT))
    {   
        if(y & 1)
            return_value = &display_raw_data[DISPLAY_HEIGHT-1-y][x];
        else
            return_value = &display_raw_data[DISPLAY_HEIGHT-1-y][DISPLAY_WIDTH-1-x];   
    }
    return return_value;
}

//This is just an auxiliar function
color LEDdisplay_map_rgb(unsigned char r, unsigned char g, unsigned char b)
{
    color c;
    c.r = r;  c.g = g; c.b = b;
    return c;
}
         
//Set display pixel
void LEDdisplay_set_pixel(unsigned char x, unsigned char y, color c) 
{
    color* pixel = get_pointer_to_pixel(x,y);
    if(pixel != NULL)
        (*pixel) = c;
}

//Get display pixel
color LEDdisplay_get_pixel(unsigned char x, unsigned char y)
{
      color* pixel = get_pointer_to_pixel(x,y);
      if(pixel != NULL)
          return *pixel;
      return LEDdisplay_map_rgb(0,0,0);
}

//Clear display to color
void LEDdisplay_clear_to_color(color c)
{
    //Note that this does not use get_pointer_to_pixel function
    unsigned char x,y;
    for(y = 0 ; y < DISPLAY_HEIGHT ; y++)
        for(x = 0 ; x < DISPLAY_WIDTH ; x++)
            display_raw_data[y][x] = c;
}

void LEDdisplay_update(void)
{
     //IMPORTANT!!!! Always set display pointer and display length!!
     WS2812B_Set_Data_pointer((unsigned char*)display_raw_data);
     WS2812B_Set_Data_Length(DISPLAY_WIDTH*DISPLAY_HEIGHT*sizeof(color));
     WS2812B_Send_data(); 
}