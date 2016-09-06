/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12SPIV2.h                                        	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 SPI     						 		     */
/*                                                                           */
/* DESCRIPTION: Defines the SPI module register block as a          		 */
/* datastructure of type tSPI.         	                 					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB			   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12SPIV2_H			/*prevent duplicated includes */
#define S12SPIV2_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uSPICR1
  {
  tU08	byte;
  struct
    {
    tU08 lsbfe	:1;		/*lsb first enable */
    tU08 ssoe	:1;		/*slave select output enable */
    tU08 cpha	:1;		/*clock phase */
    tU08 cpol	:1;		/*clock polarity */
    tU08 mstr	:1;		/*master/slave mode select */
    tU08 sptie	:1;		/*transmit interrupt enable */
    tU08 spe 	:1;		/*spi enable */
    tU08 spie	:1;		/*spi interrupt enable */
    }bit;
  }tSPICR1;

#define LSBFE	0x01	/*bit masks	*/
#define SSOE	0x02
#define CPHA	0x04
#define CPOL	0x08
#define MSTR	0x10
#define SPTIE	0x20
#define SPE		0x40
#define SPIE	0x80

typedef union uSPICR2
  {
  tU08	byte;
  struct
    {
    tU08 spc0	 :1;	/*serial pin control 0 */
    tU08 spiswai :1;	/*stop in wait mode	*/
    tU08 		 :1;	/*not used */
    tU08 bidiroe :1;	/*bi-directional mode output enable */
    tU08 modfen	 :1;	/*mode fault enable	*/
    tU08		 :3;	/*not used */
    }bit;
  }tSPICR2;

#define SPC0	0x01	/*bit masks	*/
#define SPISWAI	0x02
#define BIDIROE	0x08
#define MODFEN	0x10

typedef union uSPIBR
  {
  tU08 byte;
  struct
    {
    tU08 spr 	:3;  /*baud rate selection */
    tU08   	 	:1;  /*not used*/           
    tU08 sppr	:3;  /*baud rate pre-selection */
    tU08   		:1;  /*not used */            
    }bit;
  }tSPIBR;
 
#define SPR0  0x01 /*bit masks */
#define SPR1  0x02
#define SPR2  0x04
#define SPR   0x07 /*baud rate selection mask */
#define SPPR0 0x10
#define SPPR1 0x20
#define SPPR2 0x40 
#define SPPR  0x70 /*baud rate pre-selection mask */

typedef union uSPISR
  {
  tU08	byte;
  struct
    {
    tU08		:4;		/*not used */
    tU08 modf	:1;		/*mode error interrupt status flag */
    tU08 sptef	:1;		/*transmit empty interrupt flag */
	tU08		:1;		/*not used */
    tU08 spif	:1;		/*spi interrupt request	*/
    }bit;
  }tSPISR;

#define MODF	0x10	/*bit masks	*/
#define SPTEF	0x20
#define SPIF	0x80

typedef union uSPIDR
  {
  tU08 byte;
  struct
    {
    tU08 data	:8;		/*data bits*/
    }bit;
  }tSPIDR;


typedef struct				/*spi datastructure	*/
  {
  volatile tSPICR1	spicr1;	/*spi control register 1 */
  volatile tSPICR2	spicr2;	/*spi control register 2 */
  volatile tSPIBR	spibr;	/*spi baud rate register */
  volatile tSPISR	spisr;	/*spi status register */
           tU08		rsv;	/*reserved (maintaining memory map)	*/
  volatile tSPIDR	spidr;	/*spi data register	*/
           tU16		rsv2;	/*reserved (maintaining module memory map) */
  }tSPI;

#endif /*S12SPIV2_H */