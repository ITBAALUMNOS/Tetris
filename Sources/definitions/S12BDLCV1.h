/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12BDLCV1.h                                               	 */
/*                                                                           */
/* PURPOSE: Header File for S12 BDLC		     					 		 */
/*                                                                           */
/* DESCRIPTION: Defines the BDLC module register block as a         		 */
/* datastructure of type tBDLC.                           					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB     									 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12BDLCV1_H			/*prevent duplicated includes */
#define S12BDLCV1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uDLCBCR1
{
    tU08 byte;
  	struct
    {
    	tU08 wcm	:1;		/*wait clock mode select	*/
    	tU08 ie		:1;		/*interrupt enable */
    	tU08 		:4;		/*not used */
    	tU08 clks	:1;		/*clock select */
    	tU08 imsg	:1;		/*ignore message */
    }bit;
}tDLCBCR1;

#define WCM		0x01	/*bit masks	*/
#define IE		0x02
#define CLKS	0x40
#define IMSG	0x80

typedef union uDLCBSVR
{
    tU08 byte;
 	 struct
    {
    	tU08 		:2;		/*not used */
    	tU08 i0		:1;		/*interrupt state vector bits */
    	tU08 i1		:1;
    	tU08 i2		:1;
    	tU08 i3		:1;
    	tU08 		:2;		/*not used */
    }bit;
}tDLCBSVR;

#define I0		0x04	/*bit masks	*/
#define I1		0x08
#define I2		0x10
#define I3		0x20

typedef union uDLCBCR2
{
  	tU08 byte;
  	struct
    {
    	tU08 tmifr0	:1;		/*transmit in-frame response control 0 */
    	tU08 tmifr1	:1;		/*transmit in-frame response control 1 */
    	tU08 tsifr	:1;		/*transmit single byte IFR with no CRC */
    	tU08 teod	:1;		/*transmit end of data */
    	tU08 nbfs	:1;		/*normalization bit format select */
    	tU08 rx4xe	:1;		/*receive 4x enable	*/
    	tU08 dloop	:1;		/*digital loop back mode */
    	tU08 smrst	:1;		/*state machine reset */
    }bit;
}tDLCBCR2;

#define TMIFR0	0x01	/*bit masks	*/
#define TMIFR1	0x02
#define TSIFR 	0x04
#define TEOD	0x08
#define NBFS	0x10
#define RX4XE	0x20
#define DLOOP	0x40
#define SMRST	0x80

typedef union uDLCBDR
{
  	tU08 byte;
  	struct
    {
    	tU08 d0	:1;		/*data register */
    	tU08 d1	:1;		
    	tU08 d2	:1;		
    	tU08 d3	:1;		
    	tU08 d4	:1;		
    	tU08 d5	:1;		
    	tU08 d6	:1;		
    	tU08 d7	:1;		
    }bit;
}tDLCBDR;

typedef union uDLCBARD
{
  	tU08 byte;
  	struct
    {
    	tU08 bo		:4;		/*analog round trip offset*/
    	tU08 		:2;		/*not used*/
    	tU08 rxpol	:1;		/*receive pin polarity */
    	tU08 		:1;		/*not used*/
    }bit;
}tDLCBARD;

#define B0		0x01	/*bit masks	*/
#define B1		0x02
#define B2		0x04
#define B3		0x08
#define RXPOL	0x40

typedef union uDLCBRSR
{
  	tU08 byte;
  	struct
    {
    	tU08 r		:6;		/*rate select bits	*/
    	tU08 		:2;		/*not used */
    }bit;
}tDLCBRSR;

#define R0		0x01	/*bit masks	*/
#define R1		0x02
#define R2		0x04
#define R3		0x08
#define R4		0x10
#define R5		0x20

typedef union uDLCSCR
{
  	tU08 byte;
  	struct
    {
    	tU08 		:4;		/*not used*/
    	tU08 bdlce	:1;		/*bdlc enable */
    	tU08 		:3;		/*not used*/
    }bit;
}tDLCSCR;

#define BDLCE	0x10	/*bit masks	*/

typedef union uDLCBSTAT
{
  	tU08 byte;
  	struct
    {
    	tU08 bidle	:1;		/*idle status */
    	tU08 		:7;		/*not used*/
    }bit;
}tDLCBSTAT;
						/*NOTE: idle bit declared as bidle to avoid */
						/*      contention with SCI idle bit */

#define BIDLE	0x01	/*bit masks	*/

typedef struct						/*bdlc datastructure	*/
{
  volatile tDLCBCR1		dlcbcr1;	/*bdlc control register 1 */
  volatile tDLCBSVR		dlcbsvr;	/*bdlc state vector register */
  volatile tDLCBCR2		dlcbcr2;	/*bdlc control register 2 */
  volatile tDLCBDR		dlcbdr;		/*bdlc data register */
  volatile tDLCBARD		dlcbard;	/*bdlc analog round trip delay register */
  volatile tDLCBRSR		dlcbrsr;	/*bdlc rate select register */
  volatile tDLCSCR		dlcscr;		/*bdlc control register */
  volatile tDLCBSTAT	dlcbstat;	/*bdlc status register */
}tBDLC;


#endif /*S12BDLCV1_H */