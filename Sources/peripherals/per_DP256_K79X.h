#ifndef  per_DP256_K79X_H     		    
#define	 per_DP256_K79X_H  

/******************************************************************************
*                                                   COPYRIGHT (c) MOTOROLA 2003   
* FILE NAME: per_DP256_K79X.c                                             
*                                                                           
* PURPOSE: declaration of peripheral variables for an MC9S12DP256
*		   Mask Set: K79X							 
*                                                                           
* DESCRIPTION:  declarations of control register blocks for on-chip peripherals.        
*                                                                           
*                                                                           
* AUTHOR: r9aabe   LOCATION: Austin,TX      LAST EDIT DATE: 02/27/03  
*                                                                           
******************************************************************************/
/******************************************************************************
* Peripheral Versions for MCS12DP256 - Mask Set: K79X
* 
* Peripheral	Peripheral UG	  Version	Doc. Order #		Header File
* ----------	---------------   -------	---------------		---------------
* CORE			HCS12 V1.5 Core   V1.2		S12CPU15UG/D		S12CPU15V1_2.h
* CRG			CRG  			  V02		S12CRGV2/D			S12CRGV2.h
* TIMER			ECT_16B8C		  V01		S12ECT16B8CV1/D		S12ECT16B8CV1.h
* ATD			ATD_10B8C		  V02		S12ATD10B8CV2/D		S12ATD10B8CV2.h
* IIC			IIC				  V02		S12IICV2/D			S12IICV2.h
* SCI			SCI				  V02		S12SCIV2/D			S12SCIV2.h
* SPI			SPI	  			  V02		S12SPIV2/D			S12SPIV2.h
* PWM			PWM_8B8C		  V01		S12PWM8B8CV1/D		S12PWM8B8CV1.h
* FLASH			FTS256K			  V02		S12FTS256KV2/D		S12FTS256KV2.h
* EEPROM		EETS4K			  V02		S12EETS4KV2/D		S12EETS4KV2.h
* BDLC			BDLC			  V01		S12BDLCV1/D			S12BDLCV1.h
* MSCAN			MSCAN			  V02		S12MSCANV2/D		S12MSCANV2.h
* VREG			VREG			  V01		S12REGV1/D			--
* PIM			PIM_9DP256	   	  V02		S12PIMDP256V2/D		S12PIMDP256V2.h
*
******************************************************************************/ 				
			    
#ifndef REG_BASE
#define REG_BASE			0x0000
#endif

#include "S12ATD10B8CV2.h"			//ATD
#include "S12BDLCV1.h" 				//BDLC
#include "S12CPU15V1_2.h"			//CORE(PAGE/REG)
#include "S12CRGV2.h"				//CRG
#include "S12EETS4KV2.h"			//EEPROM
#include "S12FTS256KV2.h"			//FLASH
#include "S12IICV2.h"				//IIC
#include "MOTTYPES.h"				//TYPE DEFS
#include "S12MSCANV2.h"				//MSCAN
#include "S12DP256PIMV2.h"			//PIM
#include "S12PWM8B8CV1.h"			//PWM
#include "S12SCIV2.h"				//SCI
#include "S12SPIV2.h"				//SPI
#include "S12ECT16B8CV1.h"			//TIMER


extern  tREGISTER Regs 	@ (0x0000 + REG_BASE);
extern  tPAGE     Page  @ (0x0030 + REG_BASE);
extern  tCRG	  Crg  	@ (0x0034 + REG_BASE);
extern  tTIMER	  Tim0	@ (0x0040 + REG_BASE);
extern  tATD	  Atd0  @ (0x0080 + REG_BASE);
extern  tPWM	  Pwm	@ (0x00A0 + REG_BASE);
extern  tSCI      Sci0  @ (0x00C8 + REG_BASE);
extern  tSCI      Sci1  @ (0x00D0 + REG_BASE);
extern  tSPI      Spi0  @ (0x00D8 + REG_BASE);
extern  tIIC	  Iic	@ (0x00E0 + REG_BASE);
extern  tBDLC	  Bdlc  @ (0x00E8 + REG_BASE);
extern  tSPI      Spi1  @ (0x00F0 + REG_BASE);
extern  tSPI      Spi2  @ (0x00F8 + REG_BASE);
extern  tFLASH    Flash @ (0x0100 + REG_BASE);
extern  tEEPROM   Eeprom@ (0x0110 + REG_BASE);
extern  tATD	  Atd1  @ (0x0120 + REG_BASE);
extern  tMSCAN	  Can0	@ (0x0140 + REG_BASE);
extern  tMSCAN	  Can1	@ (0x0180 + REG_BASE);
extern  tMSCAN	  Can2	@ (0x01C0 + REG_BASE);
extern  tMSCAN	  Can3	@ (0x0200 + REG_BASE);
extern  tPIM	  Pim	@ (0x0240 + REG_BASE);
extern  tMSCAN	  Can4	@ (0x0280 + REG_BASE);

#endif	  //per_DP256_K79X_H
