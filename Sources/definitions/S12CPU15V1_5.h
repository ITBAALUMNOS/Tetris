/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12CPU15V1_5.h  	            								 */
/*                                                                           */
/* PURPOSE: header file for HCS12 register block					 		 */
/*                                                                           */
/*                                                                           */
/* DESCRIPTION:  standard definitions for HCS12 core registers block         */
/* Defines the external bus ports (A, B & E), system registers and bdm       */
/* registers as a datastructure of type tREGISTER.                           */
/* 																		     */
/* AUTHOR: r32151        LOCATION:EKB      LAST EDIT DATE: 25.07.01  		 */
/*                                                                           */
/*****************************************************************************/

/****	  

Filename : s12_page.h

Defines the paging (MEBI) register block as a datastructure

Written by R32151

****/		  


#ifndef S12CPU15V1_5_H      /*prevent duplicated includes */
#define S12CPU15V1_5_H

#ifndef MOTTYPES_H        /*prevent duplicated includes */
#include "MOTTYPES.h"
#endif


typedef union uPPAGE
  {
  tU08	byte;
  struct
    {
    tU08 pix	:6;		/*active page bits */
    tU08		:2;		/* not used */
    }bit;
  }tPPAGE;

#define PIX0	0x01	/*bit masks	*/
#define PIX1	0x02
#define PIX2	0x04
#define PIX3	0x08
#define PIX4	0x10
#define PIX5	0x20

typedef union uPORTK
  {
  tU08	byte;
  struct
    {
    tU08 ptk0	:1;		/*i/o port pins	*/
    tU08 ptk1	:1;
    tU08 ptk2	:1;
    tU08 ptk3	:1;
	tU08 ptk4	:1;
    tU08 ptk5	:1;
    tU08 ptk6	:1;
    tU08 ptk7	:1;
    }bit;
  }tPORTK;

#define PTK0	0x01	/*bit masks	*/
#define PTK1 	0x02
#define PTK2 	0x04
#define PTK3 	0x08
#define PTK4 	0x10
#define PTK5 	0x20
#define PTK6 	0x40
#define PTK7 	0x80

typedef union uDDRK
  {
  tU08	byte;
  struct
    {
    tU08 ddrk0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrk1	:1;
    tU08 ddrk2	:1;
    tU08 ddrk3	:1;
	tU08 ddrk4	:1;
    tU08 ddrk5	:1;
    tU08 ddrk6	:1;
    tU08 ddrk7	:1;
    }bit;
  }tDDRK;

#define DDRK0	0x01	/*bit masks	*/
#define DDRK1	0x02
#define DDRK2	0x04
#define DDRK3	0x08
#define DDRK4 	0x10
#define DDRK5 	0x20
#define DDRK6 	0x40
#define DDRK7	0x80


typedef struct				/*page module used on the Dx256	*/
  {
           tPPAGE	ppage;	/*program page index register */
           tU08		rsv;	/*reserved (maintaining memory map)	*/
           tPORTK	portk;	/*port K data register */
           tDDRK	ddrk;	/*port K data direction register */


  }tPAGE;
  
//End of Page Structures

typedef union uPORTA
  {
  tU08  byte;
  struct
    {
    tU08 pta0    :1;     /*i/o port pins */
    tU08 pta1    :1;
    tU08 pta2    :1;
    tU08 pta3    :1;
    tU08 pta4    :1;
    tU08 pta5    :1;
    tU08 pta6    :1;
    tU08 pta7    :1;
    }bit;
  }tPORTA;

#define PTA0     0x01    /*bit masks */
#define PTA1     0x02
#define PTA2     0x04
#define PTA3     0x08
#define PTA4     0x10
#define PTA5     0x20
#define PTA6     0x40
#define PTA7     0x80

typedef union uPORTB
  {
  tU08  byte;
  struct
    {
    tU08 ptb0    :1;     /*i/o port pins */
    tU08 ptb1    :1;
    tU08 ptb2    :1;
    tU08 ptb3    :1;
    tU08 ptb4    :1;
    tU08 ptb5    :1;
    tU08 ptb6    :1;
    tU08 ptb7    :1;
    }bit;
  }tPORTB;

#define PTB0     0x01    /*bit masks */
#define PTB1     0x02
#define PTB2     0x04
#define PTB3     0x08
#define PTB4     0x10
#define PTB5     0x20
#define PTB6     0x40
#define PTB7     0x80

typedef union uDDRA
  {
  tU08  byte;
  struct
    {
    tU08 ddra0   :1;     /*data direction bits (0:input;1:output) */
    tU08 ddra1   :1;
    tU08 ddra2   :1;
    tU08 ddra3   :1;
    tU08 ddra4   :1;
    tU08 ddra5   :1;
    tU08 ddra6   :1;
    tU08 ddra7   :1;
    }bit;
  }tDDRA;

#define DDRA0    0x01    /*bit masks */
#define DDRA1    0x02
#define DDRA2    0x04
#define DDRA3    0x08
#define DDRA4    0x10
#define DDRA5    0x20
#define DDRA6    0x40
#define DDRA7    0x80

typedef union uDDRB
  {
  tU08  byte;
  struct
    {
    tU08 ddrb0   :1;     /*data direction bits (0:input;1:output) */
    tU08 ddrb1   :1;
    tU08 ddrb2   :1;
    tU08 ddrb3   :1;
    tU08 ddrb4   :1;
    tU08 ddrb5   :1;
    tU08 ddrb6   :1;
    tU08 ddrb7   :1;
    }bit;
  }tDDRB;

#define DDRB0    0x01    /*bit masks */
#define DDRB1    0x02
#define DDRB2    0x04
#define DDRB3    0x08
#define DDRB4    0x10
#define DDRB5    0x20
#define DDRB6    0x40
#define DDRB7    0x80

typedef union uPORTE
  {
  tU08  byte;
  struct
    {
    tU08 pte0    :1;     /*i/o port pins */
    tU08 pte1    :1;
    tU08 pte2    :1;
    tU08 pte3    :1;
    tU08 pte4    :1;
    tU08 pte5    :1;
    tU08 pte6    :1;
    tU08 pte7    :1;
    }bit;
  }tPORTE;

#define PTE0     0x01    /*bit masks */
#define PTE1     0x02
#define PTE2     0x04
#define PTE3     0x08
#define PTE4     0x10
#define PTE5     0x20
#define PTE6     0x40
#define PTE7     0x80

typedef union uDDRE
  {
  tU08  byte;
  struct
    {
    tU08         :2;
    tU08 ddre2   :1;     /*data direction bits (0:input;1:output) */
    tU08 ddre3   :1;
    tU08 ddre4   :1;
    tU08 ddre5   :1;
    tU08 ddre6   :1;
    tU08 ddre7   :1;
    }bit;
  }tDDRE;

#define DDRE2    0x04    /*bit masks */
#define DDRE3    0x08
#define DDRE4    0x10
#define DDRE5    0x20
#define DDRE6    0x40
#define DDRE7    0x80

typedef union uPEAR
  {
  tU08  byte;
  struct
    {
    tU08        :2;     
    tU08 rdwe   :1;     /*read/write enable */
    tU08 lstre  :1;     /*low strobe enable */
    tU08 neclk  :1;     /*no external eclk */
    tU08 pipoe  :1;     /*pipe status signal output enable */
    tU08        :1;     
    tU08 noacce :1;     /*cpu no access output enable */
    }bit;
  }tPEAR;


#define RDWE    0x04    /*bit masks */
#define LSTRE   0x08
#define NECLK   0x10
#define PIPOE   0x20
#define NOACCE  0x80

typedef union uMODE
  { 
  tU08  byte;
  struct
    {
    tU08 eme    :1;     /*emulate port E */
    tU08 emk    :1;     /*emulate port K  */
    tU08        :1;     
    tU08 ivis   :1;     /*internal visibility */
    tU08        :1;     
    tU08 moda   :1;     /*mode select bits */
    tU08 modb   :1;
    tU08 modc   :1;
    }bit;
  }tMODE;

#define EME     0x01    /*bit masks */
#define EMK     0x02
#define IVIS    0x08
#define MODA    0x20
#define MODB    0x40
#define MODC    0x80


typedef union uPUCR
  {
  tU08  byte;
  struct
    {
    tU08 pupae  :1;     /*pull-up port A enable */
    tU08 pupbe  :1;     /*pull-up port B enable */
    tU08        :2;     
    tU08 pupee  :1;     /*pull-up port E enable */
    tU08        :2;     
    tU08 pupke  :1;     /*pull-up port K enable */
    }bit;
  }tPUCR;

#define PUPAE   0x01    /*bit mask */
#define PUPBE   0x02
#define PUPEE   0x10
#define PUPKE   0x40

typedef union uRDRIV
  {
  tU08  byte;
  struct
    {
    tU08 rdpa   :1;     /*reduced drive port A */
    tU08 rdpb   :1;     /*reduced drive port B */
    tU08        :2;     
    tU08 rdpe   :1;     /*reduced drive port E */
    tU08        :2;     
    tU08 rdpk   :1;     /*reduced drive port K */
    }bit;
  }tRDRIV;

#define RDPA    0x01    /*bit mask */
#define RDPB    0x02
#define RDPE    0x10
#define RDPK    0x80

typedef union uEBICTL
  {
  tU08  byte;
  struct
    {
    tU08 estr   :1;     /*e-clock free running or bus control signal */
    tU08        :7;     /*not used */
    }bit;
  }tEBICTL;

#define ESTR    0x01    /*bit mask */

typedef union uINITRM
  {
  tU08  byte;
  struct
    {
    tU08 ramhal :1;     /*RAM hi or low alignment within 16K page  */
    tU08        :2;     /*not used */
    tU08 ram    :5;     /*internal ram map position */
    }bit;               
  }tINITRM;

#define RAMHAL  0x01    /*bit masks */
#define RAM11   0x08    
#define RAM12   0x10
#define RAM13   0x20
#define RAM14   0x40
#define RAM15   0x80

typedef union uINITRG
  {
  tU08  byte;
  struct
    {
    tU08        :3;     /*not used */
    tU08 reg    :5;     /*internal register map position */
    }bit;
  }tINITRG;

    
#define REG11   0x08    /*bit masks */
#define REG12   0x10
#define REG13   0x20
#define REG14   0x40
#define REG15   0x80

typedef union uINITEE
  {
  tU08  byte;
  struct
    {
    tU08 eeon   :1;     /*internal eeprom on */
    tU08        :2;     /*not used */
    tU08 ee     :5;     /*internal eeprom map position */
    }bit;
  }tINITEE;

#define EEON    0x01    /*bit masks */
#define EE11    0x04
#define EE12    0x10
#define EE13    0x20
#define EE14    0x40
#define EE15    0x80

typedef union uMISC
  {
  tU08  byte;
  struct
    {
    tU08 romon  :1;     /*enable flash */
    tU08 romhm  :1;     /*flash only in second half of map */
    tU08 exstr  :2;     /*external access clock stretch */
    tU08        :4;     /*not used */
    }bit;
  }tMISC;

#define ROMON   0x01    /*bit masks */
#define ROMHM   0x02
#define EXSTR0  0x04
#define EXSTR1  0x08


typedef union uITCR
  {
  tU08  byte;
  struct
    {
    tU08 adr0   :1;     /*interrupt test control */
    tU08 adr1   :1;
    tU08 adr2   :1;
    tU08 adr3   :1;
    tU08 wrtint  :1;
    tU08        :3;     /*not used */
    }bit;
  }tITCR;

#define ADR0    0x01    /*bit masks */
#define ADR1    0x02
#define ADR2    0x04
#define ADR3    0x08
#define WRTINT  0x10
  
typedef union uITEST
  {
  tU08  byte;
  struct
    {
    tU08 int0   :1;     /*interrupt test register */
    tU08 int2   :1;
    tU08 int4   :1;
    tU08 int6   :1;
    tU08 int8   :1;
    tU08 inta   :1;
    tU08 intc   :1;
    tU08 inte   :1;
    }bit;
  }tITEST;

typedef union uVREGCTRL
  {
  tU08  byte;
  struct
    {
    tU08 lvif   :1;     
    tU08 lvie   :1;    
    tU08 lvds   :1;
    tU08 lvde   :1;
    tU08        :4;
    }bit;
  }tVREGCTRL;
 
#define LVIF    0x01    /*bit masks */
#define LVIE   0x02
#define LVDS     0x04
#define LVDE     0x08

typedef union uPARTID   /* bits 1:3 minor mask revs */
  {                     /* bits 4:7 major mask revs - inc fab x'fer */
  tU16  word;           /* bits 8:11 minor family id */
  struct                /* bits 12:15 major family id */
    {
    tU08 partidh;
    tU08 partidl;
    }byte;
  }tPARTID;


typedef union uMEMSIZ0
  {
  tU08  byte;
  struct
    {
    tU08 ram_sw :3;     
    tU08        :1;
    tU08 eep_sw :2;
    tU08        :1;
    tU08 reg_sw :1;
    }bit;
  }tMEMSIZ0;

#define RAM_SW0 0x01    /*bit masks */
#define RAM_SW1 0x02
#define RAM_SW2 0x04
#define EEP_SW0 0x10
#define EEP_SW1 0x20
#define REG_SW0 0x80

typedef union uMEMSIZ1
  {
  tU08  byte;
  struct
    {
    tU08 pag_sw :2;     
    tU08        :4;
    tU08 rom_sw :2;
    }bit;
  }tMEMSIZ1;

#define PAG_SW0 0x01    /*bit masks */
#define PAG_SW1 0x02
#define ROM_SW0 0x40
#define ROM_SW1 0x80


typedef union uIRQCR
  {
  tU08  byte;
  struct
    {
    tU08        :6;     /*not used */
    tU08 irqen  :1;     /*external irq enable */
    tU08 irqe   :1;     /*irq select edge sensitive only */
    }bit;
  }tIRQCR;


#define IRQEN   0x40    /*bit masks */
#define IRQE    0x80

typedef union uHPRIO
  {
  tU08  byte;
  struct
    {
    tU08        :1;     /*not used */
    tU08 psel1  :1;     /*highest priority interrupt select bits */
    tU08 psel2  :1;
    tU08 psel3  :1;
    tU08 psel4  :1;
    tU08 psel5  :1;
    tU08 psel6  :1;     
    tU08 psel7  :1;     
    }bit;
  }tHPRIO;

#define PSEL1   0x02    /*bit masks */
#define PSEL2   0x04
#define PSEL3   0x08
#define PSEL4   0x10
#define PSEL5   0x20
#define PSEL6   0x40
#define PSEL7   0x80

typedef union uDBGC1
  {
  tU08  byte;
  struct
    {
    tU08 capmod :2;     
    tU08 		:1;     
    tU08 dbgbrk :1;
    tU08 begin  :1;     
    tU08 trgsel :1;     
    tU08 arm    :1;
    tU08 dbgen  :1;
    }bit;
  }tDBGC1;

#define CAPMOD  0x03
#define DBGBRK  0x08
#define BEGIN   0x10
#define TRGSEL  0x20
#define ARM     0x40
#define DBGEN   0x80

typedef union uDBGSC
{
  tU08  byte;
  struct
    {
    tU08 trg    :4;     
    tU08 	    :1;
    tU08 cf		:1;
    tU08 bf		:1;
    tU08 af		:1;     
    }bit;
}tDBGSC;

#define TRG     0x0F    /*bit masks */
#define CF		0x20
#define BF      0x40
#define AF		0x80

typedef union uDBGC2
  {
  tU08  byte;
  struct
    {
    tU08 rwc    :1;     
    tU08 rwcen  :1;    
    tU08 tagc   :1;
    tU08 bkcen  :1;
    tU08 tagab  :1;
    tU08 bdm    :1;
    tU08 full   :1;
    tU08 bkaben :1;
    }bit;
  }tDBGC2;

#define RWC   	0x01    /*bit masks */
#define RWCEN   0x02
#define TAGC    0x04
#define BKCEN   0x08
#define TAGAB   0x10
#define BDM     0x20
#define FULL	0x40
#define BKABEN  0x80

typedef union uDBGC3
  {
  tU08  byte;
  struct
    {
    tU08 rwb    :1;     
    tU08 rwben  :1;    
    tU08 rwa    :1;
    tU08 rwaen  :1;
    tU08 bkbmb  :2;
    tU08 bkamb  :2;
    }bit;
  }tDBGC3;

#define RWB   	0x01    /*bit masks */
#define RWBEN   0x02
#define RWA     0x04
#define RWAEN   0x08
#define BKBMBL  0x10
#define BKBMBH  0x20
#define BKAMBL	0x40
#define BKAMBH  0x80

typedef union uDBGCAX 
  {
  tU08  byte;
  struct
    {
    tU08 extcmp :6;     
    tU08 pagsel :2;
    }bit;
  }tDBGCAX;

typedef union uDBGCBX 
  {
  tU08  byte;
  struct
    {
    tU08 extcmp :6;     
    tU08 pagsel :2;
    }bit;
  }tDBGCBX;

typedef union uDBGCCX 
  {
  tU08  byte;
  struct
    {
    tU08 extcmp :6;     
    tU08 pagsel :2;
    }bit;
  }tDBGCCX;

typedef union uDBGCNT 
  {
  tU08  byte;
  struct
    {
    tU08 cnt :6;     
    tU08     :1;
    tU08 tbf :1;
    }bit;
  }tDBGCNT;
  
#define TBF 0x80	 /*bit masks */

typedef union uDBGCCH
  {
  tU08	byte;
  struct
    {
    tU08 compch 	:8;		/*Comparator C address bits*/
    }bit;
  }tDBGCCH;
  
typedef union uDBGCCL
  {
  tU08	byte;
  struct
    {
    tU08 compcl 	:8;		/*Comparator C address bits*/
    }bit;
  }tDBGCCL;

typedef union uDBGCC
{
	tU16 word;
  	struct
    {
    	tDBGCCH	msb;
    	tDBGCCL	lsb;
    }byte;
}tDBGCC;

typedef union uDBGCAH
  {
  tU08	byte;
  struct
    {
    tU08 compah 	:8;		/*Comparator A address bits*/
    }bit;
  }tDBGCAH;
  
typedef union uDBGCAL
  {
  tU08	byte;
  struct
    {
    tU08 compal 	:8;		/*Comparator A address bits*/
    }bit;
  }tDBGCAL;

typedef union uDBGCA
{
	tU16 word;
  	struct
    {
    	tDBGCAH	msb;
    	tDBGCAL	lsb;
    }byte;
}tDBGCA;

typedef union uDBGCBH
  {
  tU08	byte;
  struct
    {
    tU08 compbh 	:8;		/*Comparator B address bits*/
    }bit;
  }tDBGCBH;
  
typedef union uDBGCBL
  {
  tU08	byte;
  struct
    {
    tU08 compbl 	:8;		/*Comparator B address bits*/
    }bit;
  }tDBGCBL;

typedef union uDBGCB
{
	tU16 word;
  	struct
    {
    	tDBGCBH	msb;
    	tDBGCBL	lsb;
    }byte;
}tDBGCB;

typedef union uDBGTBH
  {
  tU08	byte;
  struct
    {
    tU08 tbh 	:8;		/*Trace Buffer High*/
    }bit;
  }tDBGTBH;
  
typedef union uDBGTBL
  {
  tU08	byte;
  struct
    {
    tU08 tbl 	:8;		/*Trace Buffer Low*/
    }bit;
  }tDBGTBL;


typedef union uDBGTB
{
	tU16 word;
	struct
	{
		tDBGTBH msb;
		tDBGTBL lsb;
	}byte;
}tDBGTB;


typedef struct              /*port and internal resource control */
  {
  volatile tPORTA   	porta;  /*port A data register */
  volatile tPORTB   	portb;  /*port B data register */
  volatile tDDRA    	ddra;   /*port A data direction register */
  volatile tDDRB    	ddrb;   /*port B data direction register */
           tU08     	rsv1[4];/*reserved (maintaining memory map) */
  volatile tPORTE   	porte;  /*port E data register */
  volatile tDDRE    	ddre;   /*port E data direction register */
  volatile tPEAR    	pear;   /*port E assignment register */
  volatile tMODE    	mode;   /*mode register */
  volatile tPUCR    	pucr;   /*pull-up control register */
  volatile tRDRIV   	rdriv;  /*reduced drive register */
  volatile tEBICTL  	ebictl; /*external bus control */
           tU08     	rsv2;   /*reserved (maintaining memory map) */
  volatile tINITRM  	initrm; /*initialise internal ram position */
  volatile tINITRG  	initrg; /*initialise internal register position */
  volatile tINITEE  	initee; /*initialise internal eeprom position */
  volatile tMISC    	misc;   /*miscellaneous system control register */
           tU08     	rsv3;   /*reserved (maintaining memory map) */
  volatile tITCR    	itcr;   /*interrupt test control (?) */
  volatile tITEST   	itest;  /*interrupt test status (?) */
           tU08     	rsv4[2];/*reserved (maintaining memory map) */
  volatile tVREGCTRL 	vregctrl;/*vreg control register*/
  volatile tPARTID  	partid; /*word containing part id information */
  volatile tMEMSIZ0 	memsiz0;/* */
  volatile tMEMSIZ1 	memsiz1;/* */
  volatile tIRQCR   	irqcr;  /*interrupt control register */
  volatile tHPRIO   	hprio;  /*highest priority I interrupt */
  volatile tDBGC1   	dbgc1;	/*debug control register 1 */
  volatile tDBGSC		dbgsc;	/*debug control and status register */
  volatile tDBGTB  		dbgtb;  /*debug trace buffer high register */
  volatile tDBGCNT  	dbgcnt;	/*debug count register */
  volatile tDBGCCX  	dbgccx; /*debug comparator C expansion register */
  volatile tDBGCC   	dbgcc;  /*debug comparator C high register */
  volatile tDBGC2		dbgc2;	/*debug control register 2 */
  volatile tDBGC3		dbgc3;  /*debug control register 3 */
  volatile tDBGCAX		dbgcax; /*debug comparator A expansion register */
  volatile tDBGCA		dbgca;  /*debug comparator A high register */
  volatile tDBGCBX  	dbgcbx; /*debug comparator B expansion register */
  volatile tDBGCB   	dbgcb;  /*debug comparator B high register */
  }tREGISTER;

#endif /*S12CPU15V1_5_H  */
