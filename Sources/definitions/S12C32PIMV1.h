/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12C32PIMV1.h		                                             */
/*                                                                           */
/* PURPOSE: header file for S12 PIM block     					     		 */
/*                                                                           */
/*                                                                           */
/* AUTHOR: r9aabe	 LOCATION: Austin,TX   LAST EDIT DATE: 09.24.02          */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef S12C32PIMV1_H			/*prevent duplicated includes */
#define S12C32PIMV1_H

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


/******************** Module Routing Register MODRR ***************/

typedef union uMODRR
  {
  tU08	byte;
  struct
    {
    tU08 modrr0	:1;		/*PWM/TIM routing */
    tU08 modrr1	:1;		/*PWM/TIM routing */
    tU08 moddr2	:1;		/*PWM/TIM routing */
    tU08 moddr3	:1;		/*PWM/TIM routing */
    tU08 modrr4	:1;		/*PWM/TIM routing */
    tU08 		:1;		/*not used */
    tU08 		:1;		/*not used */
    tU08        :1;		/*not used */
    }bit;
  }tMODRR;

#define MODRR0	0x01	/*bit masks */
#define MODRR1	0x02
#define MODDR2  0x04
#define MODRR3	0x08
#define MODRR4	0x10


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

typedef union uPIEP		/*interrupt enable register */
  {
  tU08	byte;
  struct
    {
    tU08 piep0	:1;		/*interrupt source (1:enabled) */
    tU08 piep1	:1;
    tU08 piep2	:1;
    tU08 piep3	:1;
    tU08 piep4	:1;
    tU08 piep5	:1;
    tU08 piep6	:1;
    tU08 piep7	:1;
    }bit;
  }tPIEP;

#define PIEP0	0x01	/*bit masks */
#define PIEP1	0x02
#define PIEP2 	0x04
#define PIEP3 	0x08
#define PIEP4 	0x10
#define PIEP5 	0x20
#define PIEP6 	0x40
#define PIEP7 	0x80

typedef union uPIFP		/*wired-or mode register */
  {
  tU08	byte;
  struct
    {
    tU08 pifp0	:1;		/*wired-or bits (1:enabled) */
    tU08 pifp1	:1;
    tU08 pifp2	:1;
    tU08 pifp3	:1;
    tU08 pifp4	:1;
    tU08 pifp5	:1;
    tU08 pifp6	:1;
    tU08 pifp7	:1;
    }bit;
  }tPIFP;

#define PIFP0	0x01	/*bit masks */
#define PIFP1	0x02
#define PIFP2 	0x04
#define PIFP3 	0x08
#define PIFP4 	0x10
#define PIFP5 	0x20
#define PIFP6 	0x40
#define PIFP7 	0x80


/******************************  PORT J  **************************/

typedef union uPTJ		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptj0	:1;		/*i/o port pins */
    tU08 ptj1	:1;
    tU08 ptj2	:1;
    tU08 ptj3	:1;
    tU08 ptj4	:1;
    tU08 ptj5	:1;
    tU08 ptj6	:1;
    tU08 ptj7	:1;
    }bit;
  }tPTJ;

#define PTJ0	0x01	/*bit masks */
#define PTJ1	0x02
#define PTJ2 	0x04
#define PTJ3 	0x08
#define PTJ4 	0x10
#define PTJ5 	0x20
#define PTJ6 	0x40
#define PTJ7 	0x80

typedef union uPTIJ		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptij0	:1;		/*i/o port pins */
    tU08 ptij1	:1;
    tU08 ptij2	:1;
    tU08 ptij3	:1;
    tU08 ptij4	:1;
    tU08 ptij5	:1;
    tU08 ptij6	:1;
    tU08 ptij7	:1;
    }bit;
  }tPTIJ;

#define PTIJ0	0x01	/*bit masks */
#define PTIJ1	0x02
#define PTIJ2 	0x04
#define PTIJ3 	0x08
#define PTIJ4 	0x10
#define PTIJ5 	0x20
#define PTIJ6 	0x40
#define PTIJ7 	0x80

typedef union uDDRJ		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrj0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrj1	:1;
    tU08 ddrj2	:1;
    tU08 ddrj3	:1;
    tU08 ddrj4	:1;
    tU08 ddrj5	:1;
    tU08 ddrj6	:1;
    tU08 ddrj7	:1;
    }bit;
  }tDDRJ;

#define DDRJ0	0x01	/*bit masks */
#define DDRJ1	0x02
#define DDRJ2	0x04
#define DDRJ3	0x08
#define DDRJ4	0x10
#define DDRJ5	0x20
#define DDRJ6	0x40
#define DDRJ7	0x80

typedef union uRDRJ		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrj0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrj1	:1;
    tU08 rdrj2	:1;
    tU08 rdrj3	:1;
    tU08 rdrj4	:1;
    tU08 rdrj5	:1;
    tU08 rdrj6	:1;
    tU08 rdrj7	:1;
    }bit;
  }tRDRJ;

#define RDRJ0	0x01	/*bit masks */
#define RDRJ1	0x02
#define RDRJ2	0x04
#define RDRJ3	0x08
#define RDRJ4	0x10
#define RDRJ5	0x20
#define RDRJ6	0x40
#define RDRJ7	0x80

typedef union uPERJ		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perj0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perj1	:1;
    tU08 perj2	:1;
    tU08 perj3	:1;
    tU08 perj4	:1;
    tU08 perj5	:1;
    tU08 perj6	:1;
    tU08 perj7	:1;
    }bit;
  }tPERJ;

#define PERJ0	0x01	/*bit masks */
#define PERJ1	0x02
#define PERJ2 	0x04
#define PERJ3 	0x08
#define PERJ4 	0x10
#define PERJ5 	0x20
#define PERJ6 	0x40
#define PERJ7 	0x80

typedef union uPPSJ		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsj0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsj1	:1;
    tU08 ppsj2	:1;
    tU08 ppsj3	:1;
    tU08 ppsj4	:1;
    tU08 ppsj5	:1;
    tU08 ppsj6	:1;
    tU08 ppsj7	:1;
    }bit;
  }tPPSJ;

#define PPSJ0	0x01	/*bit masks */
#define PPSJ1	0x02
#define PPSJ2 	0x04
#define PPSJ3 	0x08
#define PPSJ4 	0x10
#define PPSJ5 	0x20
#define PPSJ6 	0x40
#define PPSJ7 	0x80

typedef union uPIEJ		/*interrupt enable register */
  {
  tU08	byte;
  struct
    {
    tU08 piej0	:1;		/*interrupt source (1:enabled) */
    tU08 piej1	:1;
    tU08 piej2	:1;
    tU08 piej3	:1;
    tU08 piej4	:1;
    tU08 piej5	:1;
    tU08 piej6	:1;
    tU08 piej7	:1;
    }bit;
  }tPIEJ;

#define PIEJ0	0x01	/*bit masks */
#define PIEJ1	0x02
#define PIEJ2 	0x04
#define PIEJ3 	0x08
#define PIEJ4 	0x10
#define PIEJ5 	0x20
#define PIEJ6 	0x40
#define PIEJ7 	0x80

typedef union uPIFJ		/*wired-or mode register */
  {
  tU08	byte;
  struct
    {
    tU08 pifj0	:1;		/*wired-or bits (1:enabled) */
    tU08 pifj1	:1;
    tU08 pifj2	:1;
    tU08 pifj3	:1;
    tU08 pifj4	:1;
    tU08 pifj5	:1;
    tU08 pifj6	:1;
    tU08 pifj7	:1;
    }bit;
  }tPIFJ;

#define PIFJ0	0x01	/*bit masks */
#define PIFJ1	0x02
#define PIFJ2 	0x04
#define PIFJ3 	0x08
#define PIFJ4 	0x10
#define PIFJ5 	0x20
#define PIFJ6 	0x40
#define PIFJ7 	0x80

/******************************  PORT AD  **************************/


typedef union uPTAD		/*i/o register */
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
  }tPTAD;

#define PTAD0	0x01	/*bit masks */
#define PTAD1	0x02
#define PTAD2 	0x04
#define PTAD3 	0x08
#define PTAD4 	0x10
#define PTAD5 	0x20
#define PTAD6 	0x40
#define PTAD7 	0x80

typedef union uPTIAD		/*input register */
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
  }tPTIAD;

#define PTIAD0	0x01	/*bit masks */
#define PTIAD1	0x02
#define PTIAD2 	0x04
#define PTIAD3 	0x08
#define PTIAD4 	0x10
#define PTIAD5 	0x20
#define PTIAD6 	0x40
#define PTIAD7 	0x80

typedef union uDDRAD		/*data direction register */
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
  }tDDRAD;

#define DDRAD0	0x01	/*bit masks */
#define DDRAD1	0x02
#define DDRAD2	0x04
#define DDRAD3	0x08
#define DDRAD4	0x10
#define DDRAD5	0x20
#define DDRAD6	0x40
#define DDRAD7	0x80

typedef union uRDRAD		/*reduced drive register */
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
  }tRDRAD;

#define RDRAD0	0x01	/*bit masks */
#define RDRAD1	0x02
#define RDRAD2	0x04
#define RDRAD3	0x08
#define RDRAD4	0x10
#define RDRAD5	0x20
#define RDRAD6	0x40
#define RDRAD7	0x80

typedef union uPERAD		/*pull-up/dn enable register */
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
  }tPERAD;

#define PERAD0	0x01	/*bit masks */
#define PERAD1	0x02
#define PERAD2 	0x04
#define PERAD3 	0x08
#define PERAD4 	0x10
#define PERAD5 	0x20
#define PERAD6 	0x40
#define PERAD7 	0x80

typedef union uPPSAD		/*pull-up/dn polarity register */
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
  }tPPSAD;

#define PPSAD0	0x01	/*bit masks */
#define PPSAD1	0x02
#define PPSAD2 	0x04
#define PPSAD3 	0x08
#define PPSAD4 	0x10
#define PPSAD5 	0x20
#define PPSAD6 	0x40
#define PPSAD7 	0x80

typedef struct					/*port integration module  */
  {
								/*PORT T */
  volatile tPTT		ptt;		/*i/o register */
  volatile tPTIT	ptit;		/*input register */
  volatile tDDRT	ddrt;		/*data direction register */
  volatile tRDRT	rdrt;		/*reduced drive register */
  volatile tPERT	pert;		/*pull-up/dn enable register */
  volatile tPPST	ppst;		/*pull-up/dn polarity register */
           tU08		rsvs;		/*reserved (maintaining memory map) */
  volatile tMODRR	modrr;		/*module routing register */

  								/*PORT S */
  volatile tPTS		pts;		/*i/o register */
  volatile tPTIS	ptis;		/*input register */
  volatile tDDRS	ddrs;		/*data direction register */
  volatile tRDRS	rdrs;		/*reduced drive register */
  volatile tPERS	pers;		/*pull-up/dn enable register */
  volatile tPPSS	ppss;		/*pull-up/dn polarity register */
  volatile tWOMS	woms;		/*wired-or mode register */
           tU08		rsvs2;		/*reserved (maintaining memory map) */

								/*PORT M */
  volatile tPTM		ptm;		/*i/o register */
  volatile tPTIM	ptim;		/*input register */
  volatile tDDRM	ddrm;		/*data direction register */
  volatile tRDRM	rdrm;		/*reduced drive register */
  volatile tPERM	perm;		/*pull-up/dn enable register */
  volatile tPPSM	ppsm;		/*pull-up/dn polarity register */
  volatile tWOMM	womm;		/*wired-or mode register */
           tU08		rsvs3;		/*reserved (maintaining memory map) */
           
             					/*PORT P */
  volatile tPTP		ptp;		/*i/o register */
  volatile tPTIP	ptip;		/*input register */
  volatile tDDRP	ddrp;		/*data direction register */
  volatile tRDRP	rdrp;		/*reduced drive register */
  volatile tPERP	perp;		/*pull-up/dn enable register */
  volatile tPPSP	ppsp;		/*pull-up/dn polarity register */
  volatile tPIEP	piep;		/*interrupt enable register */
  volatile tPIFP	pifp;		/*interrupt flag register */

  								/*PORT H */
  		   tU08		rsvt[8];	/*reserved (maintaining memory map) */

  								/*PORT J */
  volatile tPTJ		ptj;		/*i/o register */
  volatile tPTIJ	ptij;		/*input register */
  volatile tDDRJ	ddrj;		/*data direction register */
  volatile tRDRJ	rdrj;		/*reduced drive register */
  volatile tPERJ	perj;		/*pull-up/dn enable register */
  volatile tPPSJ	ppsj;		/*pull-up/dn polarity register */
  volatile tPIEJ	piej;		/*interrupt enable register */
  volatile tPIFJ	pifj;		/*interrupt flag register */
  
  								/*PORT AD */
  volatile tPTAD    ptad;		/*i/o register */
  volatile tPTIAD   ptiad;		/*input register */
  volatile tDDRAD   ddrad;		/*data direction register */
  volatile tRDRAD   rdrad;		/*reduced drive register */
  volatile tPERAD   perad;		/*pull-up/dn enable register */
  volatile tPPSAD   ppsad;		/*pull-up/dn polarity register */
  		   
  		   tU08		rsvt2[10];	/*reserved (maintaining memory map) */  		   
  } tPIM;


#endif /*S12C32PIMV1_H */