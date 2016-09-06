/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12LCD32F4BV1.h                                      	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 LCD 							 		     */
/*                                                                           */
/* DESCRIPTION: Defines the LCD module register block as a          		 */
/* datastructure of type tLCD.                          					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin, TX	   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12LCD32F4BV1_H			/*prevent duplicated includes */
#define S12LCD32F4BV1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uLCDCR0
  {
  tU08	byte;	
  struct
    {
    tU08 duty	:2;		
    tU08 bias	:1;
    tU08 lclk	:3;
    tU08 		:1;		/*reserved bit space*/
    tU08 lcden	:1;
    }bit;
  }tLCDCR0;

#define DUTY0	0x01	/*bit masks */
#define DUTY1 	0x02
#define BIAS	0x04
#define LCLK0 	0x08
#define LCLK1 	0x10
#define LCLK2 	0x20
#define LCDEN 	0x80

typedef union uLCDCR1
  {
  tU08	byte;	
  struct
    {
    tU08 lcdrpstp	:1;		
    tU08 lcdswai	:1;    
    tU08 			:6;		/*reserved bit space*/
    }bit;
  }tLCDCR1;

#define LCDRPSTP	0x01	/*bit masks */
#define LCDSWAI 	0x02

typedef union uFPENR0
  {
  tU08	byte;	
  struct
    {
    tU08 fp0en	:1;		
    tU08 fp1en	:1;
    tU08 fp2en	:1;
    tU08 fp3en	:1;
    tU08 fp4en	:1;
    tU08 fp5en	:1;
    tU08 fp6en	:1;		
    tU08 fp7en	:1;
    }bit;
  }tFPENR0;

#define FP0EN	0x01	/*bit masks */
#define FP1EN 	0x02
#define FP2EN	0x04
#define FP3EN 	0x08
#define FP4EN 	0x10
#define FP5EN 	0x20
#define FP6EN	0x40
#define FP7EN 	0x80

typedef union uFPENR1
  {
  tU08	byte;	
  struct
    {
    tU08 fp8en	:1;		
    tU08 fp9en	:1;
    tU08 fp10en	:1;
    tU08 fp11en	:1;
    tU08 fp12en	:1;
    tU08 fp13en	:1;
    tU08 fp14en	:1;		
    tU08 fp15en	:1;
    }bit;
  }tFPENR1;

#define FP8EN	0x01	/*bit masks */
#define FP9EN 	0x02
#define FP10EN	0x04
#define FP11EN 	0x08
#define FP12EN 	0x10
#define FP13EN 	0x20
#define FP14EN	0x40
#define FP15EN 	0x80

typedef union uFPENR2
  {
  tU08	byte;	
  struct
    {
    tU08 fp16en	:1;		
    tU08 fp17en	:1;
    tU08 fp18en	:1;
    tU08 fp19en	:1;
    tU08 fp20en	:1;
    tU08 fp21en	:1;
    tU08 fp22en	:1;		
    tU08 fp23en	:1;
    }bit;
  }tFPENR2;

#define FP16EN	0x01	/*bit masks */
#define FP17EN 	0x02
#define FP18EN	0x04
#define FP19EN 	0x08
#define FP20EN 	0x10
#define FP21EN 	0x20
#define FP22EN	0x40
#define FP23EN 	0x80

typedef union uFPENR3
  {
  tU08	byte;	
  struct
    {
    tU08 fp24en	:1;		
    tU08 fp25en	:1;
    tU08 fp26en	:1;
    tU08 fp27en	:1;
    tU08 fp28en	:1;
    tU08 fp29en	:1;
    tU08 fp30en	:1;		
    tU08 fp31en	:1;
    }bit;
  }tFPENR3;

#define FP24EN	0x01	/*bit masks */
#define FP25EN 	0x02
#define FP26EN	0x04
#define FP27EN 	0x08
#define FP28EN 	0x10
#define FP29EN 	0x20
#define FP30EN	0x40
#define FP31EN 	0x80

typedef struct				/*lcd*/
  {
  volatile tLCDCR0	lcdcr0;
  volatile tLCDCR1	lcdcr1;
  volatile tFPENR0	fpenr0;
  volatile tFPENR1  fpenr1;
  volatile tFPENR2  fpenr2;
  volatile tFPENR3  fpenr3;
           tU08		rsv[2];  /*reserved (maintaining memory map) */
  volatile tREG08	lcdram[16];	/*lcdram ~ 16 bytes*/
           
   }tLCD;

#endif /*S12LCD32F4BV1_H */