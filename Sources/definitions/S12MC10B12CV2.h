/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12MC10B12CV2.h                                      	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 MC_10B_12C						 		     */
/*                                                                           */
/* DESCRIPTION: Defines the MC_10B_12C module register block as a      		 */
/* datastructure of type tMC.         	                 					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin, TX	   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12MC10B12CV2_H			/*prevent duplicated includes */
#define S12MC10B12CV2_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uMCCTL0
  {
  tU08	byte;	
  struct
    {
    tU08 mctoif	:1;	
    tU08 		:1;		/*reserved bit space*/	
    tU08 dith	:1;
    tU08 fast	:1;
    tU08 mcswai	:1;
    tU08 mcpre0	:1;
    tU08 mcpre1	:1;
    tU08 		:1;		/*reserved bit space*/
    }bit;
  }tMCCTL0;

#define MCTOIF	0x01	/*bit masks */
#define DITH	0x04
#define FAST 	0x08
#define MCSWAI 	0x10
#define MCPRE0 	0x20
#define MCPRE1 	0x40

typedef union uMCCTL1
  {
  tU08	byte;	
  struct
    {
    tU08 mctoie	:1;	
    tU08 		:6;		/*reserved bit space*/	
    tU08 recirc	:1;
    }bit;
  }tMCCTL1;

#define MCTOIE	0x01	/*bit masks */
#define RECIRC 	0x80

typedef union uMCPER
  {
  tU16	word;
  struct
    {
    tU08 mcperh;
    tU08 mcperl;
    }byte;
  }tMCPER;
  
typedef union uMCCC0
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC0;
  
typedef union uMCCC1
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC1;

typedef union uMCCC2
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC2;

typedef union uMCCC3
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC3;

typedef union uMCCC4
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC4;

typedef union uMCCC5
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC5;
  
typedef union uMCCC6
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC6;
  
typedef union uMCCC7
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC7;
  
typedef union uMCCC8
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC8;


typedef union uMCCC9
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC9;
  
typedef union uMCCC10
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC10;


typedef union uMCCC11
  {
  tU08	byte;	
  struct
    {
    tU08 cd0	:1;	
    tU08 cd1	:1;		
    tU08 		:2;
    tU08 mcam0	:1;
    tU08 mcam1	:1;
    tU08 mcom0	:1;
    tU08 mcom1	:1;
    }bit;
  }tMCCC11;
  
#define CD0		0x01	/*bit masks */
#define CD1		0x02
#define MCAM0 	0x10
#define MCAM1 	0x20
#define MCOM0 	0x40
#define MCOM1 	0x80

typedef union uMCDC0
  {
  tU16	word;
  struct
    {
    tU08 mcdc0h;
    tU08 mcdc0l;
    }byte;
  }tMCDC0;

typedef union uMCDC1
  {
  tU16	word;
  struct
    {
    tU08 mcdc1h;
    tU08 mcdc1l;
    }byte;
  }tMCDC1;

typedef union uMCDC2
  {
  tU16	word;
  struct
    {
    tU08 mcdc2h;
    tU08 mcdc2l;
    }byte;
  }tMCDC2;
  
typedef union uMCDC3
  {
  tU16	word;
  struct
    {
    tU08 mcdc3h;
    tU08 mcdc3l;
    }byte;
  }tMCDC3;
  
typedef union uMCDC4
  {
  tU16	word;
  struct
    {
    tU08 mcdc4h;
    tU08 mcdc4l;
    }byte;
  }tMCDC4;
  
typedef union uMCDC5
  {
  tU16	word;
  struct
    {
    tU08 mcdc5h;
    tU08 mcdc5l;
    }byte;
  }tMCDC5;

typedef union uMCDC6
  {
  tU16	word;
  struct
    {
    tU08 mcdc6h;
    tU08 mcdc6l;
    }byte;
  }tMCDC6;

typedef union uMCDC7
  {
  tU16	word;
  struct
    {
    tU08 mcdc7h;
    tU08 mcdc7l;
    }byte;
  }tMCDC7;

typedef union uMCDC8
  {
  tU16	word;
  struct
    {
    tU08 mcdc8h;
    tU08 mcdc8l;
    }byte;
  }tMCDC8;

typedef union uMCDC9
  {
  tU16	word;
  struct
    {
    tU08 mcdc9h;
    tU08 mcdc9l;
    }byte;
  }tMCDC9;

typedef union uMCDC10
  {
  tU16	word;
  struct
    {
    tU08 mcdc10h;
    tU08 mcdc10l;
    }byte;
  }tMCDC10;

typedef union uMCDC11
  {
  tU16	word;
  struct
    {
    tU08 mcdc11h;
    tU08 mcdc11l;
    }byte;
  }tMCDC11;
  
typedef struct				/*motor controller*/
  {
  volatile tMCCTL0	mcctl0;		/*mc control register 0 */
  volatile tMCCTL1	mcctl1;		/*mc control register 1 */
  volatile tMCPER	mcper;		/*mc period register */
      	   tU08 	rsv[12]; 	/*reserved space */
  volatile tMCCC0	mccc0;		/*mc channel control registers */
  volatile tMCCC1	mccc1;
  volatile tMCCC2	mccc2;
  volatile tMCCC3	mccc3;
  volatile tMCCC4	mccc4;
  volatile tMCCC5	mccc5;
  volatile tMCCC6	mccc6;
  volatile tMCCC7	mccc7;
  volatile tMCCC8	mccc8;
  volatile tMCCC9	mccc9;
  volatile tMCCC10	mccc10;
  volatile tMCCC11	mccc11;
 		   tU08		rsv2[4];	/*reserved space */
  volatile tMCDC0	mcdc0;		/*mc duty cycle registers */
  volatile tMCDC1	mcdc1;
  volatile tMCDC2	mcdc2;
  volatile tMCDC3	mcdc3;
  volatile tMCDC4	mcdc4;
  volatile tMCDC5	mcdc5;
  volatile tMCDC6	mcdc6;
  volatile tMCDC7	mcdc7;
  volatile tMCDC8	mcdc8;
  volatile tMCDC9	mcdc9;
  volatile tMCDC10	mcdc10;
  volatile tMCDC11	mcdc11;
 		   tU08		rsv3[8];	/*reserved space */
           
   }tMC;

#endif /*S12MC10B12CV2_H*/