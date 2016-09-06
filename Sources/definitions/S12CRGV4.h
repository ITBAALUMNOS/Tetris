/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12CRGV4.h                                               	     */
/*                                                                           */
/* PURPOSE: Header File for S12 CRG		     					 		     */
/*                                                                           */
/* DESCRIPTION: Defines the CRG module register block as a           		 */
/* datastructure of type tCRG.                           					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB     									 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12CRGV4_H			/*prevent duplicated includes */
#define S12CRGV4_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif		   

typedef union uSYNR
{
  	tU08 byte;
  	struct
    {
    	tU08 syn	:6;		/*synthesizer bits, controls multiplication factor of PLL */
    	tU08		:2;		/*not used */
    }bit;
}tSYNR;

#define SYN0	0x01	/*bit masks	*/
#define SYN1	0x02
#define SYN2	0x04
#define SYN3	0x08
#define SYN4	0x10
#define SYN5	0x20

typedef union uREFDV
{
    tU08 byte;
  	struct
    {
    	tU08 refdv	:4;		/*allows finer granularity for pll ref freq	*/
    	tU08		:4;		/*not used */
    }bit;
}tREFDV;

#define REFDV0	0x01	/*bit masks	*/
#define REFDV1	0x02
#define REFDV2	0x04
#define REFDV3	0x08


typedef union uCTFLG		
{
  	tU08 byte;
  	struct
    {
    	tU08	:8;		/*not used */
    }bit;
}tCTFLG;

typedef union uCRGFLG
{
  	tU08 byte;
  	struct
    {
    	tU08 scm	:1;		/*self clock mode ststus (1: limp-home clock active) */
    	tU08 scmif	:1;		/*self clock mode interrupt flag */
		tU08 track	:1;		/*track status*/
    	tU08 lock	:1;		/*lock status */
    	tU08 lockif	:1;		/*lock interrupt flag */
    	tU08 lvrf	:1;		/*low voltage reset flag*/
		tU08 porf	:1;		/*power on reset flag */
		tU08 rtif	:1;		/*real time interrupt flag */
    }bit;
}tCRGFLG;

#define SCM		0x01	/*bit masks	*/
#define SCMIF	0x02
#define TRACK	0x04	
#define LOCK	0x08	
#define LOCKIF	0x10
#define LVRF	0x20	
#define PORF	0x40	
#define RTIF	0x80

typedef union uCRGINT
{
  	tU08 byte;
  	struct
    {
		tU08 		:1;		/*not used*/
    	tU08 scmie	:1;		/*self clock mode interrupt enable */
		tU08 		:2;		/*not used*/
    	tU08 lockie	:1;		/*lock interrupt enable */
    	tU08		:2;		/*not used */
		tU08 rtie	:1;		/*real time interrupt enable */
    }bit;
}tCRGINT;

#define SCMIE	0x02	/*bit masks	*/
#define LOCKIF	0x10	
#define RTIE	0x80

typedef union uCLKSEL
{
  	tU08 byte;
  	struct
    {
    	tU08 copwai	:1;		/*not used */
    	tU08 rtiwai	:1;		/*module clock select */
    	tU08 cwai	:1;		/*not used */
    	tU08 pllwai	:1;		/*bus clock select slow	*/
    	tU08 roawai	:1;		/*bus clock select pll */
    	tU08 syswai	:1;		/*system clock stoped in wait mode */
    	tU08 pstp	:1;		/*pseudo stop mode enable */
    	tU08 pllsel	:1;		/*pll select */
    }bit;
}tCLKSEL;

#define COPWAI	  0x01		/*bit masks */
#define RTIWAI	  0x02		
#define CWAI	  0x04		
#define PLLWAI	  0x08		
#define ROAWAI	  0x10		
#define SYSWAI	  0x20		
#define PSTP	  0x40		
#define PLLSEL	  0x80		

typedef union uPLLCTL
{
  	tU08 byte;
 	 struct
    {
    	tU08 scme	:1;		/*self clock mode enable */
		tU08 pce	:1;		/*pseudo stop COP enable */
    	tU08 pre	:1;		/*pseudo stop RTI enable */
    	tU08		:1;		/*not used */
    	tU08 acq	:1;		/*not in acquisition */
    	tU08 aut	:1;		/*automatic bandwidth control */
    	tU08 pllon	:1;		/*phase lock loop on */
    	tU08 cme	:1;		/*crystal monitor enable */
    }bit;
}tPLLCTL;

/****

The bitfield aut was used instead of auto, as auto is a C keyword and may be
problematic to some compilers.

****/

#define SCME	0x01	/*bit masks	*/
#define PCE		0x02
#define PRE		0x04
#define ACQ		0x10
#define AUT 	0x20
#define PLLON	0x40
#define CME		0x80

typedef union uRTICTL
{
  	tU08 byte;
  	struct
    {
    	tU08 rtr0	:1;		/*modulus counter select */
		tU08 rtr1	:1;		
    	tU08 rtr2	:1;		
    	tU08 rtr3	:1;		
    	tU08 rtr4	:1;		/*prescaler rate select */
    	tU08 rtr5	:1;		
    	tU08 rtr6	:1;		
    	tU08  		:1;		/*not used */
    }bit;
}tRTICTL;
  
#define RTR0	0x01	/*bit masks	*/
#define RTR1	0x02
#define RTR2	0x04
#define RTR3	0x08
#define RTR4	0x10
#define RTR5	0x20
#define RTR6	0x40

typedef union uCOPCTL
{			  
  	tU08 byte;
  	struct
    {
    	tU08 cr		:3;		/*cop timer rate select */
    	tU08		:3;		/*not used */
    	tU08 rsbck  :1;		/*cop and rti stop in active bdm */
    	tU08 wcop	:1;		/*window cop enable */
    }bit;
}tCOPCTL;

#define CR0		0x01	/*bit masks	*/
#define CR1		0x02
#define CR2		0x04
#define RSBCK   0x40
#define WCOP	0x80

typedef union uFORBYP		
{
  	tU08 byte;
  	struct
    {
    	tU08	:8;		/*not used */
    }bit;
}tFORBYP;

typedef union uCTCTL		
{
  	tU08 byte;
  	struct
    {
    	tU08	:8;		/*not used */
    }bit;
}tCTCTL;

typedef union uARMCOP		
{
  	tU08 byte;
  	struct
    {
    	tU08	:8;		/*not used */
    }bit;
}tARMCOP;

typedef struct				
{
  volatile  tSYNR	synr;	/*synthesizer register */
  volatile  tREFDV	refdv;	/*reference divider register */
  volatile  tCTFLG	ctflg;	/*clock generator test flags register	*/
  volatile  tCRGFLG	crgflg;	/*clock generator flags register */
  volatile  tCRGINT	crgint;	/*clock generator interrupt control register */
  volatile  tCLKSEL	clksel;	/*clock generator clock select register */
  volatile  tPLLCTL	pllctl;	/*pll control register */
  volatile  tRTICTL	rtictl;	/*rti control register */
  volatile  tCOPCTL	copctl;	/*cop control register */
  volatile  tFORBYP	forbyp; /*crg force and bypass test register */
  volatile  tCTCTL	ctctl;	/*crg test control register */
  volatile  tARMCOP	armcop;	/*cop arming register (to reset write $55:$AA) */
}tCRG;

#endif /*S12CRGV4_H */