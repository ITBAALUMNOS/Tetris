/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12TIM16B4CV1.h                                        	 	 */
/*                                                                           */
/* PURPOSE: Header File for S12 TIM_16B4C     						 	     */
/*                                                                           */
/* DESCRIPTION: Defines the TIM_16B4C module register block as a       		 */
/* datastructure of type tTIM.         	                 					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin, TX	   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12TIM16B4CV1_H			/*prevent duplicated includes */
#define S12TIM16B4CV1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uTIOS
  {
  tU08	byte;	
  struct
    {
    tU08 		:4;		/*i/p capture(0) or o/p compare(1) select */
    tU08 ios4	:1;
    tU08 ios5	:1;
    tU08 ios6	:1;
    tU08 ios7	:1;
    }bit;
  }tTIOS;

#define IOS4 	0x10
#define IOS5 	0x20
#define IOS6 	0x40
#define IOS7 	0x80

typedef union uCFORC
  {
  tU08	byte;	
  struct
    {
    tU08 		:4;		/*force output compare, no interrupt flag */
    tU08 foc4	:1;
    tU08 foc5	:1;
    tU08 foc6	:1;
    tU08 foc7	:1;
    }bit;
  }tCFORC;

#define FOC4 	0x10
#define FOC5 	0x20
#define FOC6 	0x40
#define FOC7 	0x80

typedef union uOC7M
  {
  tU08	byte;	
  struct
    {
    tU08 		:4;		/*output compare 7 bit mask */
    tU08 oc7m4	:1;
    tU08 oc7m5	:1;
    tU08 oc7m6	:1;
    tU08 oc7m7	:1;
    }bit;
  }tOC7M;

#define OC7M4	0x10
#define OC7M5	0x20
#define OC7M6	0x40
#define OC7M7	0x80

typedef union uOC7D
  {
  tU08	byte;	
  struct
    {
    tU08		:4;
    tU08 oc7d4	:1;
    tU08 oc7d5	:1;
    tU08 oc7d6	:1;
    tU08 oc7d7	:1;
    }bit;
  }tOC7D;

#define OC7D4	0x10
#define OC7D5	0x20
#define OC7D6	0x40
#define OC7D7	0x80

typedef union uTCNT
  {
  tU16	word;
  struct
    {
    tU08 tcnth;
    tU08 tcntl;
    }byte;
  }tTCNT;

typedef union uTSCR1
  {
  tU08	byte;
  struct
    {
    tU08		:4;		/*not used */
    tU08 tffca	:1;		/*timer fast flag clear all */
    tU08 tsfrz	:1;		/*timer stops in background mode (MAKO MODIFICATION) */
    tU08 tswai	:1;		/*timer stops in wait mode */
    tU08 ten	:1;		/*timer enable */
    }bit;
  }tTSCR1;

#define TFFCA	0x10	/*bit masks */
#define TSFRZ	0x20
#define TSWAI	0x40
#define TEN	    0x80

typedef union uTTOV		/*TOVx toggles output compare pin on overflow */
  {
  tU08	byte;
  struct
    {
    tU08 	 	:4;		
    tU08 tov4 	:1;		 
    tU08 tov5 	:1;		 
    tU08 tov6	:1;		 
    tU08 tov7 	:1;
    }bit;
  }tTTOV;

#define TOV4	0x10
#define TOV5	0x20
#define TOV6	0x40
#define TOV7	0x80

typedef union uTCTL1
  {
  tU08	byte;
  struct
    {
    tU08 ol4 	:1;		/*output compare pin action */
    tU08 om4 	:1;
    tU08 ol5 	:1;		/*OMx:OLx -> action */
    tU08 om5 	:1;		/* 0 : 0  -> disconnected from pin */
    tU08 ol6 	:1;		/* 0 : 1  -> toggle OCx pin */
    tU08 om6 	:1;		/* 1 : 0  -> clear OCx pin (0) */
    tU08 ol7 	:1;		/* 1 : 1  -> set OCx pin (1) */
    tU08 om7 	:1;
    }bit;
  }tTCTL1;

#define OL4		0x01	/*bit masks */
#define OM4		0x02
#define OL5		0x04
#define OM5		0x08
#define OL6		0x10
#define OM6		0x20
#define OL7		0x40
#define OM7		0x80

typedef union uTCTL3
  {
  tU08	byte;
  struct
    {
    tU08 edg4	:2;		/*input capture configuration */
    
    tU08 edg5	:2;		/*EDGxB:EDGxA -> configuration */
    					/*  0  :  0   -> capture disabled */
    tU08 edg6	:2;		/*  0  :  1   -> rising edge only */
    					/*  1  :  0   -> falling edge only */
    tU08 edg7	:2;		/*  1  :  1   -> any edge */
    }bit;
  }tTCTL3;

#define EDG4A	0x01	/*bit masks */
#define EDG4B	0x02
#define EDG4	0x03
#define EDG5A	0x04
#define EDG5B	0x08
#define EDG5	0x0C
#define EDG6A	0x10
#define EDG6B	0x20
#define EDG6	0x30
#define EDG7A	0x40
#define EDG7B	0x80
#define EDG7	0xC0

typedef union uTIE		/*On HC12 was TMSK1 */
  {
  tU08	byte;
  struct
    {
    tU08 		:4;		/*capture/compare interrupt enable */
    tU08 c4i	:1;
    tU08 c5i	:1;
    tU08 c6i	:1;
    tU08 c7i	:1;
    }bit;
  }tTIE;

#define C4I 	0x10
#define C5I 	0x20
#define C6I 	0x40
#define C7I 	0x80

typedef union uTSCR2		/*On HC12 was TMSK2 */
  {
  tU08	byte;
  struct
    {
    tU08 pr		:3;		/*timer prescaler select */
    					/*prescale settings : 1,2,4,8,16,32 */ 
    tU08 tcre	:1;		/*timer counter reset enable (OC7) */ 
    tU08		:3;		/*not used */
    tU08 toi	:1;		/*timer overflow interrupt enable */ 
    }bit;
  }tTSCR2;

#define PR0		0x01	/*bit masks */
#define PR1		0x02
#define PR2		0x04
#define PR		0x07
#define TCRE	0x08
#define TOI		0x80

typedef union uTFLG1
  {
  tU08	byte;
  struct
    {
    tU08 		:4;		/*capture/compare interrupt flag */
    tU08 c4f	:1;
    tU08 c5f	:1;
    tU08 c6f	:1;
    tU08 c7f	:1;
    }bit;
  }tTFLG1;

#define C4F 	0x10
#define C5F 	0x20
#define C6F 	0x40
#define C7F 	0x80

typedef union uTFLG2
  {
  tU08	byte;
  struct
    {
    tU08		:7;		/*not used */
    tU08 tof	:1;		/*timer overflow interrupt flag */
    }bit;
  }tTFLG2;

#define TOF		0x80	/*bit masks */

typedef union uPACTL
  {
  tU08	byte;
  struct
    {
    tU08 pai	:1;		/*pulse acc. input interrupt enable */
    tU08 paovi	:1;		/*pulse acc. overflow interrupt enable */
    tU08 clk	:2;		/*clock source select */
    tU08 pedge	:1;		/*pulse acc. edge control */
    tU08 pamod	:1;		/*pulse acc. mode */
    tU08 paen	:1;		/*pulse acc. enable */
    tU08		:1;		/*not used */
    }bit;
  }tPACTL;

#define PAI	    0x01	/*bit masks */
#define PAOVI	0x02
#define CLK0	0x04
#define CLK1	0x08
#define CLK		0x0C
#define PEDGE	0x10
#define PAMOD	0x20
#define PAEN	0x40

typedef union uPAFLG
  {
  tU08	byte;
  struct
    {
    tU08 paif	:1;		/*pulse acc. input flag */
    tU08 paovf	:1;		/*pulse acc. overflow flag */
    tU08	    :6;		/*not used */
    }bit;
  }tPAFLG;

#define PAIF	0x01
#define PAOVF	0x02

typedef union uPACNT	
  {
  tU16	word;			/*used if 16-bit pulse acc. used */
  struct			    /*MUST use single word access in 16-bit mode */
    {
    tU08 pacnth;			/*MAKO MODIFICATION*/
    tU08 pacntl;			
    }byte;
  }tPACNT;

typedef union uTIMTST
  {
  tU08	byte;
  struct
    {
    tU08 pcbyp	:1;		/*pulse acc. divider chain bypass */
    tU08 tcbyp	:1;		/*timer divider chain bypass */
    tU08	    :6;		/*not used */
    }bit;
  }tTIMTST;

#define PCBYP	0x01	/*bit masks */
#define TCBYP	0x02

typedef struct				/*enhanced timer  */
  {
  volatile tTIOS	tios;	/*timer input capture/output compare select */
  volatile tCFORC	cforc;	/*timer compare force register */
  volatile tOC7M	oc7m;	/*output compare 7 mask register */
  volatile tOC7D	oc7d;	/*output compare 7 data register */
  volatile tTCNT	tcnt;	/*timer count register */
  volatile tTSCR1	tscr1;	/*timer system control register 1 */
  volatile tTTOV	ttov;	/*timer toggle on overflow register */
  volatile tTCTL1	tctl1;	/*timer control register 1 */
           tU08 	rsv;	/*reserved (maintaining memory map) */
  volatile tTCTL3	tctl3;	/*timer control register 3 */
           tU08 	rsv2;	/*reserved (maintaining memory map) */
  volatile tTIE		tie;	/*timer interrupt mask 1 */
  volatile tTSCR2	tscr2;	/*timer system control register 2 */
  volatile tTFLG1	tflg1;	/*timer interrupt flag 1 */
  volatile tTFLG2	tflg2;	/*timer interrupt flag 2 */
  		   tU16	 	rsv3[4];/*reserved (maintaining memory map) */
  volatile tREG16	tc[4];	/*timer input capture/output compare registers */
  volatile tPACTL	pactl;	/*pulse accumulator control register */
  volatile tPAFLG	paflg;  /*pulse accumulator flag register */
  volatile tPACNT	pacnt;	/*pulse accumulator count register */
  		   tU08		rsv4[8];/*reserved (maintaining memory map) */
  volatile tTIMTST	timtst;	/*timer test register */
           tU08		rsv5[2];/*reserved (maintaining memory map) */
   }tTIMER;

#endif /*S12TIM16B4CV1_H*/