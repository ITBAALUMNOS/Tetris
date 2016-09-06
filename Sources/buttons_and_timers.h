#ifndef BUTTONS_AND_TIMERS_H_
#define BUTTONS_AND_TIMERS_H_
#include "event_queue.h"
//This will take care of "hardware" events
//And register it into event queue as normal events

#define TOTAL_BUTTONS         8     //   TOTAL_BUTTONS <= 8, uses PORTB
#define TOTAL_TIMERS          8
#define INTERRUPT_PERIOD_MS   50    //IS EQUAL TO THE PERIOD OF THE INTERRUPT
                                    //DO NOT MODIFY (or modify interrupt period AND this value)

//Here we have some useful definitions
//Events enum. You may create custom events, starting enum from CUSTOM_EVENT_START
//These are events' ids
enum {BUTTON_PRESS,BUTTON_REPEAT,BUTTON_RELEASE,TIMER,CUSTOM_EVENT_START};
//Timer enum (event.data for TIMER event.id)
enum {TIMER_0,TIMER_1,TIMER_2,TIMER_3,TIMER_4,TIMER_5,TIMER_6,TIMER_7};
//Buttons enum. (event.data for BUTTON_* event.id)
enum {BUTTON_0,BUTTON_1,BUTTON_2,BUTTON_3,BUTTON_4,BUTTON_5,BUTTON_6,BUTTON_7};
//THESE ARE UP,DOWN,LEFT,RIGHT,UP_LEFT_BUTTON,UP_RIGHT_BUTTON,DOWN_LEFT_BUTTON, and DOWN_RIGHT_BUTTON respectively

//If you want to redefine this in order to use names that are more friendly
//we recommend that you do that in your main code, and not here
//example: #define JUMP_BUTTON BUTTON_3
//         #define MY_TIMER TIMER_0

//Init buttons and timers

//Note: do not give a time (ms) bigger than UCHAR_MAX*INTERRUPT_PERIOD_MS
//Given time will be set to i*INTERRUPT_PERIOD_MS where i is integer and
//i*INTERRUPT_PERIOD_MS <= ms and i*INTERRUPT_PERIOD_MS is maximum.
//Undefined behaviour if ms > UCHAR_MAX*INTERRUPT_PERIOD_MS
//If you five a time (ms) smaller than INTERRUPT_PERIOD_MS, timer will be disabled

void buttons_and_timers_init(void);                //Initialization
void set_button_repeat_period_ms(unsigned int ms); //Button repeat event period. 0 will disable this. default is 0
unsigned char is_button_down(unsigned char b);     //Is Button down?
void set_timer_period_ms(unsigned char t, unsigned int ms); //Set timer period. 0 will disable timer. default is 0
void reset_timer(unsigned char t);                 //Reset timer to 0

#endif //BUTTONS_AND_TIMERS_H_