#ifndef LEDDISPLAY_H_
#define LEDDISPLAY_H_
//These implements a logical display

//Put here the size of your display
#define DISPLAY_WIDTH   8
#define DISPLAY_HEIGHT 32

//Compiler alignment must be 1 byte
typedef struct
{
        unsigned char g;
        unsigned char r;
        unsigned char b;
}color;
//Initializes display
void LEDdisplay_init(void);
//Returns color struct with given info
color LEDdisplay_map_rgb(unsigned char r, unsigned char g, unsigned char b);
//Sets display pixel
void LEDdisplay_set_pixel(unsigned char x, unsigned char y, color c);  
//Returns display pixel
color LEDdisplay_get_pixel(unsigned char x, unsigned char y);
//Clear display to color
void LEDdisplay_clear_to_color(color c);
//Shows data in display  
void LEDdisplay_update(void); 

#endif //LEDDISPLAY_H_