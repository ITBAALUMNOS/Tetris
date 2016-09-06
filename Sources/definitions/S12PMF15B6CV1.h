/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12PMF15B6CV1.h                                      	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 PMF								 		     */
/*                                                                           */
/* DESCRIPTION: Defines the PMF module register block as a          		 */
/* datastructure of type tPMF.                          					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r9aabe	       LOCATION: Austin, TX	   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12PMF15B6CV1_H           /*prevent duplicated includes */
#define S12PMF15B6CV1_H

#ifndef MOTTYPES_H        /*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uPMFCFG0
  {
  tU08  byte;
  struct
    {
    tU08 indepa :1;     /*independent or complimentary operation (pair A) */
    tU08 indepb :1;		/*independent or complimentary operation (pair B) */
    tU08 indepc :1;		/*independent or complimentary operation (pair C) */
    tU08 edgea  :1;		/*edge-aligned or center-aligned operation (pair A) */
    tU08 edgeb  :1;     /*edge-aligned or center-aligned operation (pair B) */
    tU08 edgec  :1;		/*edge-aligned or center-aligned operation (pair C) */
    tU08 mtg	:1;		/*multiple timebase generators */
    tU08 wp     :1;		/*write protect */
    }bit;
  }tPMFCFG0;

#define INDEPA   0x01    /*bit masks */
#define INDEPB   0x02
#define INDEPC   0x04
#define EDGEA    0x08
#define EDGEB    0x10
#define EDGEC  	 0x20
#define MTG  	 0x40
#define WP	     0x80

typedef union uPMFCFG1
  {
  tU08  byte;
  struct
    {
    tU08 topnega  :1;   /*pair A top-side polarity */
    tU08 botnega  :1;	/*pair A bottom-side polarity */
    tU08 topnegb  :1;	/*pair B top-side polarity */
    tU08 botnegb  :1;	/*pair B bottom-side polarity */
    tU08 topnegc  :1;   /*pair C top-side polarity */  
    tU08 botnegc  :1;	/*pair C bottom-side polarity */
    tU08 		  :1;
    tU08 enha	  :1;	/*enable hardware acceleration */
    }bit;
  }tPMFCFG1;

#define TOPNEGA   0x01    /*bit masks */
#define BOTNEGA   0x02
#define TOPNEGB   0x04
#define BOTNEGB   0x08
#define TOPNEGC   0x10
#define BOTNEGC   0x20
#define ENHA	  0x80

typedef union uPMFCFG2
  {
  tU08  byte;
  struct
    {
    tU08 msk0  :1;   /*mask PWMx */
    tU08 msk1  :1;	
    tU08 msk2  :1;	
    tU08 msk3  :1;	
    tU08 msk4  :1;   
    tU08 msk5  :1;	
    tU08 	   :2;
    }bit;
  }tPMFCFG2;

#define MSK0   0x01    /*bit masks */
#define MSK1   0x02
#define MSK2   0x04
#define MSK3   0x08
#define MSK4   0x10
#define MSK5   0x20

typedef union uPMFCFG3
  {
  tU08  byte;
  struct
    {
    tU08 swapa  :1;     /* swap pair a */
    tU08 swapb  :1;		/* swap pair b */
    tU08 swapc  :1;		/* swap pair c */
    tU08 vlmode :2;		/*value register load mode */
    tU08		:1;
    tU08 pmffrz :1;		/*pmf stops while in FREEZE mode */
    tU08 pmfwai :1;		/*pmf stops while in WAIT mode */
    }bit;
  }tPMFCFG3;

#define SWAPA   0x01    /*bit masks */
#define SWAPB   0x02
#define SWAPC   0x04
#define VLMODE  0x18
#define PMFFRZ  0x40
#define PMFWAI  0x80


typedef union uPMFFCTL
  {
  tU08  byte;
  struct
    {
    tU08 fie0   :1;		/*fault 0 pin interrupt enable */     
    tU08 fmode0	:1;		/*fault 0 pin clearing mode */
    tU08 fie1   :1;     /*fault 1 pin interrupt enable */                               
    tU08 fmode1 :1;     /*fault 1 pin clearing mode */
    tU08 fie2   :1;     /*fault 2 pin interrupt enable */         
    tU08 fmode2 :1;     /*fault 2 pin clearing mode */
    tU08 fie3   :1;     /*fault 3 pin interrupt enable */
    tU08 fmode3 :1;     /*fault 3 pin clearing mode */                            
    }bit;
  }tPMFFCTL;

#define FIE0   	0x01    /*bit masks */
#define FMODE0  0x02
#define FIE1    0x04
#define FMODE1  0x08    
#define FIE2    0x10
#define FMODE2  0x20
#define FIE3    0x40    
#define FMODE3  0x80    


typedef union uPMFFPIN
  {
  tU08  byte;
  struct
    {
    tU08 fpine0   :1;     /*fault X pin acknowledge */
    tU08 		  :1;
    tU08 fpine1   :1;
    tU08 	      :1;
    tU08 fpine2   :1;     
    tU08 	      :1;
    tU08 fpine3   :1;
    tU08 	      :1;
    }bit;
  }tPMFFPIN;

#define FPIN0    0x01    /*bit masks */
#define FPIN1    0x04
#define FPIN2    0x10
#define FPIN3    0x40

typedef union uPMFFSTA
  {
  tU08  byte;
  struct
    {
    tU08 fflag0   :1;     /*fault x pin flag */
    tU08 		  :1;
    tU08 fflag1   :1;
    tU08 	      :1;
    tU08 fflag2   :1;     
    tU08 	      :1;
    tU08 fflag3   :1;
    tU08 	      :1;
    }bit;
  }tPMFFSTA;

#define FFLAG0    0x01    /*bit masks */
#define FFLAG1    0x04
#define FFLAG2    0x10
#define FFLAG3    0x40

typedef union uPMFQSMP
  { 
  tU08  byte;
  struct
    {
    tU08 qsmp0  :2;     /*fault 0 qualifying samples */
    tU08 qsmp1  :2;     /*fault 1 qualifying samples */
    tU08 qsmp2  :2;     /*fault 2 qualifying samples */
    tU08 qsmp3  :2;     /*fault 3 qualifying samples */
    }bit;
  }tPMFQSMP;

#define QSMP0   0x03    /*bit masks */
#define QSMP1   0x0C
#define QSMP2   0x30
#define QSMP3   0xC0

typedef union uPMFDMPA
  {
  tU08  byte;
  struct
    {
    tU08 dmp00   :1;     
    tU08 dmp01   :1;     
    tU08 dmp02   :1;     
    tU08 dmp03   :1;     
    tU08 dmp10   :1;     
    tU08 dmp11   :1;    
    tU08 dmp12   :1;     
    tU08 dmp13   :1;     
    }bit;
  }tPMFDMPA;

#define DMP00      0x01    /*bit masks */
#define DMP01      0x02
#define DMP02      0x04
#define DMP03	   0x08
#define DMP10      0x10
#define DMP11      0x20
#define DMP12      0x40
#define DMP13      0x80

typedef union uPMFDMPB
  {
  tU08  byte;
  struct
    {
    tU08 dmp20   :1;     
    tU08 dmp21   :1;     
    tU08 dmp22   :1;     
    tU08 dmp23   :1;     
    tU08 dmp30   :1;     
    tU08 dmp31   :1;    
    tU08 dmp32   :1;     
    tU08 dmp33   :1;     
    }bit;
  }tPMFDMPB;

#define DMP20      0x01    /*bit masks */
#define DMP21      0x02
#define DMP22      0x04
#define DMP23	   0x08
#define DMP30      0x10
#define DMP31      0x20
#define DMP32      0x40
#define DMP33      0x80

typedef union uPMFDMPC
  {
  tU08  byte;
  struct
    {
    tU08 dmp40   :1;     
    tU08 dmp41   :1;     
    tU08 dmp42   :1;     
    tU08 dmp43   :1;     
    tU08 dmp50   :1;     
    tU08 dmp51   :1;    
    tU08 dmp52   :1;     
    tU08 dmp53   :1;     
    }bit;
  }tPMFDMPC;

#define DMP40      0x01    /*bit masks */
#define DMP41      0x02
#define DMP42      0x04
#define DMP43	   0x08
#define DMP50      0x10
#define DMP51      0x20
#define DMP52      0x40
#define DMP53      0x80

typedef union uPMFOUTC
  {
  tU08  byte;
  struct
    {
    tU08 outctl0 :1;		/*software control enables*/     
    tU08 outctl1 :1;     
    tU08 outctl2 :1;     
    tU08 outctl3 :1;     
    tU08 outctl4 :1;     
    tU08 outctl5 :1;    
    tU08 		 :2;     
    }bit;
  }tPMFOUTC;

#define OUTCTL0    0x01    /*bit masks */
#define OUTCTL1    0x02
#define OUTCTL2    0x04
#define OUTCTL3	   0x08
#define OUTCTL4    0x10
#define OUTCTL5    0x20

typedef union uPMFOUTB
  {
  tU08  byte;
  struct
    {
    tU08 out0 :1;		/*output controls */     
    tU08 out1 :1;     
    tU08 out2 :1;     
    tU08 out3 :1;     
    tU08 out4 :1;     
    tU08 out5 :1;    
    tU08 	  :2;     
    }bit;
  }tPMFOUTB;

#define OUT0    0x01    /*bit masks */
#define OUT1    0x02
#define OUT2    0x04
#define OUT3	0x08
#define OUT4    0x10
#define OUT5    0x20

typedef union uPMFDTMS
  {
  tU08  byte;
  struct
    {
    tU08 dt0	 :1;		/*dead time sample register*/     
    tU08 dt1	 :1;     
    tU08 dt2	 :1;     
    tU08 dt3     :1;     
    tU08 dt4     :1;     	
    tU08 dt5	 :1;
    tU08 		 :2;     
    }bit;
  }tPMFDTMS;

#define DT0		 0x01    /*bit masks */
#define DT1      0x02
#define DT2      0x04
#define DT3      0x08
#define DT4      0x10
#define DT5      0x20

typedef union uPMFCCTL
  {
  tU08  byte;
  struct
    {
    tU08 ipola   :1;		/*current polarities*/     
    tU08 ipolb	 :1;     
    tU08 ipolc   :1;     
    tU08         :1;     
    tU08 isens   :2;     	/*current status sensing method */
    tU08 		 :2;     
    }bit;
  }tPMFCCTL;

#define IPOLA    0x01    /*bit masks */
#define IPOLB    0x02
#define IPOLC    0x04
#define ISENS    0x30

typedef union uPMFENCA
  {
  tU08  byte;
  struct
    {
    tU08 pwmriea :1;		/*pwm reload interrupt enable A */     
    tU08 ldoka   :1;        /*load okay A */
    tU08 		 :5;     
    tU08 pwmena  :1;   		/*pwm generator A enable */  
    }bit;
  }tPMFENCA;

#define PWMRIEA    0x01    /*bit masks */
#define LDOKA      0x02
#define PWMENA     0x80

typedef union uPMFFQCA
  {
  tU08  byte;
  struct
    {
    tU08 pwmrfa  :1;		/*pwm reload flag A */     
    tU08 prsca   :2;        /*prescalar A */
    tU08 halfa   :1;     	/*half cycle reload A */
    tU08 ldfqa   :4;   		/*load frequency A */  
    }bit;
  }tPMFFQCA;

#define PWMRFA    0x01    /*bit masks */
#define PRSCA     0x06
#define HALFA     0x04
#define LDFQA     0xF0

typedef union uPMFENCB
  {
  tU08  byte;
  struct
    {
    tU08 pwmrieb :1;		/*pwm reload interrupt enable B */     
    tU08 ldokb   :1;        /*load okay B */
    tU08 		 :5;     
    tU08 pwmenb  :1;   		/*pwm generator B enable */  
    }bit;
  }tPMFENCB;

#define PWMRIEB    0x01    /*bit masks */
#define LDOKB      0x02
#define PWMENB     0x80

typedef union uPMFFQCB
  {
  tU08  byte;
  struct
    {
    tU08 pwmrfb  :1;		/*pwm reload flag B */     
    tU08 prscb   :2;        /*prescalar B */
    tU08 halfb   :1;     	/*half cycle reload B */
    tU08 ldfqb   :4;   		/*load frequency B */  
    }bit;
  }tPMFFQCB;

#define PWMRFB    0x01    /*bit masks */
#define PRSCB     0x06
#define HALFB     0x04
#define LDFQB     0xF0

typedef union uPMFENCC
  {
  tU08  byte;
  struct
    {
    tU08 pwmriec :1;		/*pwm reload interrupt enable C */     
    tU08 ldokc   :1;        /*load okay C */
    tU08 		 :5;     
    tU08 pwmenc  :1;   		/*pwm generator C enable */  
    }bit;
  }tPMFENCC;

#define PWMRIEC    0x01    /*bit masks */
#define LDOKC      0x02
#define PWMENC     0x80

typedef union uPMFFQCC
  {
  tU08  byte;
  struct
    {
    tU08 pwmrfc  :1;		/*pwm reload flag C*/     
    tU08 prscc   :2;        /*prescalar C */
    tU08 halfc   :1;     	/*half cycle reload C */
    tU08 ldfqc   :4;   		/*load frequency C */  
    }bit;
  }tPMFFQCC;

#define PWMRFC    0x01    /*bit masks */
#define PRSCC     0x06
#define HALFC     0x04
#define LDFQC     0xF0

typedef struct                  
  {
  volatile tPMFCFG0  pmfcfg0;     /*pmf configure 0 register */
  volatile tPMFCFG1  pmfcfg1;     /*pmf configure 1 register  */
  volatile tPMFCFG2  pmfcfg2;     /*pmf configure 2 register */
  volatile tPMFCFG3  pmfcfg3;     /*pmf configure 3 register */
  volatile tPMFFCTL  pmffctl;     /*pmf fault control register */
  volatile tPMFFPIN  pmffpin;     /*pmf fault acknowledge register */
  volatile tPMFFSTA  pmffsta;     /*pmf fault status register */
  volatile tPMFQSMP  pmfqsmp;     /*pmf fault qualifying samples register */
  volatile tPMFDMPA  pmfdmpa;     /*pmf disable mapping A register */
  volatile tPMFDMPB  pmfdmpb;     /*pmf disable mapping B register */
  volatile tPMFDMPC  pmfdmpc;     /*pmf disable mapping C register */
           tU08      rsv;		  /*reserved */
  volatile tPMFOUTC  pmfoutc;  	  /*pmf output control register */
  volatile tPMFOUTB  pmfoutb;  	  /*pmf output control bit register */
  volatile tPMFDTMS  pmfdtms; 	  /*pmf deadtime sample register */
  volatile tPMFCCTL  pmfcctl;  	  /*pmf correction control register */
  volatile tREG16    pmfval[6];   /*pmf value registers */
           tU16      rsvt[2];	  /*reserved */
  volatile tPMFENCA  pmfenca;	  /*pmf enable control A register */
  volatile tPMFFQCA  pmffqca;     /*pmf frequency control A register */
  volatile tREG16    pmfcnta;  	  /*pmf counter A register */
  volatile tREG16	 pmfmoda;     /*pmf counter modulo A register */
  volatile tREG16    pmfdtma;     /*pmf deadline A register */
  volatile tPMFENCB  pmfencb;	  /*pmf enable control B register */
  volatile tPMFFQCB  pmffqcb;     /*pmf frequency control B register */
  volatile tREG16    pmfcntb;  	  /*pmf counter B register */
  volatile tREG16	 pmfmodb;     /*pmf counter modulo B register */
  volatile tREG16    pmfdtmb;     /*pmf deadline B register */
  volatile tPMFENCC  pmfencc;	  /*pmf enable control C register */
  volatile tPMFFQCC  pmffqcc;     /*pmf frequency control C register */
  volatile tREG16    pmfcntc;  	  /*pmf counter C register */
  volatile tREG16	 pmfmodc;     /*pmf counter modulo C register */
  volatile tREG16    pmfdtmc;     /*pmf deadline C register */
           tU16      rsv2[4];	  /*reserved */
  
  }tPMF;
#endif /*S12PMF15B6CV1_H */
