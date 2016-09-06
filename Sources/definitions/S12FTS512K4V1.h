/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12FTS512K4V1.h                                          	     */
/*                                                                           */
/* PURPOSE: Header File for S12 FLASH (512K)   					 		     */
/*                                                                           */
/* DESCRIPTION: Defines the FLASH module register block as a          		 */
/* datastructure of type tFLASH.                          					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB   		   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12FTS512K4V1_H			/*prevent duplicated includes */
#define S12FTS512K4V1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uFCLKDIV
  {
  tU08	byte;
  struct
    {
    tU08 fdiv	:6;		/*clk divider */
    tU08 prdiv8	:1;		/*clk /8 prescaler enable */
    tU08 fdivld	:1;		/*clock divider loaded flag */
    }bit;
  }tFCLKDIV;

#define FDIV	0x3F	/*bit masks	*/
#define PRDIV8	0x40
#define FDIVLD	0x80

typedef union uFSEC
  {
  tU08	byte;
  struct
    {
    tU08 sec	:2;		/*memory security bit */
    tU08 nv		:4;		/*user non volatile flag bits */
    tU08 keyen	:2;		/*security key access enable */
    }bit;
  }tFSEC;

#define SEC0	0x01	/*bit masks	*/
#define SEC1	0x02
#define SEC		0x03
#define NV2		0x04
#define NV3		0x08
#define NV4		0x10
#define NV5 	0x20
#define NV		0x3C
#define KEYEN0	0x40
#define KEYEN1	0x80

typedef union uFTSTMOD
  {
  tU08	byte;
  struct
    {
    tU08 		:4;		/*unused */
    tU08 wrall	:1;		/*write to all register banks */
    tU08 		:3;		/*unused */
    }bit;
  }tFTSTMOD;

#define WRALL	0x10	/*bit masks	*/

typedef union uFCNFG
  {
  tU08	byte;
  struct
    {
    tU08 bksel	:2;		/*register bank select */
    tU08		:3;		/*not used */
    tU08 keyacc	:1;		/*security key writing enable */
    tU08 ccie	:1;		/*command complete interrupt enable */
    tU08 cbeie	:1;		/*command buffer empty interrupt enable	*/
    }bit;
  }tFCNFG;

#define BKSEL0	0x01	/*bit masks	*/
#define BKSEL1	0x02
#define BKSEL	0x03	/*bank select mask */
#define KEYACC	0x20	
#define CCIE	0x40	
#define CCBIE	0x80

typedef union uFPROT
  {
  tU08	byte;
  struct
    {
    tU08 fpls		:2;		/*flash protection lower address size */
    tU08 fpldis		:1;		/*flash protection lower address range disable */
    tU08 fphs		:2;		/*flash protection higher address size */
    tU08 fphdis		:1;		/*flash protection higher address range disable */
    tU08 nv6		:1;		/*contains value of equivalent bit in protection byte */
    tU08 fpopen		:1;		/*open block for program/erase control */
    }bit;
  }tFPROT;

#define FPLS0		0x01	/*bit masks	*/
#define FPLS1		0x02
#define FPLS		0x03	/*fpls block size mask */
#define FPLDIS		0x04	
#define FPHS0		0x08	
#define FPHS1		0x10
#define FPHS		0x18	/*fphs block size mask */
#define FPHDIS		0x20	
#define NV6 		0x40 
#define FPOPEN		0x80

typedef union uFSTAT
  {
  tU08	byte;
  struct
    {
    tU08 		:2;		/*not used */
    tU08 blank	:1;		/*blank verify flag */
    tU08 		:1;		/*not used */
    tU08 accerr	:1;		/*access error flag */
    tU08 pviol	:1;		/*protection violation flag */
    tU08 ccif	:1;		/*command complete interrupt flag */
    tU08 cbeif	:1;		/*command buffer empty interrupt flag */
    }bit;
  }tFSTAT;

#define BLANK	0x04	/*bit masks	*/
#define ACCERR	0x10
#define PVIOL 	0x20
#define CCIF	0x40
#define CBEIF	0x80

typedef union uFCMD
  {
  tU08	byte;
  struct
    {
    tU08 cmdb0	:1;		
	tU08 		:1;		/*not used */
    tU08 cmdb2	:1;		
	tU08 		:2;		/*not used */
    tU08 cmdb5	:1;		
    tU08 cmdb6	:1;		
	tU08 		:1;		/*not used */
    }bit;
  }tFCMD;

#define CMDB0	0x01	/*bit masks	*/
#define CMDB2	0x04
#define CMDB5	0x20
#define CMDB6	0x40
#define MASS	0x01	
#define ERVER	0x04
#define PROG	0x20
#define ERASE	0x40
#define ERASE_VERIFY	0x05 
#define BYTE_PROGRAM	0x20
#define SECTOR_ERASE	0x40
#define MASS_ERASE 		0x41

typedef struct						/*flash datastructure */
  {
  volatile tFCLKDIV		fclkdiv;	/*flash clock divider register */
  volatile tFSEC		fsec;		/*flash security register */
  volatile tFTSTMOD		ftstmod;	/*flash test mode register */
  volatile tFCNFG		fcnfg;		/*flash configuration register */
  volatile tFPROT		fprot;		/*flash protection register */
  volatile tFSTAT		fstat;		/*flash status register */
  volatile tFCMD		fcmd;		/*flash command buffer & status register */
  		   tU08			rsv1[9];	/*reserved */
  }tFLASH;


#endif /*S12FTS512K4V1_H */