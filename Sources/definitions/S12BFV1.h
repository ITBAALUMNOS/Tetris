/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12BFV1.h                                               	     */
/*                                                                           */
/* PURPOSE: Header File for S12 BF		     					 		     */
/*                                                                           */
/* DESCRIPTION: Defines the BF module register block as a           		 */
/* datastructure of type tBF.                           					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r28318        LOCATION: EKB     									 */
/*                                                                           */
/*****************************************************************************/


#ifndef S12BFV1_H		/*prevent duplicated includes*/
#define S12BFV1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes*/
#include "MOTTYPES.h"
#endif

typedef union uBFMCR
{
  	tU08 byte;
  	struct
  	{
  		tU08 initak	:1;		/*Initialization acknowledge*/
  		tU08 sswai	:1;		/*Stops in Wait Mode*/
  		tU08 wpulse	:1;		/*Wake Up Pulses*/
  		tU08 slprq	:1;		/*Sleep Request*/
  		tU08 slpak	:1;		/*Sleep Acknowledge*/
  		tU08 alarm	:1;		/*Master Alarm Pulses*/
  		tU08 master :1;		/*Master Select*/
  		tU08 initrq :1;		/*Initialization request*/
  	}bit;
}tBFMCR;
  
#define INITAK	0x01	/*bit masks	*/
#define SSWAI	0x02
#define WPULSE	0x04
#define SLPREQ	0x08
#define SLPACK	0x10
#define ALARM	0x20
#define MASTER	0x40
#define INITREQ	0x80

typedef union uBFFSIZR
{
  	tU08 byte;
  	struct
  	{
  		tU08 fsize	:5;		/* FIFO size Bits*/
  		tU08 		:1;		/*not used*/
  		tU08 		:1;		/*not used*/
  		tU08 		:1;		/*not used*/
  	}bit;
}tBFFSIZR;
  
#define FSIZ0	0x01	/*bit masks	*/
#define FSIZ1	0x02
#define FSIZ2	0x04
#define FSIZ3	0x08
#define FSIZ4	0x10

typedef union uBFTCR1
{
    tU08 byte;
    struct
  	{
  		tU08 twxot	:8;		/* Transmit Offset time Bits*/
   	}bit;
}tBFTCR1;
  
#define TWXOT0	0x01	/*bit masks	*/
#define TWXOT1	0x02
#define TWXOT2	0x04
#define TWXOT3	0x08
#define TWXOT4	0x10
#define TWXOT5	0x20
#define TWXOT6	0x40
#define TWXOT7	0x80

typedef union uBFTCR2
{
    tU08 byte;
    struct
  	{
  		tU08 twxor	:8;		/* Receive Offset time Bits*/
   	}bit;
}tBFTCR2;
  
#define TWXOR0	0x01	/*bit masks	*/
#define TWXOR1	0x02
#define TWXOR2	0x04
#define TWXOR3	0x08
#define TWXOR4	0x10
#define TWXOR5	0x20
#define TWXOR6	0x40
#define TWXOR7	0x80

typedef union uBFTCR3
{
	tU08 byte;
  	struct
  	{
  		tU08 twxod	:8;		/* Delta Offset time Bits*/
   	}bit;
}tBFTCR3;
  
#define TWXOD0	0x01	/*bit masks	*/
#define TWXOD1	0x02
#define TWXOD2	0x04
#define TWXOD3	0x08
#define TWXOD4	0x10
#define TWXOD5	0x20
#define TWXOD6	0x40
#define TWXOD7	0x80

typedef union uBFIDX
{
    tU08 byte;
  	struct
  	{
  		tU08 putidx	:4;		/* Put index bits*/
  		tU08 getidx	:4;		/* Put index bits*/
   	}bit;
}tBFIDX;
  
#define PUTIDX0	0x01	/*bit masks	*/
#define PUTIDX1	0x02
#define PUTIDX2	0x04
#define PUTIDX3	0x08
#define GETIDX0	0x10
#define GETIDX1	0x20
#define GETIDX2	0x40
#define GETIDX3	0x80

typedef union uBFRISR
{
  	tU08 byte;
  	struct
  	{
  		tU08 optdf	:1;		/*Optical diagnosis flag*/
  		tU08 xsynif	:1;		/*Xsync pulse interrupt flag*/
  		tU08 		:1;		/*not used*/
  		tU08 slmmif	:1;		/*Slot mismatch interrupt flag*/
  		tU08 synnif :1;		/*Sync normal pulse interrupt flag*/
  		tU08 synaif :1;		/*Sync Alarm pulse interrupt flag*/
  		tU08 rxif	:1;		/*Receive interrupt flag*/
  		tU08 rcvfif	:1;		/*Receive FIFO not empty interrupt flag*/
   	}bit;
}tBFRISR;
  
#define OPTDF	0x01	/*bit masks	*/
#define XSYNIF	0x02
#define SLMMIF	0x08
#define SYNNIF	0x10
#define SYNAIF	0x20
#define RXIF	0x40
#define RCVFIF	0x80

typedef union uBFGISR
{
	tU08 byte;
  	struct
  	{
  		tU08 wakeif	:1;		/*Wake up interrupt flag*/
  		tU08 lockif	:1;		/*Locking error interrupt flag*/
  		tU08 illpif :1;		/*Illegal pulse error interrupt flag*/
  		tU08 synlif	:1;		/*Sync pulse lost interrupt flag*/
  		tU08 syneif :1;		/*Sync pulse too early interrupt flag*/
  		tU08 errif	:1;		/*Message format error interrupt flag*/
  		tU08 ovrnif	:1;		/*Receive FIFO overrun interrupt flag*/
  		tU08 txif	:1;		/*Transmit interrupt flag*/
   	}bit;
}tBFGISR;
  
#define WAKEIF	0x01	/*bit masks	*/
#define LCKIF	0x02
#define ILLPIF	0x04
#define SYNLIF	0x08
#define SYNEIF	0x10
#define ERRIF	0x20
#define OVRNIF	0x40
#define TXIF	0x80

typedef union uBFRIER
{
  	tU08 byte;
    struct
  	{
  		tU08 		:1;		/*NOT USED*/
  		tU08 xsynie	:1;		/*Xsync pulse interrupt enable*/
  		tU08 		:1;		/*not used*/
  		tU08 slmmie	:1;		/*Slot mismatch interrupt enable*/
  		tU08 synnie :1;		/*Sync normal pulse interrupt enable*/
  		tU08 synaie :1;		/*Sync Alarm pulse interrupt enable*/
  		tU08 rxie	:1;		/*Receive interrupt enable*/
  		tU08 rcvfie	:1;		/*Receive FIFO not empty interrupt enable*/
   	}bit;
}tBFRIER;
  
#define XSYNIE	0x02	/*bit masks	*/
#define SLMMIE	0x08
#define SYNNIE	0x10
#define SYNAIE	0x20
#define RXIE	0x40
#define RCVFIE	0x80

typedef union uBFGIER
{
    tU08 byte;
    struct
  	{
  		tU08 wakeie	:1;		/*Wake up interrupt enable*/
  		tU08 lockie	:1;		/*Locking error interrupt enable*/
  		tU08 illpie :1;		/*Illegal pulse error interrupt enable*/
  		tU08 synlie	:1;		/*Sync pulse lost interrupt enable*/
  		tU08 syneie :1;		/*Sync pulse too early interrupt enable*/
  		tU08 errie	:1;		/*Message format error interrupt enable*/
  		tU08 ovrnie	:1;		/*Receive FIFO overrun interrupt enable*/
  		tU08 txie	:1;		/*Transmit interrupt enable*/
   	}bit;
}tBFGIER;
  
#define WAKEIE	0x01	/*bit masks	*/
#define LOCKIE	0x02
#define ILLPIE	0x04
#define SYNLIE	0x08
#define SYNEIE	0x10
#define ERRIE	0x20
#define OVRNIE	0x40
#define TXIE	0x80

typedef union uBFRIVEC
{
  	tU08 byte;
  	struct
  	{
  		tU08 rivec	:4;		/*Receive Vector bits*/
  		tU08 		:4;		/*not used*/
   	}bit;
}tBFRIVEC;
  
#define RIVEC0	0x01	/*bit masks	*/
#define RIVEC1	0x02
#define RIVEC2	0x04
#define RIVEC3	0x08

typedef union uBFTIVEC
{
    tU08 byte;
 	struct
  	{
  		tU08 tivec	:4;		/*Transmit Vector bits*/
  		tU08 		:4;		/*not used*/
   	}bit;
}tBFTIVEC;
  
#define TIVEC0	0x01	/*bit masks	*/
#define TIVEC1	0x02
#define TIVEC2	0x04
#define TIVEC3	0x08

typedef union uBFFIDAC
{
    tU08 byte;
  	struct
  	{
  		tU08 fidac	:8;		/*FIFO identification acceptance bits*/
   	}bit;
}tBFFIDAC;
  
#define FIDAC0	0x01	/*bit masks	*/
#define FIDAC1	0x02
#define FIDAC2	0x04
#define FIDAC3	0x08
#define FIDAC4	0x10
#define FIDAC5	0x20
#define FIDAC6	0x40
#define FIDAC7	0x80

typedef union uBFFIDMR
{
  	tU08 byte;
  	struct
  	{
  		tU08 fidmr	:8;		/*FIFO identification mask bits*/
   	}bit;
}tBFFIDMR;
  
#define FIDMR0	0x01	/*bit masks	*/
#define FIDMR1	0x02
#define FIDMR2	0x04
#define FIDMR3	0x08
#define FIDMR4	0x10
#define FIDMR5	0x20
#define FIDMR6	0x40
#define FIDMR7	0x80

typedef union uBFMVR
{
  	tU08 byte;
  	struct
  	{
  		tU08 mvr	:8;		/*Module Version Register bits*/
   	}bit;
}tBFMVR;
  
#define MVR0	0x01	/*bit masks	*/
#define MVR1	0x02
#define MVR2	0x04
#define MVR3	0x08
#define MVR4	0x10
#define MVR5	0x20
#define MVR6	0x40
#define MVR7	0x80

typedef union uBFPCTLBF
{
  	tU08 byte;
    struct
  	{
  		tU08 bfen	:1;		/*Byteflight enable*/
  		tU08 		:1;		/*not used*/
  		tU08 psynen	:1;		/*sync pulse ok enable*/
  		tU08 proken	:1;		/*reception ok enable*/
  		tU08 perren	:1;		/*error pulse enable*/
  		tU08 pslmen	:1;		/*slot mismatch enable*/
  		tU08 		:1;		/*not used*/
  		tU08 pmeren	:1;		/*slot mismatch error enable*/
   	}bit;
}tBFPCTLBF;
  
#define BFEN	0x01	/*bit masks	*/
#define PSYNEN	0x04
#define PROKEN	0x08
#define PERREN	0x10
#define PSLMEN	0x20
#define PMEREN	0x80

typedef union uBFBUFLOCK
{
  	tU08 byte;
  	struct
  	{
  		tU08 rxbuflock	:1;		/*RX buffer locked*/
  		tU08 txbuflock	:1;		/*TX buffer locked*/
  		tU08 		    :6;		/*not used*/
   	}bit;
}tBFBUFLOCK;
  
#define RXBUFLOCK	0x01	/*bit masks	*/
#define TXBUFLOCK	0x02

typedef union uBFFIDRJ
{
  	tU08 byte;
  	struct
  	{
  		tU08 fidrj	:8;		/*FIFO identification rejection bits*/
   	}bit;
}tBFFIDRJ;
  
#define FIDRJ0	0x01	/*bit masks	*/
#define FIDRJ1	0x02
#define FIDRJ2	0x04
#define FIDRJ3	0x08
#define FIDRJ4	0x10
#define FIDRJ5	0x20
#define FIDRJ6	0x40
#define FIDRJ7	0x80

typedef union uBFFIDRMR
{
  	tU08 byte;
 	struct
  	{
  		tU08 fidrmr	:8;		/*FIFO identification mask bits*/
   	}bit;
}tBFFIDRMR;
  
#define FIDRMR0	0x01	/*bit masks	*/
#define FIDRMR1	0x02
#define FIDRMR2	0x04
#define FIDRMR3	0x08
#define FIDRMR4	0x10
#define FIDRMR5	0x20
#define FIDRMR6	0x40
#define FIDRMR7	0x80

typedef union uBFTIDENT
{
  	tU08 byte;
  	struct
  	{
  		tU08 tident	:8;		/*Transmit buffer identification bits*/
   	}bit;
}tBFTIDENT;
  
#define TIDENT0	0x01	/*bit masks	*/
#define TIDENT1	0x02
#define TIDENT2	0x04
#define TIDENT3	0x08
#define TIDENT4	0x10
#define TIDENT5	0x20
#define TIDENT6	0x40
#define TIDENT7	0x80 

typedef union uBFTLEN
{
  	tU08 byte;
  	struct
  	{
  		tU08 tlen	:4;		/*Transmit data length bits*/
  		tU08		:4;		/*not used*/
   	}bit;
}tBFTLEN;
  
#define TLEN0	0x01	/*bit masks	*/
#define TLEN1	0x02
#define TLEN2	0x04
#define TLEN3	0x08

typedef union uBFTDATA0
{
  	tU08	byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA0;
  
#define TDATA0	0x01	/*bit masks	*/
#define TDATA1	0x02
#define TDATA2	0x04
#define TDATA3	0x08
#define TDATA4	0x10
#define TDATA5	0x20
#define TDATA6	0x40
#define TDATA7	0x80 

typedef union uBFTDATA1
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA1;
  
typedef union uBFTDATA2
{
  	tU08	byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA2;
 
typedef union uBFTDATA3
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA3;
  
typedef union uBFTDATA4
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA4;
  
typedef union uBFTDATA5
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA5;
  
typedef union uBFTDATA6
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA6;
  
typedef union uBFTDATA7
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA7;
  
typedef union uBFTDATA8
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA8;
  
typedef union uBFTDATA9
{
  	tU08 byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA9;
  
typedef union uBFTDATA10
{
  	tU08 byte;
 	 struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA10;
  
typedef union uBFTDATA11
{
 	tU08	byte;
  	struct
  	{
  		tU08 tdata	:8;		/*Transmit data bits*/
   	}bit;
}tBFTDATA11;
          
typedef union uBFRIDENT
{
  	tU08 byte;
  	struct
  	{
  		tU08 rident	:8;		/*Receive buffer identification bits*/
   	}bit;
}tBFRIDENT;
  
#define RIDENT0	0x01	/*bit masks	*/
#define RIDENT1	0x02
#define RIDENT2	0x04
#define RIDENT3	0x08
#define RIDENT4	0x10
#define RIDENT5	0x20
#define RIDENT6	0x40
#define RIDENT7	0x80 

typedef union uBFRLEN
{
  	tU08 byte;
  	struct
  	{
  		tU08 rlen	:4;		/*Receive data length bits*/
  		tU08		:4;		/*not used*/
   	}bit;
}tBFRLEN;
  
#define RLEN0	0x01	/*bit masks	*/
#define RLEN1	0x02
#define RLEN2	0x04
#define RLEN3	0x08

typedef union uBFRDATA0
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA0;
  
#define RDATA0	0x01	/*bit masks	*/
#define RDATA1	0x02
#define RDATA2	0x04
#define RDATA3	0x08
#define RDATA4	0x10
#define RDATA5	0x20
#define RDATA6	0x40
#define RDATA7	0x80 

typedef union uBFRDATA1
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA1;
  
typedef union uBFRDATA2
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA2;
 
typedef union uBFRDATA3
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA3;
  
typedef union uBFRDATA4
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA4;
  
typedef union uBFRDATA5
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA5;
  
typedef union uBFRDATA6
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA6;
  
typedef union uBFRDATA7
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA7;
  
typedef union uBFRDATA8
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA8;
  
typedef union uBFRDATA9
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA9;
  
typedef union uBFRDATA10
{
    tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA10;
  
typedef union uBFRDATA11
{
  	tU08 byte;
  	struct
  	{
  		tU08 rdata	:8;		/*Receive data bits*/
   	}bit;
}tBFRDATA11;
          
  
typedef union uBFFIDENT
{
  	tU08 byte;
  	struct
  	{
  		tU08 fident	:8;		/*Receive FIFO buffer identification bits*/
   	}bit;
}tBFFIDENT;
  
#define FIDENT0	0x01	/*bit masks	*/
#define FIDENT1	0x02
#define FIDENT2	0x04
#define FIDENT3	0x08
#define FIDENT4	0x10
#define FIDENT5	0x20
#define FIDENT6	0x40
#define FIDENT7	0x80 

typedef union uBFFLEN
{
  	tU08 byte;
  	struct
  	{
  		tU08 flen	:4;		/*Receive FIFO data length bits*/
  		tU08		:4;		/*not used*/
   	}bit;
}tBFFLEN;
  
#define FLEN0	0x01	/*bit masks	*/
#define FLEN1	0x02
#define FLEN2	0x04
#define FLEN3	0x08

typedef union uBFFDATA0
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA0;
  
#define FDATA0	0x01	/*bit masks	*/
#define FDATA1	0x02
#define FDATA2	0x04
#define FDATA3	0x08
#define FDATA4	0x10
#define FDATA5	0x20
#define FDATA6	0x40
#define FDATA7	0x80 

typedef union uBFFDATA1
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA1;
  
typedef union uBFFDATA2
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA2;
 
typedef union uBFFDATA3
{
  	tU08 byte;
 	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA3;
  
typedef union uBFFDATA4
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA4;
  
typedef union uBFFDATA5
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA5;
  
typedef union uBFFDATA6
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA6;
  
typedef union uBFFDATA7
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA7;
  
typedef union uBFFDATA8
{
  	tU08 byte;
 	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA8;
  
typedef union uBFFDATA9
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA9;
  
typedef union uBFFDATA10
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA10;
  
typedef union uBFFDATA11
{
  	tU08 byte;
  	struct
  	{
  		tU08 fdata	:8;		/*Receive FIFO data bits*/
   	}bit;
}tBFFDATA11;
          
typedef union uBFBUFCTL0
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL0;
  
#define CFG		0x01	/*bit masks	*/
#define ABTRQ	0x08
#define ABTAK	0x10
#define LCK		0x20
#define IENA	0x40
#define IFLG	0x80

typedef union uBFBUFCTL1
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL1;
  
typedef union uBFBUFCTL2
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL2;
  
typedef union uBFBUFCTL3
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL3;
  
typedef union uBFBUFCTL4
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL4;
  
typedef union uBFBUFCTL5
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL5;
  
typedef union uBFBUFCTL6
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL6;
  
typedef union uBFBUFCTL7
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL7;
  
typedef union uBFBUFCTL8
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL8;
  
typedef union uBFBUFCTL9
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL9;
  
typedef union uBFBUFCTL10
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL10;
  
typedef union uBFBUFCTL11
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL11;
  
typedef union uBFBUFCTL12
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL12;
  
typedef union uBFBUFCTL13
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL13;
  
typedef union uBFBUFCTL14
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL14;
  
typedef union uBFBUFCTL15
{
  	tU08 byte;
  	struct
  	{
  		tU08 cfg	:1;		/*message buffer configuration bit*/
  		tU08 		:2;		/*not used*/
  		tU08 abtrq	:1;		/*abort request*/
  		tU08 abtak	:1;		/*abort acknowledge*/
  		tU08 lock	:1;		/*message buffer lock*/
  		tU08 iena	:1;		/*interrupt enable bit*/
  		tU08 iflg	:1;		/*interrupt status flag*/
   	}bit;
}tBFBUFCTL15;
  
typedef struct
{
  volatile tBFMCR		bfmcr;		/*module configuration register*/
  volatile tBFFSIZR		bffsizr;	/*FIFO size register*/		                   
  volatile tBFTCR1		bftcr1;		/*Time Configuration Register 1*/		                   
  volatile tBFTCR2		bftcr2;		/*Time Configuration Register 2*/		                   
  volatile tBFTCR3		bftcr3;		/*Time Configuration Register 3*/		                   
  volatile tBFIDX		bfidx;		/*Fifo indexe register*/		                   
  volatile tBFRISR		bfrisr;		/*Receive interrupt status register*/		                   
  volatile tBFGISR		bfgisr;		/*General interrupt status register*/		                   
  volatile tBFRIER		bfrier;		/*Receive interrupt enable register*/		                   
  volatile tBFGIER		bfgier;		/*General interrupt enable register*/
  volatile tBFRIVEC		bfrivec;	/*Receive interrupt vector register*/		                   
  volatile tBFTIVEC 	bftivec;	/*Transmit interrupt vector register*/		                   
  volatile tBFFIDAC		bffidac;	/*Fifo identifier acceptance register*/		                   
  volatile tBFFIDMR		bffidmr;	/*Fifo identifier mask register*/		                   
  volatile tBFMVR		bfmvr;		/*module version register*/		   
  volatile tBFPCTLBF 	bfpctlbf;	/*byteflight port control register*/
  volatile tBFBUFLOCK	bfbuflock;  /*buffer lock register*/
  volatile tU08			rsv0;		/*reserved*/	                   
  volatile tBFFIDRJ		bffidrj;	/*Fifo identifier rejection register*/		                   
  volatile tBFFIDRMR 	bffidrmr;	/*Fifo identifier rejection maskr register*/
  volatile tU08			rsv1[10];	/*reserved*/		                   
  volatile tBFTIDENT 	bftident;	/*Transmit identifier register*/		                   
  volatile tBFTLEN		bftlen;		/*Transmit data length register*/		                   
  volatile tBFTDATA0	bftdata0;	/*Transmit data register 0*/		                   
  volatile tBFTDATA1	bftdata1;	/*Transmit data register 1*/		                   
  volatile tBFTDATA2	bftdata2;	/*Transmit data register 2*/		                   
  volatile tBFTDATA3	bftdata3;	/*Transmit data register 3*/		                   
  volatile tBFTDATA4	bftdata4;	/*Transmit data register 4*/		                   
  volatile tBFTDATA5	bftdata5;	/*Transmit data register 5*/		                   
  volatile tBFTDATA6	bftdata6;	/*Transmit data register 6*/		                   
  volatile tBFTDATA7	bftdata7;	/*Transmit data register 7*/		                   
  volatile tBFTDATA8	bftdata8;	/*Transmit data register 8*/		                   
  volatile tBFTDATA9	bftdata9;	/*Transmit data register 9*/		                   
  volatile tBFTDATA10	bftdata10;	/*Transmit data register 10*/		                   
  volatile tBFTDATA11	bftdata11;	/*Transmit data register 11*/		                   
  volatile tU08		    rsv2[2];	/*reserved*/		
  volatile tBFRIDENT	bfrident;	/*Receive identifier register*/		                   
  volatile tBFRLEN		bfrlen;		/*Receive data length register*/		                   
  volatile tBFRDATA0	bfrdata0;	/*Receive data register 0*/		                   
  volatile tBFRDATA1	bfrdata1;	/*Receive data register 1*/		                   
  volatile tBFRDATA2	bfrdata2;	/*Receive data register 2*/		                   
  volatile tBFRDATA3	bfrdata3;	/*Receive data register 3*/		                   
  volatile tBFRDATA4	bfrdata4;	/*Receive data register 4*/		                   
  volatile tBFRDATA5	bfrdata5;	/*Receive data register 5*/		                   
  volatile tBFRDATA6	bfrdata6;	/*Receive data register 6*/		                   
  volatile tBFRDATA7	bfrdata7;	/*Receive data register 7*/		                   
  volatile tBFRDATA8	bfrdata8;	/*Receive data register 8*/		                   
  volatile tBFRDATA9	bfrdata9;	/*Receive data register 9*/		                   
  volatile tBFRDATA10	bfrdata10;	/*Receive data register 10*/		                   
  volatile tBFRDATA11	bfrdata11;	/*Receive data register 11*/		                   
  volatile tU08			rsv3[2];	/*reserved*/	  
  volatile tBFFIDENT	bffident;	/*Receive Fifo identifier register*/		                   
  volatile tBFFLEN		bfflen;		/*Receive Fifo data length register*/		                   
  volatile tBFFDATA0	bffdata0;	/*Receive Fifo data register 0*/		                   
  volatile tBFFDATA1	bffdata1;	/*Receive Fifo data register 1*/		                   
  volatile tBFFDATA2	bffdata2;	/*Receive Fifo data register 2*/		                   
  volatile tBFFDATA3	bffdata3;	/*Receive Fifo data register 3*/		                   
  volatile tBFFDATA4	bffdata4;	/*Receive Fifo data register 4*/		                   
  volatile tBFFDATA5	bffdata5;	/*Receive Fifo data register 5*/		                   
  volatile tBFFDATA6	bffdata6;	/*Receive Fifo data register 6*/		                   
  volatile tBFFDATA7	bffdata7;	/*Receive Fifo data register 7*/		                   
  volatile tBFFDATA8	bffdata8;	/*Receive Fifo data register 8*/		                   
  volatile tBFFDATA9	bffdata9;	/*Receive Fifo data register 9*/		                   
  volatile tBFFDATA10	bffdata10;	/*Receive Fifo data register 10*/		                   
  volatile tBFFDATA11	bffdata11;	/*Receive Fifo data register 11*/		                   
  volatile tU08			rsv4[2];	/*reserved*/		
  volatile tBFBUFCTL0	bfbufctl0;	/*Message Buffer Control Register 0*/
  volatile tBFBUFCTL1	bfbufctl1;	/*Message Buffer Control Register 1*/
  volatile tBFBUFCTL2	bfbufctl2;	/*Message Buffer Control Register 2*/
  volatile tBFBUFCTL3	bfbufctl3;	/*Message Buffer Control Register 3*/ 
  volatile tBFBUFCTL4	bfbufctl4;	/*Message Buffer Control Register 4*/
  volatile tBFBUFCTL5	bfbufctl5;	/*Message Buffer Control Register 5*/
  volatile tBFBUFCTL6	bfbufctl6;	/*Message Buffer Control Register 6*/
  volatile tBFBUFCTL7	bfbufctl7;	/*Message Buffer Control Register 7*/ 
  volatile tBFBUFCTL8	bfbufctl8;	/*Message Buffer Control Register 8*/
  volatile tBFBUFCTL9	bfbufctl9;	/*Message Buffer Control Register 9*/
  volatile tBFBUFCTL10	bfbufctl10;	/*Message Buffer Control Register 10*/
  volatile tBFBUFCTL11	bfbufctl11;	/*Message Buffer Control Register 11*/ 
  volatile tBFBUFCTL12	bfbufctl12;	/*Message Buffer Control Register 12*/
  volatile tBFBUFCTL13	bfbufctl13;	/*Message Buffer Control Register 13*/
  volatile tBFBUFCTL14	bfbufctl14;	/*Message Buffer Control Register 14*/
  volatile tBFBUFCTL15	bfbufctl15;	/*Message Buffer Control Register 15*/ 
}tBF;     		                   
  	                   
          
#endif /*S12BFV1_H*/