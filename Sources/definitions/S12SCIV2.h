/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12SCIV2.h                                        	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 SCI     						 		     */
/*                                                                           */
/* DESCRIPTION: Defines the SCI module register block as a          		 */
/* datastructure of type tSCI.         	                 					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB			   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12SCIV2_H			/*prevent duplicated includes */
#define S12SCIV2_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uSCIBDH
{
	tU08 byte;
  	struct
    {
    	tU08 sbr8	:1;		/*msb baud rate select bits	*/
    	tU08 sbr9	:1;
    	tU08 sbr10	:1;
   		tU08 sbr11	:1;
    	tU08 sbr12	:1;
    	tU08 		:3;		/*not used */
    }bit;
}tSCIBDH;

#define SBR8	0x01	/*bit masks	*/
#define SBR9	0x02
#define SBR10	0x04
#define SBR11	0x08
#define SBR12	0x10

typedef union uSCIBDL
{
	tU08 byte;
 	struct
    {
    	tU08 sbr0	:1;		/*msb baud rate select bits	*/
    	tU08 sbr1	:1;
    	tU08 sbr2	:1;
    	tU08 sbr3	:1;
    	tU08 sbr4	:1;
    	tU08 sbr5	:1;		
    	tU08 sbr6	:1;		
    	tU08 sbr7   :1;		
    }bit;
}tSCIBDL;

#define SBR0	0x01	/*bit masks	*/
#define SBR1	0x02
#define SBR2	0x04
#define SBR3	0x08
#define SBR4	0x10
#define SBR5	0x20
#define SBR6	0x40
#define SBR7	0x80

typedef union 
{
	tU16 word;
 	 struct
    {
    	tSCIBDH	msb;
    	tSCIBDL	lsb;
    }byte;
}tSCIBD;

typedef union uSCICR1
  {
  tU08	byte;
  struct
    {
    tU08 pt			:1;		/*parity type */
    tU08 pe			:1;		/*parity enable	*/
    tU08 ilt		:1;		/*idle line type */
    tU08 wake		:1;		/*wake up by address mark/idle */
    tU08 m			:1;		/*mode select */
    tU08 rsrc		:1;		/*receiver source */
    tU08 sciswai	:1;		/*stop in wait mode	*/
    tU08 loops		:1;		/*loop mode/single wire mode enable	*/
    }bit;
  }tSCICR1;

#define PT		0x01	/*bit masks	*/
#define PE		0x02
#define ILT		0x04
#define WAKE	0x08
#define M	    0x10
#define RSRC	0x20
#define SCISWAI	0x40
#define LOOPS	0x80

typedef union uSCICR2
  {
  tU08	byte;
  struct
    {
    tU08 sbk	:1;		/*send break character */
    tU08 rwu	:1;		/*receiver wake-up control */
    tU08 re		:1;		/*receiver enable */
    tU08 te		:1;		/*transmitter enable */
    tU08 ilie	:1;		/*idle line interrupt enable */
    tU08 rie	:1;		/*receiver interrupt enable	*/
    tU08 tcie	:1;		/*transmit complete interrupt enable */
    tU08 tie	:1;		/*transmit interrupt enable	*/
    }bit;
  }tSCICR2;

#define SBK		0x01	/*bit masks	*/
#define RWU		0x02
#define RE		0x04
#define TE		0x08
#define ILIE	0x10
#define RIE		0x20
#define TCIE	0x40
#define TIE		0x80

typedef union uSCISR1
  {
  tU08	byte;
  struct
    {
    tU08 pf		:1;		/*parity error flag	*/
    tU08 fe		:1;		/*framing error flag */
    tU08 nf		:1;		/*noise error flag */
    tU08 orf	:1;		/*overrun error flag - 'or' in specification */
    tU08 idle	:1;		/*idle line detected flag */
    tU08 rdrf	:1;		/*receive data register full flag */
    tU08 tc		:1;		/*transmit complete flag */
    tU08 tdre	:1;		/*transmit data register empty flag	*/
    }bit;
  }tSCISR1;

#define PF		0x01	/*bit masks	*/
#define FE		0x02
#define NF		0x04
#define ORF		0x08	/* 'OR' in specification */
#define IDLE	0x10
#define RDRF	0x20
#define TC		0x40
#define TDRE	0x80

typedef union uSCISR2
  {
  tU08	byte;
  struct
    {
    tU08 raf	:1;		/*receiver active flag */
	tU08 txdir	:1;		/*receiver active flag */
    tU08 brk13	:1;		/*brk transmit character length */
    tU08 		:5;		/*not used */
    }bit;
  }tSCISR2;

#define RAF		0x01	/*bit masks	*/
#define TXDIR	0x02	
#define BRK13	0x04	

typedef union uSCIDRH
  {
  tU08	byte;
  struct
    {
    tU08		:6;		/*not used */
    tU08 t8		:1;		/*transmit bit 8 */
    tU08 r8		:1;		/*receive bit 8	*/
    }bit;
  }tSCIDRH;

#define T8		0x40	/*bit masks	*/
#define R8		0x80

typedef union uSCIDRL
  {
  tU08  byte;
  struct
    {
    tU08 t0r0	:1;		/*tx / rx bits */
    tU08 t1r1   :1;
    tU08 t2r2   :1;
    tU08 t3r3   :1;
    tU08 t4r4	:1;
    tU08 t5r5   :1;
    tU08 t6r6   :1;
    tU08 t7r7   :1;
    }bit;
  }tSCIDRL;
  
#define T0R0	0x01
#define T1R1	0x02
#define T2R2	0x04
#define T3R3    0x08
#define T4R4    0x10
#define T5R5	0x20
#define T6R6	0x40
#define T7R7	0x80

typedef struct				/*sci datastructure	*/
{
    volatile tSCIBD		scibd;	/*sci baud rate registers */
    volatile tSCICR1	scicr1;	/*sci control register 1 */
    volatile tSCICR2	scicr2;	/*sci control register 2 */
  	volatile tSCISR1	scisr1;	/*sci status register 1	*/
  	volatile tSCISR2	scisr2;	/*sci status register 2	*/
  	volatile tSCIDRH	scidrh;	/*sci data register high */
  	volatile tSCIDRL	scidrl;	/*sci data register low	*/
}tSCI;


#endif /*S12SCIV2_H */