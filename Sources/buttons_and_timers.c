#include "buttons_and_timers.h"
#include "mc9s12xdp512.h"

//Function prototypes for pseudoFSM
static void button_press(unsigned char b);
static void button_release(unsigned char b);
static void button_repeat(unsigned char b);
static void button_do_nothing(unsigned char b);

static int button_repeat_period = 0; //Initialized in 0

//Button FSM
static void (* const  button_fsm[2][2])(unsigned char) = 
{
                    //BUTTON_UP     //BUTTON_DOWN 
/*WAS UP*/          {button_do_nothing,button_press}, 
/*WAS DOWN*/        {button_release,button_repeat}
}; 

static unsigned char button_state;                              //Initialized in 0
static unsigned char button_repeat_count[TOTAL_BUTTONS];        //Initialized in 0
static unsigned char timer_count[TOTAL_TIMERS];                 //Initialized in 0
static unsigned char timer_compare[TOTAL_TIMERS];               //Initialized in 0


void buttons_and_timers_init() 
{
    DDRB = 0x00;  //PORTB all input. Used for buttons
    // MC9S12XDP512 Data Sheet, Rev. 2.15 page 103
    // A write to the RTICTL register restarts the RTI time-out period. 
    //RTICTL = 0x77 | RTICTL_RTDEC_MASK;    // Decimal divider (16MHz / 1.6E6) = 100mseg
    RTICTL = 0x73 | RTICTL_RTDEC_MASK;      // Decimal divider (16MHz / 800E3) = 50mseg
    CRGFLG = CRGFLG_RTIF_MASK;              // Clear RTI Inerrupt mask
   
    CRGINT |= CRGINT_RTIE_MASK;             // Enable RTI Interrupt 
    _asm cli;                               // Enable interrupts
}

unsigned char is_button_down(unsigned char b)
{
    return button_state & (1 << b);
}

void set_button_repeat_period_ms(unsigned int ms)           //0 will disable repeat event
{
         unsigned char b;
         _asm sei;
         button_repeat_period = (unsigned char) (ms/INTERRUPT_PERIOD_MS);
         for(b = 0 ; b < TOTAL_BUTTONS ; b++)
                   button_repeat_count[b] = 0;
         _asm cli;
}

void set_timer_period_ms(unsigned char t, unsigned int ms)    //0 will disable timer
{
        _asm sei;
        timer_compare[t] = (unsigned char) (ms/INTERRUPT_PERIOD_MS);
        timer_count[t] = 0;
        _asm cli;
}

void reset_timer(unsigned char t) 
{
        timer_count[t] = 0;
}

//Note that if these functions cannot add an event to the queue
//It will be postponed INTERRUPT_PERIOD_MS (if event condition is still met)
//This guarantees that, for example, a repeat event cannot be generated
//if corresponding button down event was not added to queue
//Or that we won't have two button press events without a button release in the middle 

static void button_press(unsigned char b)
{
        EVENT_T ev;
        ev.id = BUTTON_PRESS;
        ev.data = b;
        button_repeat_count[b] = 0;
        if(register_event_in_queue(&ev) == SUCCESS)
                button_state |= (1 << b); 
}

static void button_release(unsigned char b)
{
        EVENT_T ev;
        ev.id = BUTTON_RELEASE;
        ev.data = b;
        if(register_event_in_queue(&ev) == SUCCESS)
                button_state &= ~(1 << b); 
}

static void button_repeat(unsigned char b)
{
        if(button_repeat_period != 0 && ++button_repeat_count[b] == button_repeat_period) 
        {
             EVENT_T ev;
             ev.id = BUTTON_REPEAT;
             ev.data = b;
             if(register_event_in_queue(&ev) == SUCCESS)
                    button_repeat_count[b] = 0;
             else
                 button_repeat_count[b]--;
        }
}

#pragma MESSAGE DISABLE C5703 /*: Parameter declared but not referenced */
static void button_do_nothing(unsigned char b){}
#pragma MESSAGE WARNING C5703 /*: Parameter declared but not referenced */

static void tick_timer(unsigned char t)
{
        if(timer_compare[t] != 0 && ++timer_count[t] == timer_compare[t])
        {
             EVENT_T ev;
             ev.id = TIMER;
             ev.data = t;
             if(register_event_in_queue(&ev) == SUCCESS)
                    timer_count[t] = 0;
             else
                 timer_count[t]--;  //Try not to lose event by undoing last tick!
        }
}

void interrupt ISR_rti(void) 
{       
        unsigned char i,j;
        
        CRGFLG = CRGFLG_RTIF_MASK;  //Clear RTI interrupt flag
        
        //Update buttons
        for(i = 0, j = 1; i < TOTAL_BUTTONS ; i++, j<<=1)
                button_fsm[button_state & j ? 1 : 0][(~PORTB) & j ? 1 : 0](i);
        
        //Update timers
        for(i = 0 ; i < TOTAL_TIMERS ; i++)
                tick_timer(i);           
}

