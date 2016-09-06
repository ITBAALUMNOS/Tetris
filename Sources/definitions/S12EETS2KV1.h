/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12EETS2KV1.h                                          	     */
/*                                                                           */
/* PURPOSE: Header File for S12 EEPROM (2K)   					 		     */
/*                                                                           */
/* DESCRIPTION: Defines the EEPROM module register block as a          		 */
/* datastructure of type tEEPROM.                          					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB      								 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12EETS2KV1_H			/*prevent duplicated includes */
#define S12EETS2KV1_H

#ifndef MOTTYPES_H			/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uECLKDIV
  {
  tU08	byte;
  struct
    {
    tU08 ediv	:6;		/*clk divider */
    tU08 prdiv8	:1;		/*clk /8 prescaler enable */
    tU08 edivld	:1;		/*clock divider loaded flag */
    }bit;
  }tECLKDIV;

#define EDIV0	0x01	/*bit masks	*/
#define EDIV1   0x02
#define EDIV2   0x04
#define EDIV3   0x08
#define EDIV4   0x10
#define EDIV5   0x20
#define PRDIV8	0x40
#define EDIVLD	0x80

typedef union uECNFG
  {
  tU08	byte;
  struct
    {
    tU08		:6;		/*not used */
    tU08 ccie	:1;		/*command complete interrupt enable */
    tU08 cbeie	:1;		/*command buffer empty interrupt enable	*/
    }bit;
  }tECNFG;

#define CCIE	0x40	
#define CCBIE	0x80

typedef union uEPROT
  {
  tU08	byte;
  struct
    {
    tU08 ep			:3;		/*protection block size: (ep+1)*64 bytes */
    tU08 epdis		:1;		/*protection disable */
    tU08 			:3;		/*contain value of equivalent bits in protection byte */
    tU08 eopen		:1;		/*open block for program/erase */
    }bit;
  }tEPROT;

#define EP0		0x01	/*bit masks	*/
#define EP1		0x02
#define EP2		0x04	
#define EP		0x07	/*ep block mask */
#define EPDIS   0x08
#define EOPEN	0x80

typedef union uESTAT
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
  }tESTAT;

#define BLANK	0x04	/*bit masks	*/
#define ACCERR	0x10
#define PVIOL 	0x20
#define CCIF	0x40
#define CBEIF	0x80

typedef union uECMD
{
	tU08 byte;
	struct
	{
		tU08 cmdb0 :1;  
		tU08 	   :1;	/*not used*/
		tU08 cmdb2 :1;
		tU08 	   :2;	/*not used*/
		tU08 cmdb5 :1;			
		tU08 cmdb6 :1;
		tU08 	   :1;	/*not used*/
	}bit;
}tECMD;

#define CMDB0 	0x01      /*bit masks */
#define CMDB2 	0x04
#define CMDB5	0x20
#define CMDB6 	0x40
#define MASS 	0x01 
#define ERVER 	0x04
#define PROG	0x20
#define ERASE   0x40
#define ERASE_VERIFY	0x05 
#define WORD_PROGRAM	0x20
#define SECTOR_ERASE	0x40
#define MASS_ERASE 		0x41
#define SECTOR_MODIFY	0x60


typedef struct						/*eeprom datastructure */
  {
  volatile tECLKDIV		eclkdiv;	/*eeprom clock divider register */
		   tU08			rsv1[2];	/*reserved */
  volatile tECNFG		ecnfg;		/*eeprom configuration register */
  volatile tEPROT		eprot;		/*eeprom protection register */
  volatile tESTAT		estat;		/*eeprom status register */
  volatile tECMD		ecmd;		/*eeprom command buffer & status register */
           tU08			rsv2[5];	/*reserved */
  }tEEPROM;


#endif /*S12EETS2KV1_H */