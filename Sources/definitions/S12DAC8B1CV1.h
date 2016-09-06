/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12DAC8B1CV1.h                                           	     */
/*                                                                           */
/* PURPOSE: Header File for S12 DAC		     					 		     */
/*                                                                           */
/* DESCRIPTION: Defines the DAC module register block as a           		 */
/* datastructure of type tDAC.                           					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin, TX								 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12DAC8B1CV1_H			/*prevent duplicated includes */
#define S12DAC8B1CV1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uDACC0
{
  	tU08 byte;
  	struct
    {
    	tU08 dacoe	 :1;		/*dac output enable */
    	tU08 dacwai	 :1;		/*dac stop in WAIT mode */
    	tU08 dacdsgn :1;		/*data register signed */
    	tU08 dacdjm	 :1;		/*data register data justification */
    	tU08 		 :2;		/*not used */
    	tU08 dacte	 :1;		/*read only*/
    	tU08 dace	 :1;		/*dac enable */
    }bit;
}tDACC0;

#define DACOE	0x01	/*bit masks */
#define DACWAI	0x02
#define DACDSGN	0x04
#define DACDJM	0x08
#define DACTE	0x40
#define DACE	0x80

/*Used bitfields like dacdsgn and dacdjm instead of dsgn and djm to avoid
  conflict with other peripherals */
  
typedef union uDACC1
{
  	tU08 byte;
  	struct
    {
    	tU08 	 :8;		/*not used */
    }bit;
}tDACC1;

typedef union uDACDL
{
  	tU08 byte;
  	struct
    {
    	tU08 	 :8;		/*data register - left justified */
    }bit;
}tDACDL;

typedef union uDACDR
{
  	tU08 byte;
  	struct
    {
    	tU08 	 :8;		/*data register - right justified */
    }bit;
}tDACDR;

typedef struct						/*dac module */ 
{
  volatile tDACC0	 	dacc0;		/*dac control register 0 */
  volatile tDACC1	 	dacc1;		/*dac reserved register */
  volatile tDACDL	 	dacdl;		/*dac data register - left justified */
  volatile tDACDR	  	dacdr;		/*dac data register - right justified */
}tDAC;

#endif /*S12DAC8B1CV1_H*/