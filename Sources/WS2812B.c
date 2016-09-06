#include "mc9s12xdp512.h"
#include "WS2812B.h"
#include <stdlib.h>
    
#define OCTIC 50            // 50ns (prescaler must be at 2)  
#define T1H   800/OCTIC     // 800ns  @ 50ns OCTic
#define T0H   400/OCTIC     // 400ns  @ 50ns OCTic
#define TRES  50000/OCTIC   // 50us @ 50ns OCTic

// Variables used by Driver                                     

static unsigned int  delta;
static unsigned char mask;

// ************* OJO **********
// OJO ByteCtr debe ser int no char pues el maximo es 32x8x3= 768 me ovide !!!
// Medir como impacta en los tiempos
  
//static unsigned char ByteCtr=2;   // How many bytes will be send to WS2812B
static unsigned int  ByteCtr=2;   // How many bytes will be send to WS2812B

static unsigned char *p2rgb = NULL;      // Poiner to data to be send over DIN pin (WS2812B) 


// Definitions for transposed display
                                             


//static unsigned char (*p2led)[RGB_COLS*sizeof(LEDSTR)]; 

//static unsigned char rgb_col=0;
//static unsigned char rgb_row=0;
    

// OC6  pin 17 H3   (Din WS2812B)
// OC7  pin 18 H3   (Scope Test Point)

// ======================================

void WS2812B_Set_Data_Length( unsigned int length ) {
 
 
        ByteCtr=length;    //
 
  
}

void WS2812B_Set_Data_pointer( unsigned char *data_ptr ) {
 
  // Not transposed
  p2rgb=data_ptr;    // 
                
  // For transposed                
///  p2led=(unsigned char (*)[RGB_COLS*sizeof(LEDSTR)])data_ptr;
 
  
}



void WS2812B_Send_data(void)  // Important we don't use any local variables for speed reasons

{
  if(p2rgb == NULL)
    return;   
 
  
   _asm sei;          // Disable Interrupts Critical timing starts here
  
// ====================================================

  TC7=TCNT+1000;   // lets syncronize OC7 & OC6 with TCNT 
  TC6=TC7;         // and Reset WS2812B (TRES = 50000/OCTIC=1000)
      
  TFLG1=0x80; //  Clr C7F
  TFLG1=0x40; //  Clr C6F
   
  
  while (!TFLG1_C7F); // Wait for Sync 
  while (!TFLG1_C6F);   
   
  // Reset flags
  
  TFLG1=0x80; //  Clr C7F
  TFLG1=0x40; //  Clr C6F
 
  
  TC7=TC7+1000;  // Add some time to carry out the next tasks 
  TC6=TC6+1000;  // before next OC takes place
     
// **********************************************     
// DIN signal of WS2812B is generated at OC6 pin 
   
// OC7 Timer generates the signal period (Tbit)
// OC6 Timer generates the signal pulse width 
// 0.4us for 0 and 0.8us for 1

// At OC7 compare the following takes place:
 
// OC7 sets OC6 at 1
 
                          

// set up OC7 D and M to control OC6


    OC7M_OC7M6=1;          // OC7 controls OC6 pin 
    OC7D=0x40;             // When OC7 is reached OC6 pin goes HI
        
        
    mask=0x80;             // Init walking '1'
 
 
   // Bit value to pulse width conversion
   
    if((*p2rgb)&mask)      // Setup first Bit
          delta=T1H;
    else
          delta=T0H;
    

while (ByteCtr)
{

   
    while (!TFLG1_C7F);  // Sync with start of period
  
  // WARNING: Critical timing Don't put any code here

//=========== Set bit width ================================================
     TC6=TC7+delta;   // set bit width (T1H,T0H) value on OC6
    
//=========== Set bit period ==========================================================   

//   TC7=TC7+25;      // 1.25us   (nominal period) 

// Add some extra time to the nominal period (1.25us)
// in order to have enough time set up next iteration.
// Under no circumstances the total perios should exceed 5us
// otherwise a reset condition will be detected by the WS2812B

// 1.25us(25OC @50ns each) + 2us(40OC @50ns each) = 3.25us < 5us

// Time in nseg
#define TNOMINAL 1250     //1.25 us 
#define TSPARE   2000     //2 us
#define TBIT  TNOMINAL/OCTIC + TSPARE/OCTIC  // must be less than 5 us
 

   TC7=TC7+TBIT;     // Set bit period


//=====================================================================================

// Reset OC flags           

     TFLG1=0x80|0x40; //  Clr C7F and C6F

// Set up next bit     
     
     mask>>=1;        // Next bit

     if(mask){        // Are more bits left ?
     
     // Bit value to pulse width conversion
              
          if((*p2rgb)&mask) 
              delta=T1H;
          else
              delta=T0H;
     }
     
     else{                  // Start a new Byte     
      
                      
          p2rgb++;          // Next byte
          ByteCtr--;    
          mask=0x80;        // Reset mask
          
       // Setup first Bit

          if((*p2rgb)&mask)     
              delta=T1H;
          else
              delta=T0H;
          
       
       
     } // end of if


// ========================================================== //

        // The following code is for Debug 
        // It shows how much time we have free 
        // before next bit must be sent
        // Free time is t2-t1
        // t1: rising edge of PORTA pin0
        // t2: next edge on OC7
        // Actually each bit is sent every 3.25us (Tbit)
        // Tbit= 1.25us (TNOMINAL) + 2us (SPARE)
        // Tfree= Tbit - FreeTime(measured)

/* 
          PORTA|=0x01;
          _asm nop;   
          _asm nop; 
          PORTA&=0xFE;
  
*/
          
// measured values on actual code
// measured from start of period to Port A rising edge:
// 
// 1.38 us when byte is being sent  => Tfree=1.87 us
// 1.83 us when next byte is loaded => Tfree=1.42 us        
// =========================================================== //
          


       
   } //End of while
   
     OC7D=0x00;   // When OC7 is reached OC6 pin goes LO
     _asm cli;    // Reenable Interrupts Critical section has ended     
     
   
   
}  // End of WS2812B_Send_data






//***************************************************************
//                            WS2812B_Init
//===============================================================
// WS2812B_Init initializes OC Hardware for WS2812B Led Controller 
// OC6 drives the DIN pin on WS2812B. Init_display sets DIN to 0
// and OC7 to toggle mode after the call   
// How it works :
// OC7 controls OC6 setting it HI at the start of each period
// OC6 returns to LO after TH1/TH0. At the end of the period OC7 
// returns OC6 to HI.
//
// |--------|                        |------
// |  TH1/0 |                        |
// |        |------------------------|
// OC6 --> TH1/0
// OC7 --> Period
//
// 
//===============================================================


void WS2812B_Init(void)

{

  // Set TCNT prescaler     
 
  TSCR2 = (TSCR2 & 0xF8) | 0x01;    // Prescaler en 2, cuenta cada 2/40MHz = 50ns
  TSCR1 |= TSCR1_TEN_MASK;          // Habilita el timer para el IOC

  // Set Timer 6 and 7 in OC mode
  TIOS_IOS7=1;    
  TIOS_IOS6=1;
 
  // Toggle on OC7 (For debug)
  TCTL1_OL7 = 1;   
  TCTL1_OM7 = 0;

  // Set OC6 for Low on succesfull OC
  
  TCTL1_OL6 =0;    // When OC6 is reached OC6 pin (DIN) goes LO 
  TCTL1_OM6 =1;

  // Force OC to set previous settings
  
  CFORC_FOC6=1;    
  CFORC_FOC7=1; 
  
}