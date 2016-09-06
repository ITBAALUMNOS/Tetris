/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12E128PIMV1.h		                                         */
/*                                                                           */
/* PURPOSE: header file for HCS12 PIM block     					 		 */
/*                                                                           */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin,TX      LAST EDIT DATE: 08.18.03   */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef S12E128PIMV1_H			/*prevent duplicated includes */
#define S12E128PIMV1_H

#ifndef MOTTYPES_H		/*prevent duplicated includes */
#include "MOTTYPES.h"
#endif


/******************************  PORT T  *************************/

typedef union uPTT		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptt0	:1;		/*i/o port pins */
    tU08 ptt1	:1;
    tU08 ptt2	:1;
    tU08 ptt3	:1;
    tU08 ptt4	:1;
    tU08 ptt5	:1;
    tU08 ptt6	:1;
    tU08 ptt7	:1;
    }bit;
  }tPTT;

#define PTT0	0x01	/*bit masks */
#define PTT1	0x02
#define PTT2 	0x04
#define PTT3 	0x08
#define PTT4 	0x10
#define PTT5 	0x20
#define PTT6 	0x40
#define PTT7 	0x80

typedef union uPTIT		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptit0	:1;		/*i/o port pins */
    tU08 ptit1	:1;
    tU08 ptit2	:1;
    tU08 ptit3	:1;
    tU08 ptit4	:1;
    tU08 ptit5	:1;
    tU08 ptit6	:1;
    tU08 ptit7	:1;
    }bit;
  }tPTIT;

#define PTIT0	0x01	/*bit masks */
#define PTIT1	0x02
#define PTIT2 	0x04
#define PTIT3 	0x08
#define PTIT4 	0x10
#define PTIT5 	0x20
#define PTIT6 	0x40
#define PTIT7 	0x80

typedef union uDDRT		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrt0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrt1	:1;
    tU08 ddrt2	:1;
    tU08 ddrt3	:1;
    tU08 ddrt4	:1;
    tU08 ddrt5	:1;
    tU08 ddrt6	:1;
    tU08 ddrt7	:1;
    }bit;
  }tDDRT;

#define DDRT0	0x01	/*bit masks */
#define DDRT1	0x02
#define DDRT2	0x04
#define DDRT3	0x08
#define DDRT4	0x10
#define DDRT5	0x20
#define DDRT6	0x40
#define DDRT7	0x80

typedef union uRDRT		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrt0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrt1	:1;
    tU08 rdrt2	:1;
    tU08 rdrt3	:1;
    tU08 rdrt4	:1;
    tU08 rdrt5	:1;
    tU08 rdrt6	:1;
    tU08 rdrt7	:1;
    }bit;
  }tRDRT;

#define RDRT0	0x01	/*bit masks */
#define RDRT1	0x02
#define RDRT2	0x04
#define RDRT3	0x08
#define RDRT4	0x10
#define RDRT5	0x20
#define RDRT6	0x40
#define RDRT7	0x80

typedef union uPERT		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 pert0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 pert1	:1;
    tU08 pert2	:1;
    tU08 pert3	:1;
    tU08 pert4	:1;
    tU08 pert5	:1;
    tU08 pert6	:1;
    tU08 pert7	:1;
    }bit;
  }tPERT;

#define PERT0	0x01	/*bit masks */
#define PERT1	0x02
#define PERT2 	0x04
#define PERT3 	0x08
#define PERT4 	0x10
#define PERT5 	0x20
#define PERT6 	0x40
#define PERT7 	0x80

typedef union uPPST		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppst0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppst1	:1;
    tU08 ppst2	:1;
    tU08 ppst3	:1;
    tU08 ppst4	:1;
    tU08 ppst5	:1;
    tU08 ppst6	:1;
    tU08 ppst7	:1;
    }bit;
  }tPPST;

#define PPST0	0x01	/*bit masks */
#define PPST1	0x02
#define PPST2 	0x04
#define PPST3 	0x08
#define PPST4 	0x10
#define PPST5 	0x20
#define PPST6 	0x40
#define PPST7 	0x80


/******************************  PORT S  **************************/

typedef union uPTS		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 pts0	:1;		/*i/o port pins */
    tU08 pts1	:1;
    tU08 pts2	:1;
    tU08 pts3	:1;
    tU08 pts4	:1;
    tU08 pts5	:1;
    tU08 pts6	:1;
    tU08 pts7	:1;
    }bit;
  }tPTS;

#define PTS0	0x01	/*bit masks */
#define PTS1	0x02
#define PTS2 	0x04
#define PTS3 	0x08
#define PTS4 	0x10
#define PTS5 	0x20
#define PTS6 	0x40
#define PTS7 	0x80

typedef union uPTIS		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptis0	:1;		/*i/o port pins */
    tU08 ptis1	:1;
    tU08 ptis2	:1;
    tU08 ptis3	:1;
    tU08 ptis4	:1;
    tU08 ptis5	:1;
    tU08 ptis6	:1;
    tU08 ptis7	:1;
    }bit;
  }tPTIS;

#define PTIS0	0x01	/*bit masks */
#define PTIS1	0x02
#define PTIS2 	0x04
#define PTIS3 	0x08
#define PTIS4 	0x10
#define PTIS5 	0x20
#define PTIS6 	0x40
#define PTIS7 	0x80

typedef union uDDRS		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrs0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrs1	:1;
    tU08 ddrs2	:1;
    tU08 ddrs3	:1;
    tU08 ddrs4	:1;
    tU08 ddrs5	:1;
    tU08 ddrs6	:1;
    tU08 ddrs7	:1;
    }bit;
  }tDDRS;

#define DDRS0	0x01	/*bit masks */
#define DDRS1	0x02
#define DDRS2	0x04
#define DDRS3	0x08
#define DDRS4	0x10
#define DDRS5	0x20
#define DDRS6	0x40
#define DDRS7	0x80

typedef union uRDRS		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrs0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrs1	:1;
    tU08 rdrs2	:1;
    tU08 rdrs3	:1;
    tU08 rdrs4	:1;
    tU08 rdrs5	:1;
    tU08 rdrs6	:1;
    tU08 rdrs7	:1;
    }bit;
  }tRDRS;

#define RDRS0	0x01	/*bit masks */
#define RDRS1	0x02
#define RDRS2	0x04
#define RDRS3	0x08
#define RDRS4	0x10
#define RDRS5	0x20
#define RDRS6	0x40
#define RDRS7	0x80

typedef union uPERS		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 pers0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 pers1	:1;
    tU08 pers2	:1;
    tU08 pers3	:1;
    tU08 pers4	:1;
    tU08 pers5	:1;
    tU08 pers6	:1;
    tU08 pers7	:1;
    }bit;
  }tPERS;

#define PERS0	0x01	/*bit masks */
#define PERS1	0x02
#define PERS2 	0x04
#define PERS3 	0x08
#define PERS4 	0x10
#define PERS5 	0x20
#define PERS6 	0x40
#define PERS7 	0x80

typedef union uPPSS		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppss0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppss1	:1;
    tU08 ppss2	:1;
    tU08 ppss3	:1;
    tU08 ppss4	:1;
    tU08 ppss5	:1;
    tU08 ppss6	:1;
    tU08 ppss7	:1;
    }bit;
  }tPPSS;

#define PPSS0	0x01	/*bit masks */
#define PPSS1	0x02
#define PPSS2 	0x04
#define PPSS3 	0x08
#define PPSS4 	0x10
#define PPSS5 	0x20
#define PPSS6 	0x40
#define PPSS7 	0x80

typedef union uWOMS		/*wired-or mode register */
  {
  tU08	byte;
  struct
    {
    tU08 woms0	:1;		/*wired-or bits (1:enabled) */
    tU08 woms1	:1;
    tU08 woms2	:1;
    tU08 woms3	:1;
    tU08 woms4	:1;
    tU08 woms5	:1;
    tU08 woms6	:1;
    tU08 woms7	:1;
    }bit;
  }tWOMS;

#define WOMS0	0x01	/*bit masks */
#define WOMS1	0x02
#define WOMS2 	0x04
#define WOMS3 	0x08
#define WOMS4 	0x10
#define WOMS5 	0x20
#define WOMS6 	0x40
#define WOMS7 	0x80


/******************************  PORT M  **************************/

typedef union uPTM		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptm0	:1;		/*i/o port pins */
    tU08 ptm1	:1;
    tU08 ptm2	:1;
    tU08 ptm3	:1;
    tU08 ptm4	:1;
    tU08 ptm5	:1;
    tU08 ptm6	:1;
    tU08 ptm7	:1;
    }bit;
  }tPTM;

#define PTM0	0x01	/*bit masks */
#define PTM1	0x02
#define PTM2 	0x04
#define PTM3 	0x08
#define PTM4 	0x10
#define PTM5 	0x20
#define PTM6 	0x40
#define PTM7 	0x80

typedef union uPTIM		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptim0	:1;		/*i/o port pins */
    tU08 ptim1	:1;
    tU08 ptim2	:1;
    tU08 ptim3	:1;
    tU08 ptim4	:1;
    tU08 ptim5	:1;
    tU08 ptim6	:1;
    tU08 ptim7	:1;
    }bit;
  }tPTIM;

#define PTIM0	0x01	/*bit masks */
#define PTIM1	0x02
#define PTIM2 	0x04
#define PTIM3 	0x08
#define PTIM4 	0x10
#define PTIM5 	0x20
#define PTIM6 	0x40
#define PTIM7 	0x80

typedef union uDDRM		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrm0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrm1	:1;
    tU08 ddrm2	:1;
    tU08 ddrm3	:1;
    tU08 ddrm4	:1;
    tU08 ddrm5	:1;
    tU08 ddrm6	:1;
    tU08 ddrm7	:1;
    }bit;
  }tDDRM;

#define DDRM0	0x01	/*bit masks */
#define DDRM1	0x02
#define DDRM2	0x04
#define DDRM3	0x08
#define DDRM4	0x10
#define DDRM5	0x20
#define DDRM6	0x40
#define DDRM7	0x80

typedef union uRDRM		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrm0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrm1	:1;
    tU08 rdrm2	:1;
    tU08 rdrm3	:1;
    tU08 rdrm4	:1;
    tU08 rdrm5	:1;
    tU08 rdrm6	:1;
    tU08 rdrm7	:1;
    }bit;
  }tRDRM;

#define RDRM0	0x01	/*bit masks */
#define RDRM1	0x02
#define RDRM2	0x04
#define RDRM3	0x08
#define RDRM4	0x10
#define RDRM5	0x20
#define RDRM6	0x40
#define RDRM7	0x80

typedef union uPERM		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perm0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perm1	:1;
    tU08 perm2	:1;
    tU08 perm3	:1;
    tU08 perm4	:1;
    tU08 perm5	:1;
    tU08 perm6	:1;
    tU08 perm7	:1;
    }bit;
  }tPERM;

#define PERM0	0x01	/*bit masks */
#define PERM1	0x02
#define PERM2 	0x04
#define PERM3 	0x08
#define PERM4 	0x10
#define PERM5 	0x20
#define PERM6 	0x40
#define PERM7 	0x80

typedef union uPPSM		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsm0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsm1	:1;
    tU08 ppsm2	:1;
    tU08 ppsm3	:1;
    tU08 ppsm4	:1;
    tU08 ppsm5	:1;
    tU08 ppsm6	:1;
    tU08 ppsm7	:1;
    }bit;
  }tPPSM;

#define PPSM0	0x01	/*bit masks */
#define PPSM1	0x02
#define PPSM2 	0x04
#define PPSM3 	0x08
#define PPSM4 	0x10
#define PPSM5 	0x20
#define PPSM6 	0x40
#define PPSM7 	0x80

typedef union uWOMM		/*wired-or mode register */
  {
  tU08	byte;
  struct
    {
    tU08 womm0	:1;		/*wired-or bits (1:enabled) */
    tU08 womm1	:1;
    tU08 womm2	:1;
    tU08 womm3	:1;
    tU08 womm4	:1;
    tU08 womm5	:1;
    tU08 womm6	:1;
    tU08 womm7	:1;
    }bit;
  }tWOMM;

#define WOMM0	0x01	/*bit masks */
#define WOMM1	0x02
#define WOMM2 	0x04
#define WOMM3 	0x08
#define WOMM4 	0x10
#define WOMM5 	0x20
#define WOMM6 	0x40
#define WOMM7 	0x80


/******************** Module Routing Register MODRR ***************/

typedef union uMODRR
  {
  tU08 byte;
  struct
    {
    tU08 modrr0 :1;  /*PWM/TIM2 */
    tU08 modrr1 :1;  /*PWM/TIM2 */
    tU08 modrr2 :1;  /*PWM/TIM2 */
    tU08 modrr3 :1;  /*PWM/TIM2 */
    tU08        :4;  /*not used */
    }bit;
  }tMODRR;
 
#define MODRR0 0x01 /*bit masks */
#define MODRR1 0x02
#define MODRR2 0x04
#define MODRR3 0x08

/******************************  PORT P  **************************/

typedef union uPTP		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptp0	:1;		/*i/o port pins */
    tU08 ptp1	:1;
    tU08 ptp2	:1;
    tU08 ptp3	:1;
    tU08 ptp4	:1;
    tU08 ptp5	:1;
    tU08 ptp6	:1;
    tU08 ptp7	:1;
    }bit;
  }tPTP;

#define PTP0	0x01	/*bit masks */
#define PTP1	0x02
#define PTP2 	0x04
#define PTP3 	0x08
#define PTP4 	0x10
#define PTP5 	0x20
#define PTP6 	0x40
#define PTP7 	0x80

typedef union uPTIP		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptip0	:1;		/*i/o port pins */
    tU08 ptip1	:1;
    tU08 ptip2	:1;
    tU08 ptip3	:1;
    tU08 ptip4	:1;
    tU08 ptip5	:1;
    tU08 ptip6	:1;
    tU08 ptip7	:1;
    }bit;
  }tPTIP;

#define PTIP0	0x01	/*bit masks */
#define PTIP1	0x02
#define PTIP2 	0x04
#define PTIP3 	0x08
#define PTIP4 	0x10
#define PTIP5 	0x20
#define PTIP6 	0x40
#define PTIP7 	0x80

typedef union uDDRP		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrp0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrp1	:1;
    tU08 ddrp2	:1;
    tU08 ddrp3	:1;
    tU08 ddrp4	:1;
    tU08 ddrp5	:1;
    tU08 ddrp6	:1;
    tU08 ddrp7	:1;
    }bit;
  }tDDRP;

#define DDRP0	0x01	/*bit masks */
#define DDRP1	0x02
#define DDRP2	0x04
#define DDRP3	0x08
#define DDRP4	0x10
#define DDRP5	0x20
#define DDRP6	0x40
#define DDRP7	0x80

typedef union uRDRP		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrp0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrp1	:1;
    tU08 rdrp2	:1;
    tU08 rdrp3	:1;
    tU08 rdrp4	:1;
    tU08 rdrp5	:1;
    tU08 rdrp6	:1;
    tU08 rdrp7	:1;
    }bit;
  }tRDRP;

#define RDRP0	0x01	/*bit masks */
#define RDRP1	0x02
#define RDRP2	0x04
#define RDRP3	0x08
#define RDRP4	0x10
#define RDRP5	0x20
#define RDRP6	0x40
#define RDRP7	0x80

typedef union uPERP		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perp0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perp1	:1;
    tU08 perp2	:1;
    tU08 perp3	:1;
    tU08 perp4	:1;
    tU08 perp5	:1;
    tU08 perp6	:1;
    tU08 perp7	:1;
    }bit;
  }tPERP;

#define PERP0	0x01	/*bit masks */
#define PERP1	0x02
#define PERP2 	0x04
#define PERP3 	0x08
#define PERP4 	0x10
#define PERP5 	0x20
#define PERP6 	0x40
#define PERP7 	0x80

typedef union uPPSP		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsp0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsp1	:1;
    tU08 ppsp2	:1;
    tU08 ppsp3	:1;
    tU08 ppsp4	:1;
    tU08 ppsp5	:1;
    tU08 ppsp6	:1;
    tU08 ppsp7	:1;
    }bit;
  }tPPSP;

#define PPSP0	0x01	/*bit masks */
#define PPSP1	0x02
#define PPSP2 	0x04
#define PPSP3 	0x08
#define PPSP4 	0x10
#define PPSP5 	0x20
#define PPSP6 	0x40
#define PPSP7 	0x80


/******************************  PORT Q  **************************/

typedef union uPTQ		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptq0	:1;		/*i/o port pins */
    tU08 ptq1	:1;
    tU08 ptq2	:1;
    tU08 ptq3	:1;
    tU08 ptq4	:1;
    tU08 ptq5	:1;
    tU08 ptq6	:1;
    tU08 ptq7	:1;
    }bit;
  }tPTQ;

#define PTQ0	0x01	/*bit masks */
#define PTQ1	0x02
#define PTQ2 	0x04
#define PTQ3 	0x08
#define PTQ4 	0x10
#define PTQ5 	0x20
#define PTQ6 	0x40
#define PTQ7 	0x80

typedef union uPTIQ		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptiq0	:1;		/*i/o port pins */
    tU08 ptiq1	:1;
    tU08 ptiq2	:1;
    tU08 ptiq3	:1;
    tU08 ptiq4	:1;
    tU08 ptiq5	:1;
    tU08 ptiq6	:1;
    tU08 ptiq7	:1;
    }bit;
  }tPTIQ;

#define PTIQ0	0x01	/*bit masks */
#define PTIQ1	0x02
#define PTIQ2 	0x04
#define PTIQ3 	0x08
#define PTIQ4 	0x10
#define PTIQ5 	0x20
#define PTIQ6 	0x40
#define PTIQ7 	0x80

typedef union uDDRQ		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrq0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrq1	:1;
    tU08 ddrq2	:1;
    tU08 ddrq3	:1;
    tU08 ddrq4	:1;
    tU08 ddrq5	:1;
    tU08 ddrq6	:1;
    tU08 ddrq7	:1;
    }bit;
  }tDDRQ;

#define DDRQ0	0x01	/*bit masks */
#define DDRQ1	0x02
#define DDRQ2	0x04
#define DDRQ3	0x08
#define DDRQ4	0x10
#define DDRQ5	0x20
#define DDRQ6	0x40
#define DDRQ7	0x80

typedef union uRDRQ		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrq0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrq1	:1;
    tU08 rdrq2	:1;
    tU08 rdrq3	:1;
    tU08 rdrq4	:1;
    tU08 rdrq5	:1;
    tU08 rdrq6	:1;
    tU08 rdrq7	:1;
    }bit;
  }tRDRQ;

#define RDRQ0	0x01	/*bit masks */
#define RDRQ1	0x02
#define RDRQ2	0x04
#define RDRQ3	0x08
#define RDRQ4	0x10
#define RDRQ5	0x20
#define RDRQ6	0x40
#define RDRQ7	0x80

typedef union uPERQ		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perq0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perq1	:1;
    tU08 perq2	:1;
    tU08 perq3	:1;
    tU08 perq4	:1;
    tU08 perq5	:1;
    tU08 perq6	:1;
    tU08 perq7	:1;
    }bit;
  }tPERQ;

#define PERQ0	0x01	/*bit masks */
#define PERQ1	0x02
#define PERQ2 	0x04
#define PERQ3 	0x08
#define PERQ4 	0x10
#define PERQ5 	0x20
#define PERQ6 	0x40
#define PERQ7 	0x80

typedef union uPPSQ		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsq0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsq1	:1;
    tU08 ppsq2	:1;
    tU08 ppsq3	:1;
    tU08 ppsq4	:1;
    tU08 ppsq5	:1;
    tU08 ppsq6	:1;
    tU08 ppsq7	:1;
    }bit;
  }tPPSQ;

#define PPSQ0	0x01	/*bit masks */
#define PPSQ1	0x02
#define PPSQ2 	0x04
#define PPSQ3 	0x08
#define PPSQ4 	0x10
#define PPSQ5 	0x20
#define PPSQ6 	0x40
#define PPSQ7 	0x80


/******************************  PORT U  **************************/

typedef union uPTU		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptu0	:1;		/*i/o port pins */
    tU08 ptu1	:1;
    tU08 ptu2	:1;
    tU08 ptu3	:1;
    tU08 ptu4	:1;
    tU08 ptu5	:1;
    tU08 ptu6	:1;
    tU08 ptu7	:1;
    }bit;
  }tPTU;

#define PTU0	0x01	/*bit masks */
#define PTU1	0x02
#define PTU2 	0x04
#define PTU3 	0x08
#define PTU4 	0x10
#define PTU5 	0x20
#define PTU6 	0x40
#define PTU7 	0x80

typedef union uPTIU		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptiu0	:1;		/*i/o port pins */
    tU08 ptiu1	:1;
    tU08 ptiu2	:1;
    tU08 ptiu3	:1;
    tU08 ptiu4	:1;
    tU08 ptiu5	:1;
    tU08 ptiu6	:1;
    tU08 ptiu7	:1;
    }bit;
  }tPTIU;

#define PTIU0	0x01	/*bit masks */
#define PTIU1	0x02
#define PTIU2 	0x04
#define PTIU3 	0x08
#define PTIU4 	0x10
#define PTIU5 	0x20
#define PTIU6 	0x40
#define PTIU7 	0x80

typedef union uDDRU		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddru0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddru1	:1;
    tU08 ddru2	:1;
    tU08 ddru3	:1;
    tU08 ddru4	:1;
    tU08 ddru5	:1;
    tU08 ddru6	:1;
    tU08 ddru7	:1;
    }bit;
  }tDDRU;

#define DDRU0	0x01	/*bit masks */
#define DDRU1	0x02
#define DDRU2	0x04
#define DDRU3	0x08
#define DDRU4	0x10
#define DDRU5	0x20
#define DDRU6	0x40
#define DDRU7	0x80

typedef union uRDRU		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdru0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdru1	:1;
    tU08 rdru2	:1;
    tU08 rdru3	:1;
    tU08 rdru4	:1;
    tU08 rdru5	:1;
    tU08 rdru6	:1;
    tU08 rdru7	:1;
    }bit;
  }tRDRU;

#define RDRU0	0x01	/*bit masks */
#define RDRU1	0x02
#define RDRU2	0x04
#define RDRU3	0x08
#define RDRU4	0x10
#define RDRU5	0x20
#define RDRU6	0x40
#define RDRU7	0x80

typedef union uPERU		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 peru0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 peru1	:1;
    tU08 peru2	:1;
    tU08 peru3	:1;
    tU08 peru4	:1;
    tU08 peru5	:1;
    tU08 peru6	:1;
    tU08 peru7	:1;
    }bit;
  }tPERU;

#define PERU0	0x01	/*bit masks */
#define PERU1	0x02
#define PERU2 	0x04
#define PERU3 	0x08
#define PERU4 	0x10
#define PERU5 	0x20
#define PERU6 	0x40
#define PERU7 	0x80

typedef union uPPSU		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsu0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsu1	:1;
    tU08 ppsu2	:1;
    tU08 ppsu3	:1;
    tU08 ppsu4	:1;
    tU08 ppsu5	:1;
    tU08 ppsu6	:1;
    tU08 ppsu7	:1;
    }bit;
  }tPPSU;

#define PPSU0	0x01	/*bit masks */
#define PPSU1	0x02
#define PPSU2 	0x04
#define PPSU3 	0x08
#define PPSU4 	0x10
#define PPSU5 	0x20
#define PPSU6 	0x40
#define PPSU7 	0x80


/******************************  PORT AD  **************************/


typedef union uPTADH		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptad8	:1;		/*i/o port pins */
    tU08 ptad9	:1;
    tU08 ptad10	:1;
    tU08 ptad11	:1;
    tU08 ptad12	:1;
    tU08 ptad13	:1;
    tU08 ptad14	:1;
    tU08 ptad15	:1;
    }bit;
  }tPTADH;
  
#define PTAD8	0x01	/*bit masks */
#define PTAD9	0x02
#define PTAD10	0x04
#define PTAD11  0x08
#define PTAD12  0x10
#define PTAD13  0x20
#define PTAD14	0x40
#define PTAD15	0x80
  
typedef union uPTADL		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptad0	:1;		/*i/o port pins */
    tU08 ptad1	:1;
    tU08 ptad2	:1;
    tU08 ptad3	:1;
    tU08 ptad4	:1;
    tU08 ptad5	:1;
    tU08 ptad6	:1;
    tU08 ptad7	:1;
    }bit;
  }tPTADL;
  
#define PTAD0	0x01	/*bit masks */
#define PTAD1	0x02
#define PTAD2	0x04
#define PTAD3   0x08
#define PTAD4   0x10
#define PTAD5   0x20
#define PTAD6	0x40
#define PTAD7	0x80
  
typedef union uPTAD		/*i/o register */
  {
  tU16  word;
  struct
    {
    tPTADH msb;
    tPTADL lsb;
    }bit;
  }tPTAD;  

typedef union uPTIADH		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptiad8	:1;		/*i/o port pins */
    tU08 ptiad9	:1;
    tU08 ptiad10:1;
    tU08 ptiad11:1;
    tU08 ptiad12:1;
    tU08 ptiad13:1;
    tU08 ptiad14:1;
    tU08 ptiad15:1;
    }bit;
  }tPTIADH;

#define PTIAD8	0x01	/*bit masks */
#define PTIAD9	0x02
#define PTIAD10	0x04
#define PTIAD11 0x08
#define PTIAD12 0x10
#define PTIAD13 0x20
#define PTIAD14	0x40
#define PTIAD15	0x80

typedef union uPTIADL		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptiad0	:1;		/*i/o port pins */
    tU08 ptiad1	:1;
    tU08 ptiad2	:1;
    tU08 ptiad3	:1;
    tU08 ptiad4	:1;
    tU08 ptiad5	:1;
    tU08 ptiad6	:1;
    tU08 ptiad7	:1;
    }bit;
  }tPTIADL;
  
#define PTIAD0	0x01	/*bit masks */
#define PTIAD1	0x02
#define PTIAD2 	0x04
#define PTIAD3 	0x08
#define PTIAD4 	0x10
#define PTIAD5 	0x20
#define PTIAD6 	0x40
#define PTIAD7 	0x80
  
  typedef union uPTIAD		/*input register */
  {
  tU16	word;
  struct
    {
    tPTIADH msb;
    tPTIADL lsb;
    }byte;
  }tPTIAD;

typedef union uDDRADH		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrad8	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrad9	:1;
    tU08 ddrad10:1;
    tU08 ddrad11:1;
    tU08 ddrad12:1;
    tU08 ddrad13:1;
    tU08 ddrad14:1;
    tU08 ddrad15:1;
    }bit;
  }tDDRADH;

#define DDRAD8	0x01	/*bit masks */
#define DDRAD9	0x02
#define DDRAD10	0x04
#define DDRAD11	0x08
#define DDRAD12	0x10
#define DDRAD13	0x20
#define DDRAD14	0x40
#define DDRAD15	0x80

typedef union uDDRADL		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrad0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrad1	:1;
    tU08 ddrad2	:1;
    tU08 ddrad3	:1;
    tU08 ddrad4	:1;
    tU08 ddrad5	:1;
    tU08 ddrad6	:1;
    tU08 ddrad7	:1;
    }bit;
  }tDDRADL;

#define DDRAD0	0x01	/*bit masks */
#define DDRAD1	0x02
#define DDRAD2	0x04
#define DDRAD3	0x08
#define DDRAD4	0x10
#define DDRAD5	0x20
#define DDRAD6	0x40
#define DDRAD7	0x80
 
typedef union uDDRAD		/*data direction register */
  {
  tU16	word;
  struct
    {
    tDDRADH msb;
    tDDRADL lsb;
    }byte;
  }tDDRAD;

typedef union uRDRADH		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrad8	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrad9	:1;
    tU08 rdrad10:1;
    tU08 rdrad11:1;
    tU08 rdrad12:1;
    tU08 rdrad13:1;
    tU08 rdrad14:1;
    tU08 rdrad15:1;
    }bit;
  }tRDRADH;

#define RDRAD8	0x01	/*bit masks */
#define RDRAD9	0x02
#define RDRAD10	0x04
#define RDRAD11	0x08
#define RDRAD12	0x10
#define RDRAD13	0x20
#define RDRAD14	0x40
#define RDRAD15	0x80

typedef union uRDRADL		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrad0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrad1	:1;
    tU08 rdrad2	:1;
    tU08 rdrad3	:1;
    tU08 rdrad4	:1;
    tU08 rdrad5	:1;
    tU08 rdrad6	:1;
    tU08 rdrad7	:1;
    }bit;
  }tRDRADL;
  
#define RDRAD0	0x01	/*bit masks */
#define RDRAD1	0x02
#define RDRAD2	0x04
#define RDRAD3	0x08
#define RDRAD4	0x10
#define RDRAD5	0x20
#define RDRAD6	0x40
#define RDRAD7	0x80
  
typedef union uRDRAD		/*reduced drive register */
  {
  tU16	word;
  struct
    {
    tRDRADH msb;
    tRDRADL lsb;
    }byte;
  }tRDRAD;
  
typedef union uPERADH		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perad8		:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perad9		:1;
    tU08 perad10	:1;
    tU08 perad11	:1;
    tU08 perad12	:1;
    tU08 perad13	:1;
    tU08 perad14	:1;
    tU08 perad15	:1;
    }bit;
  }tPERADH;

#define PERAD8	0x01	/*bit masks */
#define PERAD9	0x02
#define PERAD10 0x04
#define PERAD11 0x08
#define PERAD12 0x10
#define PERAD13 0x20
#define PERAD14 0x40
#define PERAD15 0x80

typedef union uPERADL		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perad0		:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perad1		:1;
    tU08 perad2		:1;
    tU08 perad3		:1;
    tU08 perad4		:1;
    tU08 perad5		:1;
    tU08 perad6		:1;
    tU08 perad7		:1;
    }bit;
  }tPERADL;
  
#define PERAD0	0x01	/*bit masks */
#define PERAD1	0x02
#define PERAD2 	0x04
#define PERAD3 	0x08
#define PERAD4 	0x10
#define PERAD5 	0x20
#define PERAD6 	0x40
#define PERAD7 	0x80

typedef union uPERAD		/*pull-up/dn enable register */
  {
  tU16	word;
  struct
    {
    tPERADH msb;
    tPERADL lsb;
    }byte;
  }tPERAD;

typedef union uPPSADH		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsad8		:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsad9		:1;
    tU08 ppsad10	:1;
    tU08 ppsad11	:1;
    tU08 ppsad12	:1;
    tU08 ppsad13	:1;
    tU08 ppsad14	:1;
    tU08 ppsad15	:1;
    }bit;
  }tPPSADH;

#define PPSAD8	0x01	/*bit masks */
#define PPSAD9	0x02
#define PPSAD10 0x04
#define PPSAD11 0x08
#define PPSAD12 0x10
#define PPSAD13 0x20
#define PPSAD14	0x40
#define PPSAD15 0x80

typedef union uPPSADL		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsad0		:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsad1		:1;
    tU08 ppsad2		:1;
    tU08 ppsad3		:1;
    tU08 ppsad4		:1;
    tU08 ppsad5		:1;
    tU08 ppsad6		:1;
    tU08 ppsad7		:1;
    }bit;
  }tPPSADL;

#define PPSAD0	0x01	/*bit masks */
#define PPSAD1	0x02
#define PPSAD2 	0x04
#define PPSAD3 	0x08
#define PPSAD4 	0x10
#define PPSAD5 	0x20
#define PPSAD6 	0x40
#define PPSAD7 	0x80
  
typedef union uPPSAD		/*pull-up/dn polarity register */
  {
  tU16	word;
  struct
    {
    tPPSADH msb;
    tPPSADL lsb;
    }byte;
  }tPPSAD;

typedef union uPIEADH		/*interrupt enable register */
  {
  tU08	byte;
  struct
    {
    tU08 piead8		:1;		/*interrupt enable bits */
    tU08 piead9		:1;
    tU08 piead10	:1;
    tU08 piead11	:1;
    tU08 piead12	:1;
    tU08 piead13	:1;
    tU08 piead14	:1;
    tU08 piead15	:1;
    }bit;
  }tPIEADH;

#define PIEAD8	0x01	/*bit masks */
#define PIEAD9	0x02
#define PIEAD10 0x04
#define PIEAD11 0x08
#define PIEAD12 0x10
#define PIEAD13 0x20
#define PIEAD14	0x40
#define PIEAD15 0x80

typedef union uPIEADL		/*interrupt enable register */
  {
  tU08	byte;
  struct
    {
    tU08 piead0		:1;		/*interrupt enable bits */
    tU08 piead1		:1;
    tU08 piead2		:1;
    tU08 piead3		:1;
    tU08 piead4		:1;
    tU08 piead5		:1;
    tU08 piead6		:1;
    tU08 piead7		:1;
    }bit;
  }tPIEADL;

#define PIEAD0	0x01	/*bit masks */
#define PIEAD1	0x02
#define PIEAD2 	0x04
#define PIEAD3 	0x08
#define PIEAD4 	0x10
#define PIEAD5 	0x20
#define PIEAD6 	0x40
#define PIEAD7 	0x80
  
typedef union uPIEAD		/*interrupt enable register */
  {
  tU16	word;
  struct
    {
    tPIEADH msb;
    tPIEADL lsb;
    }byte;
  }tPIEAD;

typedef union uPIFADH		/*interrupt flag register */
  {
  tU08	byte;
  struct
    {
    tU08 pifad8		:1;		/*interrupt flag bits */
    tU08 pifad9		:1;
    tU08 pifad10	:1;
    tU08 pifad11	:1;
    tU08 pifad12	:1;
    tU08 pifad13	:1;
    tU08 pifad14	:1;
    tU08 pifad15	:1;
    }bit;
  }tPIFADH;

#define PIFAD8	0x01	/*bit masks */
#define PIFAD9	0x02
#define PIFAD10 0x04
#define PIFAD11 0x08
#define PIFAD12 0x10
#define PIFAD13 0x20
#define PIFAD14	0x40
#define PIFAD15 0x80

typedef union uPIFADL		/*interrupt flag register */
  {
  tU08	byte;
  struct
    {
    tU08 pifad0		:1;		/*interrupt flag bits */
    tU08 pifad1		:1;
    tU08 pifad2		:1;
    tU08 pifad3		:1;
    tU08 pifad4		:1;
    tU08 pifad5		:1;
    tU08 pifad6		:1;
    tU08 pifad7		:1;
    }bit;
  }tPIFADL;
  
#define PIFAD0	0x01	/*bit masks */
#define PIFAD1	0x02
#define PIFAD2 	0x04
#define PIFAD3 	0x08
#define PIFAD4 	0x10
#define PIFAD5 	0x20
#define PIFAD6 	0x40
#define PIFAD7 	0x80
  
typedef union uPIFAD		/*interrupt flag register */
  {
  tU16	word;
  struct
    {
    tPIFADH msb;
    tPIFADL lsb;
    }byte;
  }tPIFAD;

typedef struct					/*port integration module  */
  {
								/*PORT T */
  volatile tPTT		ptt;		/*i/o register */
  volatile tPTIT	ptit;		/*input register */
  volatile tDDRT	ddrt;		/*data direction register */
  volatile tRDRT	rdrt;		/*reduced drive register */
  volatile tPERT	pert;		/*pull-up/dn enable register */
  volatile tPPST	ppst;		/*pull-up/dn polarity register */
           tU08		rsvt[2];	/*reserved (maintaining memory map) */

  								/*PORT S */
  volatile tPTS		pts;		/*i/o register */
  volatile tPTIS	ptis;		/*input register */
  volatile tDDRS	ddrs;		/*data direction register */
  volatile tRDRS	rdrs;		/*reduced drive register */
  volatile tPERS	pers;		/*pull-up/dn enable register */
  volatile tPPSS	ppss;		/*pull-up/dn polarity register */
  volatile tWOMS	woms;		/*wired-or mode register */
           tU08		rsvs;		/*reserved (maintaining memory map) */

								/*PORT M */
  volatile tPTM		ptm;		/*i/o register */
  volatile tPTIM	ptim;		/*input register */
  volatile tDDRM	ddrm;		/*data direction register */
  volatile tRDRM	rdrm;		/*reduced drive register */
  volatile tPERM	perm;		/*pull-up/dn enable register */
  volatile tPPSM	ppsm;		/*pull-up/dn polarity register */
  volatile tWOMM	womm;		/*wired-or mode register */
           tU08		rsvs2;		/*reserved (maintaining memory map) */

  								/*PORT P */
  volatile tPTP		ptp;		/*i/o register */
  volatile tPTIP	ptip;		/*input register */
  volatile tDDRP	ddrp;		/*data direction register */
  volatile tRDRP	rdrp;		/*reduced drive register */
  volatile tPERP	perp;		/*pull-up/dn enable register */
  volatile tPPSP	ppsp;		/*pull-up/dn polarity register */
           tU08 	rsvt2[2];	/*reserved (maintaining memory map) */
  
  								/*PORT Q */
  volatile tPTQ		ptq;		/*i/o register */
  volatile tPTIQ	ptiq;		/*input register */
  volatile tDDRQ	ddrq;		/*data direction register */
  volatile tRDRQ	rdrq;		/*reduced drive register */
  volatile tPERQ	perq;		/*pull-up/dn enable register */
  volatile tPPSQ	ppsq;		/*pull-up/dn polarity register */
           tU08		rsvt3[2];	/*reserved (maintaining memory map) */

  								/*PORT U */
  volatile tPTU		ptu;		/*i/o register */
  volatile tPTIU	ptiu;		/*input register */
  volatile tDDRU	ddru;		/*data direction register */
  volatile tRDRU	rdru;		/*reduced drive register */
  volatile tPERU	peru;		/*pull-up/dn enable register */
  volatile tPPSU	ppsu;		/*pull-up/dn polarity register */
  volatile tMODRR	modrr;		/*interrupt enable register */
           tU08		rsvs3;		/*reserved (maintaining memory map) */
  
  								/*PORT AD */
  volatile tPTAD    ptad;		/*i/o register */
  volatile tPTIAD   ptiad;		/*input register */
  volatile tDDRAD   ddrad;		/*data direction register */
  volatile tRDRAD   rdrad;		/*reduced drive register */
  volatile tPERAD   perad;		/*pull-up/dn enable register */
  volatile tPPSAD   ppsad;		/*pull-up/dn polarity register */
  volatile tPIEAD   piead;		/*port ad interrupt enable register */
  volatile tPIFAD	pifad;		/*port ad interrupt flag register */
  } tPIM;


#endif /*S12E128PIMV1_H */
