/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12CPU15V1_2.h  	            								 */
/*                                                                           */
/* PURPOSE: header file for HCS12 register block					 		 */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB      LAST EDIT DATE: 05.22.03         */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

/****	  

Filename : s12_page.h

Defines the paging (MEBI) register block as a datastructure

PAGE datastructure base address (out of reset) -

MCSDP256	  : 0x0030


The datastructure used is determined by the #define's MCSDP256, MCSxxx, etc. 
These definitions can be found in "s12_common.h".

Written by (R32151)

Revision history -

5/5/00	- Initial coding based on HC12 page.h by Ross McLuckie
10/5/00 - Changed #include "s12_common.h" to #include "s12_common.h"
		- changed bit/mask names on Port K consistant with PIM ports

****/		  


#ifndef S12CPU15V1_2_H      /*prevent duplicated includes */
#define S12CPU15V1_2_H

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
    tU08        :3;     /*not used */
    tU08 ee     :4;     /*internal eeprom map position */
    }bit;
  }tINITEE;

#define EEON    0x01    /*bit masks */
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


typedef union uMTST     /*memory test registers  */
  {
  tU08  byte;
  struct
    {
    tU08 bit    :8;     
    }bit;
  }tMTST;

typedef union uITCR
  {
  tU08  byte;
  struct
    {
    tU08 adr0   :1;     /*interrupt test control */
    tU08 adr1   :1;
    tU08 adr2   :1;
    tU08 adr3   :1;
    tU08 wrint  :1;
    tU08        :3;     /*not used */
    }bit;
  }tITCR;

#define ADR0    0x01    /*bit masks */
#define ADR1    0x02
#define ADR2    0x04
#define ADR3    0x08
#define WRINT   0x10
  
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

typedef union uBKPCT0
  {
  tU08  byte;
  struct
    {
    tU08        :4;     /*not used */
    tU08 bktag  :1;     
    tU08 bkbdm  :1;
    tU08 bkfull :1;     
    tU08 bken   :1;     /*breakpoint mode enable */
    }bit;
  }tBKPCT0;

#define BKTAG   0x10
#define BKBDM   0x20
#define BKFULL  0x40
#define BKEN    0x80

typedef union uBKPCT1
  {
  tU08  byte;
  struct
    {
    tU08 bk1rw  :1;     /* */
    tU08 bk1rwe :1;     /* */
    tU08 bk0rw  :1;     /* */
    tU08 bk0rwe :1;     /* */
    tU08 bk1mbl :1;     /* */
    tU08 bk1mbh :1;     /* */
    tU08 bk0mbl :1;     /* */
    tU08 bk0mbh :1;     /* */
    }bit;
  }tBKPCT1;

#define BK1RW   0x01    /*bit masks */
#define BK1RWE  0x02
#define BK0RW   0x04
#define BK0RWE  0x08
#define BK1MBL  0x10
#define BK1MBH  0x20
#define BK0Mbl  0x40
#define BK0MBH  0x80

typedef union uBKP0X
  {
  tU08  byte;
  struct
    {
    tU08 bk0v   :6;     /* */
    tU08        :2;     /*not used */

    }bit;
  }tBKP0X;

#define BK0V0   0x01    /*bit masks */
#define BK0V1   0x02
#define BK0V2   0x04
#define BK0V3   0x08
#define BK0V4   0x10
#define BK0V5   0x20

typedef union uBKP0
  {
  tU16  word;
  struct
    {
    tU08 high;
    tU08 low;
    }byte;
  }tBKP0;

typedef union uBKP1X
  {
  tU08  byte;
  struct
    {
    tU08 bk1v   :6;     /* */
    tU08        :2;     /*not used */

    }bit;
  }tBKP1X;

#define BK1V0   0x01    /*bit masks */
#define BK1V1   0x02
#define BK1V2   0x04
#define BK1V3   0x08
#define BK1V4   0x10
#define BK1V5   0x20

typedef union uBKP1
  {
  tU16  word;
  struct
    {
    tU08 high;
    tU08 low;
    }byte;
  }tBKP1;



typedef struct              /*port and internal resource control */
  {
  volatile tPORTA   porta;  /*port A data register */
  volatile tPORTB   portb;  /*port B data register */
  volatile tDDRA    ddra;   /*port A data direction register */
  volatile tDDRB    ddrb;   /*port B data direction register */
           tU08     rsv1[4];/*reserved (maintaining memory map) */
  volatile tPORTE   porte;  /*port E data register */
  volatile tDDRE    ddre;   /*port E data direction register */
  volatile tPEAR    pear;   /*port E assignment register */
  volatile tMODE    mode;   /*mode register */
  volatile tPUCR    pucr;   /*pull-up control register */
  volatile tRDRIV   rdriv;  /*reduced drive register */
  volatile tEBICTL  ebictl; /*external bus control */
           tU08     rsv2;   /*reserved (maintaining memory map) */
  volatile tINITRM  initrm; /*initialise internal ram position */
  volatile tINITRG  initrg; /*initialise internal register position */
  volatile tINITEE  initee; /*initialise internal eeprom position */
  volatile tMISC    misc;   /*miscellaneous system control register */
  volatile tMTST    mtst0;  /*memory test */
  volatile tITCR    itcr;   /*interrupt test control */
  volatile tITEST   itest;  /*interrupt test status */
  volatile tMTST    mtst1;  /*memory test */
           tU08     rsv3[2]; /*reserved (maintaining memory map) */
  volatile tPARTID  partid;  /*word containing part id information */
  volatile tMEMSIZ0 memsiz0; /* */
  volatile tMEMSIZ1 memsiz1; /* */
  volatile tIRQCR   irqcr;  /*interrupt control register */
  volatile tHPRIO   hprio;  /*highest priority I interrupt */
           tU08     rsv4[8];/*reserved (maintaining memory map) */
  volatile tBKPCT0  bkpct0; /*breakpoint control register 0 */
  volatile tBKPCT1  bkpct1; /*breakpoint control register 1 */
  volatile tBKP0X   bkp0x;  /* */
  volatile tBKP0    bkp0;   /*breakpoint address registers */
  volatile tBKP1X   bkp1x;  /* */
  volatile tBKP1    bkp1;   /*breakpoint data registers */

  }tREGISTER;

#endif /*S12CPU15V1_2_H  */
