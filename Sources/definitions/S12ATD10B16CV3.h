/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12ATD10B16CV3.h                                               */
/*                                                                           */
/* PURPOSE: Header File for S12 ATD_10B16C	     					 		 */
/*                                                                           */
/* DESCRIPTION: Defines the ATD convertor module register block as a         */
/* datastructure of type tATD.                           					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin,TX 								 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12ATD10B16CV3_H	/*prevent duplicated includes */
#define S12ATD10B16CV3_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uATDCTL0
{
	tU08 byte;
 	struct
    {
    	tU08 wrap	 :4;		/*wrap around ch. select bits */
    	tU08 		 :4;		/*not used */
    }bit;
}tATDCTL0;

#define WRAP0	0x01	/*bit masks */
#define WRAP1	0x02
#define WRAP2	0x04
#define WRAP3	0x08

typedef union uATDCTL1
{
	tU08 byte;
 	struct
    {
    	tU08 etrigch :4;		/*external trigger channel select */
    	tU08     	 :3;		/*not used */
    	tU08 etrigsel:1;		/*external trigger source select */
    }bit;
}tATDCTL1;

#define ETRIGCH0	0x01	/*bit masks */
#define ETRIGCH1	0x02
#define ETRIGCH2	0x04
#define ETRIGCH3	0x08
#define ETRIGSEL	0x80

typedef union uATDCTL2
{
	tU08 byte;
 	struct
    {
    	tU08 ascif	 :1;		/*atd sequence interrupt flag */
    	tU08 ascie	 :1;		/*atd complete interrupt enable */
    	tU08 etrige	 :1;		/*external trigger mode enable */
    	tU08 etrigp	 :1;		/*external trigger polarity */
    	tU08 etrigle :1;		/*external trigger level/edge control */
    	tU08 awai	 :1;		/*atd stops in wait mode */
    	tU08 affc	 :1;		/*atd fast flag clear all */
    	tU08 adpu	 :1;		/*atd enable */
    }bit;
}tATDCTL2;

#define ASCIF	0x01	/*bit masks */
#define ASCIE	0x02
#define ETRIGE	0x04
#define ETRIGP	0x08
#define ETRIGLE	0x10
#define AWAI	0x20
#define AFFC	0x40
#define ADPU	0x80

typedef union uATDCTL3
{
	tU08 byte;
	struct
    {
    	tU08 frz	:2;		/*atd background mode */
    	tU08 fifo	:1;		/*results mapped to fifo mode */
    	tU08 slc	:4;		/*conversion sequence length */
    	tU08		:1;		/*not used */
    }bit;
}tATDCTL3;

#define FRZ0	0x01	/*bit masks */
#define FRZ1	0x02
#define FIFO	0x04
#define S1C 	0x08
#define S2C 	0x10
#define S4C 	0x20
#define S8C 	0x40

typedef union uATDCTL4
{
	tU08 byte;
  	struct
    {
    	tU08 prs	:5;		/*atd P clock prescaler */
    	tU08 smp	:2;		/*atd sample time */
   		tU08 sres8	:1;		/*atd 8-bit mode */
    }bit;
}tATDCTL4;

#define PRS0	0x01	/*bit masks */
#define PRS1	0x02
#define PRS2	0x04
#define PRS3	0x08
#define PRS4	0x10
#define SMP0	0x20
#define SMP1	0x40
#define SRES8	0x80

typedef union uATDCTL5
{
	tU08 byte;
 	 struct
    {
    	tU08 cx		:4;		/*atd channel select */
    	tU08 mult	:1;		/*atd multichannel conversion enable */
    	tU08 scan	:1;		/*atd continuous scan enable */
    	tU08 dsgn	:1;		/*signed/unsigned result mode */
    	tU08 djm	:1;		/*result data register justification mode */
    }bit;
}tATDCTL5;

#define CA		0x01	/*bit masks */
#define CB		0x02
#define CC		0x04
#define CD		0x08
#define MULT	0x10
#define SCAN	0x20
#define DSGN	0x40
#define DJM 	0x80

typedef union uATDSTAT0
{
	tU08 byte;
	struct
    {
    	tU08 ccx	:4;		/*conversion counter for current sequence */
    	tU08 fifor	:1;		/*fifo overrun flag */
   		tU08 etorf	:1;		/*external trigger overrun flag */
    	tU08		:1;		/*not used */
    	tU08 scf	:1;		/*atd sequence complete flag */
    }bit;
}tATDSTAT0;

#define CC0		0x01	/*bit masks */
#define CC1		0x02
#define CC2		0x04
#define CC3		0x08
#define FIFOR	0x10
#define ETORF	0x20
#define SCF		0x80

typedef union uATDTEST0
{
	tU08 byte;
  	struct
    {
    	tU08       	:8;		/*not used */
    }bit;
}tATDTEST0;

typedef union uATDTEST1
{
	tU08 byte;
  	struct
    {
    	tU08 sc		:1;		/*special channel conversion mode */
    	tU08       	:7;		/*not used */
    }bit;
}tATDTEST1;

#define SC  	0x01	/*bit masks */

typedef union uATDSTAT2
{
	tU08 byte;
  	struct
    {
    	tU08 ccf8	:1;		/*atd conversion complete flags */
    	tU08 ccf9	:1;
    	tU08 ccf10	:1;
    	tU08 ccf11	:1;
    	tU08 ccf12	:1;
    	tU08 ccf13	:1;
    	tU08 ccf14	:1;
    	tU08 ccf15	:1;
    }bit;
}tATDSTAT2;

#define	CCF8	0x01	/*bit masks	*/
#define CCF9	0x02
#define CCF10	0x04
#define CCF11	0x08
#define CCF12	0x10
#define CCF13	0x20
#define CCF14	0x40
#define CCF15	0x80

typedef union uATDSTAT1
{
	tU08 byte;
 	struct
    {
    	tU08 ccf0	:1;		/*atd conversion complete flags */
    	tU08 ccf1	:1;
    	tU08 ccf2	:1;
    	tU08 ccf3	:1;
    	tU08 ccf4	:1;
    	tU08 ccf5	:1;
    	tU08 ccf6	:1;
    	tU08 ccf7	:1;
    }bit;
}tATDSTAT1;

#define	CCF0	0x01	/*bit masks	*/
#define CCF1	0x02
#define CCF2	0x04
#define CCF3	0x08
#define CCF4	0x10
#define CCF5	0x20
#define CCF6	0x40
#define CCF7	0x80


typedef union uATDDIEN0
{
	tU08 byte;
  	struct
    {
    	tU08 ien0	:1;		/*input enable mask */
    	tU08 ien1	:1;
    	tU08 ien2	:1;
    	tU08 ien3 	:1;
    	tU08 ien4 	:1;
    	tU08 ien5	:1;
    	tU08 ien6	:1;
    	tU08 ien7	:1;
    }bit;
}tATDDIEN0;

#define IEN0	0x01	/*bit masks */
#define IEN1 	0x02
#define IEN2 	0x04
#define IEN3 	0x08
#define IEN4 	0x10
#define IEN5 	0x20
#define IEN6 	0x40
#define IEN7 	0x80

typedef union uATDDIEN1
{
	tU08 byte;
  	struct
    {
    	tU08 ien8	:1;		/*input enable mask */
    	tU08 ien9	:1;
    	tU08 ien10	:1;
    	tU08 ien11  :1;
    	tU08 ien12  :1;
    	tU08 ien13	:1;
    	tU08 ien14	:1;
    	tU08 ien15	:1;
    }bit;
}tATDDIEN1;

#define IEN8	0x01	/*bit masks */
#define IEN9 	0x02
#define IEN10 	0x04
#define IEN11 	0x08
#define IEN12 	0x10
#define IEN13 	0x20
#define IEN14 	0x40
#define IEN15 	0x80

typedef union uPORTAD0
{
	tU08 byte;
  	struct
    {
    	tU08 ptad8	:1;		/*input port pins */
    	tU08 ptad9	:1;
    	tU08 ptad10	:1;
    	tU08 ptad11 :1;
    	tU08 ptad12 :1;
    	tU08 ptad13	:1;
    	tU08 ptad14	:1;
    	tU08 ptad15	:1;
    }bit;
}tPORTAD0;

#define PTAD8	0x01	/*bit masks */
#define PTAD9 	0x02
#define PTAD10 	0x04
#define PTAD11 	0x08
#define PTAD12 	0x10
#define PTAD13 	0x20
#define PTAD14 	0x40
#define PTAD15 	0x80

typedef union uPORTAD1
{
	tU08 byte;
  	struct
    {
    	tU08 ptad0	:1;		/*input port pins */
    	tU08 ptad1	:1;
    	tU08 ptad2	:1;
    	tU08 ptad3 	:1;
    	tU08 ptad4 	:1;
    	tU08 ptad5	:1;
    	tU08 ptad6	:1;
    	tU08 ptad7	:1;
    }bit;
}tPORTAD1;

#define PAD0	0x01	/*bit masks */
#define PAD1 	0x02
#define PAD2 	0x04
#define PAD3 	0x08
#define PAD4 	0x10
#define PAD5 	0x20
#define PAD6 	0x40
#define PAD7 	0x80
  
typedef union uATDDR		/*ATD data register */
{
	tU16 d10;			
  	struct				
    {
    	tU08 datah;			
    	tU08 datal;			
    }d8;
}tATDDR;

typedef struct						/*atd module */ 
{
  volatile tATDCTL0		atdctl0;	/*atd control register 0 */
  volatile tATDCTL1		atdctl1;	/*atd control register 1 */
  volatile tATDCTL2	 	atdctl2;	/*atd control register 2 */
  volatile tATDCTL3	 	atdctl3;	/*atd control register 3 */
  volatile tATDCTL4	 	atdctl4;	/*atd control register 4 */
  volatile tATDCTL5  	atdctl5;	/*atd control register 5 */
  volatile tATDSTAT0 	atdstat0;	/*atd status register 0 */
  		   tU08			rsv1;		/*reserved (maintaining memory map) */  
  volatile tATDTEST0 	atdtest0;	/*atd test register */ 
  volatile tATDTEST1    atdtest1;	/*atd test register */ 
  volatile tATDSTAT2 	atdstat2;	/*atd status register 2 */
  volatile tATDSTAT1 	atdstat1;	/*atd status register 1 */
  volatile tATDDIEN0	atddien0;	/*atd digital i/p buffer enable */
  volatile tATDDIEN1	atddien1;	/*atd digital i/p buffer enable */
  volatile tPORTAD0	 	portad0;	/*port AD input register */
  volatile tPORTAD1	 	portad1;	/*port AD input register */
  volatile tATDDR	  	atddr[16];	/*atd result registers*/
}tATD;

#endif /*S12ATD10B16CV3_H*/