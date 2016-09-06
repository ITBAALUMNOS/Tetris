/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12IICV2.h                                          	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 IIC								 		     */
/*                                                                           */
/* DESCRIPTION: Defines the IIC module register block as a          		 */
/* datastructure of type tIIC.                          					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB   		   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12IICV2_H			/*prevent duplicated includes */
#define S12IICV2_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uIBAD
  {
  tU08	byte;
  struct
    {
    tU08		:1;
    tU08 adr	:7;		/*slave address bits */
    }bit;
  }tIBAD;

#define ADR1	0x02	/*bit masks	*/
#define ADR2	0x04
#define ADR3	0x08
#define ADR4	0x10
#define ADR5	0x20
#define ADR6	0x40
#define ADR7	0x80

typedef union uIBFD
  {
  tU08	byte;
  struct
    {
    tU08 ibc	:8;		/*iic bus clock rate bits */
    }bit;
  }tIBFD;

#define IBC0	0x01	/*bit masks	*/
#define IBC1	0x02
#define IBC2	0x04
#define IBC3	0x08
#define IBC4	0x10
#define IBC5	0x20
#define IBC6	0x40
#define IBC7	0x80

typedef union uIBCR
  {
  tU08	byte;
  struct
    {
    tU08 ibswai	:1;		/*iic stops in wait mode */
    tU08		:1;		/*not used */
    tU08 rsta	:1;		/*repeat start */
    tU08 txak	:1;		/*transmit acknowledge enable */
    tU08 txrx	:1;		/*transmit/receive mode select */
    tU08 mssl	:1;		/*master/slave mode select */
    tU08 ibie	:1;		/*iic bus interrupt enable */
    tU08 iben	:1;		/*iic bus enable */
    }bit;
  }tIBCR;

#define IBSWAI	0x01	/*bit masks	*/
#define RSTA	0x04
#define TXAK	0x08
#define TXRX	0x10
#define MSSL	0x20
#define IBIE	0x40
#define IBEN	0x80

typedef union uIBSR
  {
  tU08	byte;
  struct
    {
    tU08 rxak	:1;		/*received acknowledge */
    tU08 ibif	:1;		/*iic bus interrupt flag */
    tU08 srw	:1;		/*slave read/write */
    tU08		:1;		/*not used */
    tU08 ibal	:1;		/*arbitration lost */
    tU08 ibb	:1;		/*iic busy bit */
    tU08 iaas	:1;		/*addressed as a slave bit */
    tU08 tcf	:1;		/*data transferring bit	*/
    }bit;
  }tIBSR;

#define RXAK	0x01	/*bit masks	*/
#define IBIF 	0x02
#define SRW 	0x04
#define IBAL 	0x10
#define IBB 	0x20
#define IAAS 	0x40
#define TCF 	0x80

typedef union uIBDR
  {
  tU08	byte;
  struct
    {
    tU08		:1;
    tU08 d		:7;		/*data I/O register */
    }bit;
  }tIBDR;

typedef struct				
  {
  volatile tIBAD	ibad;	/*iic bus address register */
  volatile tIBFD	ibfd;	/*iic bus frequency divider register */
  volatile tIBCR	ibcr;	/*iic bus control register */
  volatile tIBSR	ibsr;	/*iic bus status register */
  volatile tIBDR	ibdr;	/*iic bus data register	*/
		   tU08		rsv[3]; /*reserved to complete module memory map */
  }tIIC;

#endif /*S12IICV2_H */