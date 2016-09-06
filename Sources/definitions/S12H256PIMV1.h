/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2000   */
/* FILE NAME: S12H256PIMV1.h		                                         */
/*                                                                           */
/* PURPOSE: header file for HCS12 PIM block     					 		 */
/*                                                                           */
/*                                                                           */
/* AUTHOR: r9aabe        LOCATION: Austin,TX      LAST EDIT DATE: 02.26.03   */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef S12H256PIMV1_H			/*prevent duplicated includes */
#define S12H256PIMV1_H

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
    tU08 	    :2;
    }bit;
  }tPTM;

#define PTM0	0x01	/*bit masks */
#define PTM1	0x02
#define PTM2 	0x04
#define PTM3 	0x08
#define PTM4 	0x10
#define PTM5 	0x20

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
    tU08      	:2;
    }bit;
  }tPTIM;

#define PTIM0	  0x01	/*bit masks */
#define PTIM1	  0x02
#define PTIM2 	0x04
#define PTIM3 	0x08
#define PTIM4 	0x10
#define PTIM5 	0x20

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
    tU08      	:2;
    }bit;
  }tDDRM;

#define DDRM0	0x01	/*bit masks */
#define DDRM1	0x02
#define DDRM2	0x04
#define DDRM3	0x08
#define DDRM4	0x10
#define DDRM5	0x20

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
    tU08      	:2;
  }bit;
  }tRDRM;

#define RDRM0	0x01	/*bit masks */
#define RDRM1	0x02
#define RDRM2	0x04
#define RDRM3	0x08
#define RDRM4	0x10
#define RDRM5	0x20

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
    tU08      	:2;
    }bit;
  }tPERM;

#define PERM0	0x01	/*bit masks */
#define PERM1	0x02
#define PERM2 	0x04
#define PERM3 	0x08
#define PERM4 	0x10
#define PERM5 	0x20

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
    tU08      	:2;
  }bit;
  }tPPSM;

#define PPSM0	0x01	/*bit masks */
#define PPSM1	0x02
#define PPSM2 	0x04
#define PPSM3 	0x08
#define PPSM4 	0x10
#define PPSM5 	0x20

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
    tU08      	:2;
    }bit;
  }tWOMM;

#define WOMM0	0x01	/*bit masks */
#define WOMM1	0x02
#define WOMM2 	0x04
#define WOMM3 	0x08
#define WOMM4 	0x10
#define WOMM5 	0x20


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
    tU08    	:2;
    }bit;
  }tPTP;

#define PTP0	0x01	/*bit masks */
#define PTP1	0x02
#define PTP2 	0x04
#define PTP3 	0x08
#define PTP4 	0x10
#define PTP5 	0x20

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
    tU08      	:2;
    }bit;
  }tPTIP;

#define PTIP0	0x01	/*bit masks */
#define PTIP1	0x02
#define PTIP2 	0x04
#define PTIP3 	0x08
#define PTIP4 	0x10
#define PTIP5 	0x20

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
    tU08      	:2;
   }bit;
  }tDDRP;

#define DDRP0	0x01	/*bit masks */
#define DDRP1	0x02
#define DDRP2	0x04
#define DDRP3	0x08
#define DDRP4	0x10
#define DDRP5	0x20

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
    tU08      	:2;
    
    }bit;
  }tRDRP;

#define RDRP0	0x01	/*bit masks */
#define RDRP1	0x02
#define RDRP2	0x04
#define RDRP3	0x08
#define RDRP4	0x10
#define RDRP5	0x20

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
    tU08      	:2;
    }bit;
  }tPERP;

#define PERP0	0x01	/*bit masks */
#define PERP1	0x02
#define PERP2 	0x04
#define PERP3 	0x08
#define PERP4 	0x10
#define PERP5 	0x20

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
    tU08      	:2;
    }bit;
  }tPPSP;

#define PPSP0	0x01	/*bit masks */
#define PPSP1	0x02
#define PPSP2 	0x04
#define PPSP3 	0x08
#define PPSP4 	0x10
#define PPSP5 	0x20



/******************************  PORT H  **************************/

typedef union uPTH		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 pth0	:1;		/*i/o port pins */
    tU08 pth1	:1;
    tU08 pth2	:1;
    tU08 pth3	:1;
    tU08 pth4	:1;
    tU08 pth5	:1;
    tU08 pth6	:1;
    tU08 pth7	:1;
    }bit;
  }tPTH;

#define PTH0	0x01	/*bit masks */
#define PTH1	0x02
#define PTH2 	0x04
#define PTH3 	0x08
#define PTH4 	0x10
#define PTH5 	0x20
#define PTH6 	0x40
#define PTH7 	0x80

typedef union uPTIH		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptih0	:1;		/*i/o port pins */
    tU08 ptih1	:1;
    tU08 ptih2	:1;
    tU08 ptih3	:1;
    tU08 ptih4	:1;
    tU08 ptih5	:1;
    tU08 ptih6	:1;
    tU08 ptih7	:1;
    }bit;
  }tPTIH;

#define PTIH0	0x01	/*bit masks */
#define PTIH1	0x02
#define PTIH2 	0x04
#define PTIH3 	0x08
#define PTIH4 	0x10
#define PTIH5 	0x20
#define PTIH6 	0x40
#define PTIH7 	0x80

typedef union uDDRH		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrh0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrh1	:1;
    tU08 ddrh2	:1;
    tU08 ddrh3	:1;
    tU08 ddrh4	:1;
    tU08 ddrh5	:1;
    tU08 ddrh6	:1;
    tU08 ddrh7	:1;
    }bit;
  }tDDRH;

#define DDRH0	0x01	/*bit masks */
#define DDRH1	0x02
#define DDRH2	0x04
#define DDRH3	0x08
#define DDRH4	0x10
#define DDRH5	0x20
#define DDRH6	0x40
#define DDRH7	0x80

typedef union uRDRH		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrh0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrh1	:1;
    tU08 rdrh2	:1;
    tU08 rdrh3	:1;
    tU08 rdrh4	:1;
    tU08 rdrh5	:1;
    tU08 rdrh6	:1;
    tU08 rdrh7	:1;
    }bit;
  }tRDRH;

#define RDRH0	0x01	/*bit masks */
#define RDRH1	0x02
#define RDRH2	0x04
#define RDRH3	0x08
#define RDRH4	0x10
#define RDRH5	0x20
#define RDRH6	0x40
#define RDRH7	0x80

typedef union uPERH		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perh0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perh1	:1;
    tU08 perh2	:1;
    tU08 perh3	:1;
    tU08 perh4	:1;
    tU08 perh5	:1;
    tU08 perh6	:1;
    tU08 perh7	:1;
    }bit;
  }tPERH;

#define PERH0	0x01	/*bit masks */
#define PERH1	0x02
#define PERH2 	0x04
#define PERH3 	0x08
#define PERH4 	0x10
#define PERH5 	0x20
#define PERH6 	0x40
#define PERH7 	0x80

typedef union uPPSH		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsh0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsh1	:1;
    tU08 ppsh2	:1;
    tU08 ppsh3	:1;
    tU08 ppsh4	:1;
    tU08 ppsh5	:1;
    tU08 ppsh6	:1;
    tU08 ppsh7	:1;
    }bit;
  }tPPSH;

#define PPSH0	0x01	/*bit masks */
#define PPSH1	0x02
#define PPSH2 	0x04
#define PPSH3 	0x08
#define PPSH4 	0x10
#define PPSH5 	0x20
#define PPSH6 	0x40
#define PPSH7 	0x80

typedef union uPIEH		/*interrupt enable register */
  {
  tU08	byte;
  struct
    {
    tU08 pieh0	:1;		/*interrupt source (1:enabled) */
    tU08 pieh1	:1;
    tU08 pieh2	:1;
    tU08 pieh3	:1;
    tU08 pieh4	:1;
    tU08 pieh5	:1;
    tU08 pieh6	:1;
    tU08 pieh7	:1;
    }bit;
  }tPIEH;

#define PIEH0	0x01	/*bit masks */
#define PIEH1	0x02
#define PIEH2 	0x04
#define PIEH3 	0x08
#define PIEH4 	0x10
#define PIEH5 	0x20
#define PIEH6 	0x40
#define PIEH7 	0x80

typedef union uPIFH		/*wired-or mode register */
  {
  tU08	byte;
  struct
    {
    tU08 pifh0	:1;		/*wired-or bits (1:enabled) */
    tU08 pifh1	:1;
    tU08 pifh2	:1;
    tU08 pifh3	:1;
    tU08 pifh4	:1;
    tU08 pifh5	:1;
    tU08 pifh6	:1;
    tU08 pifh7	:1;
    }bit;
  }tPIFH;

#define PIFH0	0x01	/*bit masks */
#define PIFH1	0x02
#define PIFH2 	0x04
#define PIFH3 	0x08
#define PIFH4 	0x10
#define PIFH5 	0x20
#define PIFH6 	0x40
#define PIFH7 	0x80


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
    tU08    	:4;
    }bit;
  }tPTJ;

#define PTJ0	0x01	/*bit masks */
#define PTJ1	0x02
#define PTJ2 	0x04
#define PTJ3 	0x08

typedef union uPTIJ		/*input register */
  {
  tU08	byte;
  struct
    {
    tU08 ptij0	:1;		/*i/o port pins */
    tU08 ptij1	:1;
    tU08 ptij2	:1;
    tU08 ptij3	:1;
    tU08      	:4;
    }bit;
  }tPTIJ;

#define PTIJ0	0x01	/*bit masks */
#define PTIJ1	0x02
#define PTIJ2 	0x04
#define PTIJ3 	0x08

typedef union uDDRJ		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrj0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrj1	:1;
    tU08 ddrj2	:1;
    tU08 ddrj3	:1;
    tU08      	:4;
   }bit;
  }tDDRJ;

#define DDRJ0	0x01	/*bit masks */
#define DDRJ1	0x02
#define DDRJ2	0x04
#define DDRJ3	0x08

typedef union uRDRJ		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrj0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrj1	:1;
    tU08 rdrj2	:1;
    tU08 rdrj3	:1;
    tU08      	:4;
    }bit;
  }tRDRJ;

#define RDRJ0	0x01	/*bit masks */
#define RDRJ1	0x02
#define RDRJ2	0x04
#define RDRJ3	0x08

typedef union uPERJ		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perj0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perj1	:1;
    tU08 perj2	:1;
    tU08 perj3	:1;
    tU08      	:4;
    }bit;
  }tPERJ;

#define PERJ0	0x01	/*bit masks */
#define PERJ1	0x02
#define PERJ2 	0x04
#define PERJ3 	0x08

typedef union uPPSJ		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsj0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsj1	:1;
    tU08 ppsj2	:1;
    tU08 ppsj3	:1;
    tU08      	:4;
    }bit;
  }tPPSJ;

#define PPSJ0	0x01	/*bit masks */
#define PPSJ1	0x02
#define PPSJ2 	0x04
#define PPSJ3 	0x08

typedef union uPIEJ		/*interrupt enable register */
  {
  tU08	byte;
  struct
    {
    tU08 piej0	:1;		/*interrupt source (1:enabled) */
    tU08 piej1	:1;
    tU08 piej2	:1;
    tU08 piej3	:1;
    tU08      	:4;
    }bit;
  }tPIEJ;

#define PIEJ0	0x01	/*bit masks */
#define PIEJ1	0x02
#define PIEJ2 	0x04
#define PIEJ3 	0x08

typedef union uPIFJ		/*wired-or mode register */
  {
  tU08	byte;
  struct
    {
    tU08 pifj0	:1;		/*wired-or bits (1:enabled) */
    tU08 pifj1	:1;
    tU08 pifj2	:1;
    tU08 pifj3	:1;
    tU08      	:4;
    }bit;
  }tPIFJ;

#define PIFJ0	0x01	/*bit masks */
#define PIFJ1	0x02
#define PIFJ2 	0x04
#define PIFJ3 	0x08

/******************************  PORT L  **************************/

 typedef union uPTL		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptl0	:1;		/*i/o port pins */
    tU08 ptl1	:1;
    tU08 ptl2	:1;
    tU08 ptl3	:1;
    tU08 ptl4	:1;
    tU08 ptl5	:1;
    tU08 ptl6	:1;
    tU08 ptl7	:1;
    }bit;
  }tPTL;

#define PTL0	0x01	/*bit masks */
#define PTL1	0x02
#define PTL2 	0x04
#define PTL3 	0x08
#define PTL4 	0x10
#define PTL5 	0x20
#define PTL6 	0x40
#define PTL7 	0x80

typedef union uPTIL		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptil0	:1;		/*i/o port pins */
    tU08 ptil1	:1;
    tU08 ptil2	:1;
    tU08 ptil3	:1;
    tU08 ptil4	:1;
    tU08 ptil5	:1;
    tU08 ptil6	:1;
    tU08 ptil7	:1;
    }bit;
  }tPTIL;

#define PTIL0	0x01	/*bit masks */
#define PTIL1	0x02
#define PTIL2 	0x04
#define PTIL3 	0x08
#define PTIL4 	0x10
#define PTIL5 	0x20
#define PTIL6 	0x40
#define PTIL7 	0x80

typedef union uDDRL		/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrl0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrl1	:1;
    tU08 ddrl2	:1;
    tU08 ddrl3	:1;
    tU08 ddrl4	:1;
    tU08 ddrl5	:1;
    tU08 ddrl6	:1;
    tU08 ddrl7	:1;
    }bit;
  }tDDRL;

#define DDRL0	0x01	/*bit masks */
#define DDRL1	0x02
#define DDRL2	0x04
#define DDRL3	0x08
#define DDRL4	0x10
#define DDRL5	0x20
#define DDRL6	0x40
#define DDRL7	0x80

typedef union uRDRL		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 rdrl0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 rdrl1	:1;
    tU08 rdrl2	:1;
    tU08 rdrl3	:1;
    tU08 rdrl4	:1;
    tU08 rdrl5	:1;
    tU08 rdrl6	:1;
    tU08 rdrl7	:1;
    }bit;
  }tRDRL;

#define RDRL0	0x01	/*bit masks */
#define RDRL1	0x02
#define RDRL2	0x04
#define RDRL3	0x08
#define RDRL4	0x10
#define RDRL5	0x20
#define RDRL6	0x40
#define RDRL7	0x80

typedef union uPERL		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perl0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perl1	:1;
    tU08 perl2	:1;
    tU08 perl3	:1;
    tU08 perl4	:1;
    tU08 perl5	:1;
    tU08 perl6	:1;
    tU08 perl7	:1;
    }bit;
  }tPERL;

#define PERL0	0x01	/*bit masks */
#define PERL1	0x02
#define PERL2 	0x04
#define PERL3 	0x08
#define PERL4 	0x10
#define PERL5 	0x20
#define PERL6 	0x40
#define PERL7 	0x80

typedef union uPPSL		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsl0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsl1	:1;
    tU08 ppsl2	:1;
    tU08 ppsl3	:1;
    tU08 ppsl4	:1;
    tU08 ppsl5	:1;
    tU08 ppsl6	:1;
    tU08 ppsl7	:1;
    }bit;
  }tPPSL;

#define PPSL0	0x01	/*bit masks */
#define PPSL1	0x02
#define PPSL2 	0x04
#define PPSL3 	0x08
#define PPSL4 	0x10
#define PPSL5 	0x20
#define PPSL6 	0x40
#define PPSL7 	0x80


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

typedef union uPTIU		/*i/o register */
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

typedef union uSRRU		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 srru0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 srru1	:1;
    tU08 srru2	:1;
    tU08 srru3	:1;
    tU08 srru4	:1;
    tU08 srru5	:1;
    tU08 srru6	:1;
    tU08 srru7	:1;
    }bit;
  }tSRRU;

#define SRRU0	0x01	/*bit masks */
#define SRRU1	0x02
#define SRRU2	0x04
#define SRRU3	0x08
#define SRRU4	0x10
#define SRRU5	0x20
#define SRRU6	0x40
#define SRRU7	0x80

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


/******************************  PORT V  **************************/


typedef union uPTV		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptv0	:1;		/*i/o port pins */
    tU08 ptv1	:1;
    tU08 ptv2	:1;
    tU08 ptv3	:1;
    tU08 ptv4	:1;
    tU08 ptv5	:1;
    tU08 ptv6	:1;
    tU08 ptv7	:1;
    }bit;
  }tPTV;

#define PTV0	0x01	/*bit masks */
#define PTV1	0x02
#define PTV2 	0x04
#define PTV3 	0x08
#define PTV4 	0x10
#define PTV5 	0x20
#define PTV6 	0x40
#define PTV7 	0x80

typedef union uPTIV		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptiv0	:1;		/*i/o port pins */
    tU08 ptiv1	:1;
    tU08 ptiv2	:1;
    tU08 ptiv3	:1;
    tU08 ptiv4	:1;
    tU08 ptiv5	:1;
    tU08 ptiv6	:1;
    tU08 ptiv7	:1;
    }bit;
  }tPTIV;

#define PTIV0	0x01	/*bit masks */
#define PTIV1	0x02
#define PTIV2 	0x04
#define PTIV3 	0x08
#define PTIV4 	0x10
#define PTIV5 	0x20
#define PTIV6 	0x40
#define PTIV7 	0x80

typedef union uDDRV	/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrv0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrv1	:1;
    tU08 ddrv2	:1;
    tU08 ddrv3	:1;
    tU08 ddrv4	:1;
    tU08 ddrv5	:1;
    tU08 ddrv6	:1;
    tU08 ddrv7	:1;
    }bit;
  }tDDRV;

#define DDRV0	0x01	/*bit masks */
#define DDRV1	0x02
#define DDRV2	0x04
#define DDRV3	0x08
#define DDRV4	0x10
#define DDRV5	0x20
#define DDRV6	0x40
#define DDRV7	0x80

typedef union uSRRV		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 srrv0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 srrv1	:1;
    tU08 srrv2	:1;
    tU08 srrv3	:1;
    tU08 srrv4	:1;
    tU08 srrv5	:1;
    tU08 srrv6	:1;
    tU08 srrv7	:1;
    }bit;
  }tSRRV;

#define SRRV0	0x01	/*bit masks */
#define SRRV1	0x02
#define SRRV2	0x04
#define SRRV3	0x08
#define SRRV4	0x10
#define SRRV5	0x20
#define SRRV6	0x40
#define SRRV7	0x80

typedef union uPERV		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perv0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perv1	:1;
    tU08 perv2	:1;
    tU08 perv3	:1;
    tU08 perv4	:1;
    tU08 perv5	:1;
    tU08 perv6	:1;
    tU08 perv7	:1;
    }bit;
  }tPERV;

#define PERV0	0x01	/*bit masks */
#define PERV1	0x02
#define PERV2 	0x04
#define PERV3 	0x08
#define PERV4 	0x10
#define PERV5 	0x20
#define PERV6 	0x40
#define PERV7 	0x80

typedef union uPPSV		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsv0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsv1	:1;
    tU08 ppsv2	:1;
    tU08 ppsv3	:1;
    tU08 ppsv4	:1;
    tU08 ppsv5	:1;
    tU08 ppsv6	:1;
    tU08 ppsv7	:1;
    }bit;
  }tPPSV;

#define PPSV0	0x01	/*bit masks */
#define PPSV1	0x02
#define PPSV2 	0x04
#define PPSV3 	0x08
#define PPSV4 	0x10
#define PPSV5 	0x20
#define PPSV6 	0x40
#define PPSV7 	0x80

/******************************  PORT W  **************************/


typedef union uPTW		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptw0	:1;		/*i/o port pins */
    tU08 ptw1	:1;
    tU08 ptw2	:1;
    tU08 ptw3	:1;
    tU08 ptw4	:1;
    tU08 ptw5	:1;
    tU08 ptw6	:1;
    tU08 ptw7	:1;
    }bit;
  }tPTW;

#define PTW0	0x01	/*bit masks */
#define PTW1	0x02
#define PTW2 	0x04
#define PTW3 	0x08
#define PTW4 	0x10
#define PTW5 	0x20
#define PTW6 	0x40
#define PTW7 	0x80

typedef union uPTIW		/*i/o register */
  {
  tU08	byte;
  struct
    {
    tU08 ptiw0	:1;		/*i/o port pins */
    tU08 ptiw1	:1;
    tU08 ptiw2	:1;
    tU08 ptiw3	:1;
    tU08 ptiw4	:1;
    tU08 ptiw5	:1;
    tU08 ptiw6	:1;
    tU08 ptiw7	:1;
    }bit;
  }tPTIW;

#define PTIW0	0x01	/*bit masks */
#define PTIW1	0x02
#define PTIW2 	0x04
#define PTIW3 	0x08
#define PTIW4 	0x10
#define PTIW5 	0x20
#define PTIW6 	0x40
#define PTIW7 	0x80

typedef union uDDRW	/*data direction register */
  {
  tU08	byte;
  struct
    {
    tU08 ddrw0	:1;		/*data direction bits (0:input;1:output) */
    tU08 ddrw1	:1;
    tU08 ddrw2	:1;
    tU08 ddrw3	:1;
    tU08 ddrw4	:1;
    tU08 ddrw5	:1;
    tU08 ddrw6	:1;
    tU08 ddrw7	:1;
    }bit;
  }tDDRW;

#define DDRW0	0x01	/*bit masks */
#define DDRW1	0x02
#define DDRW2	0x04
#define DDRW3	0x08
#define DDRW4	0x10
#define DDRW5	0x20
#define DDRW6	0x40
#define DDRW7	0x80

typedef union uSRRW		/*reduced drive register */
  {
  tU08	byte;
  struct
    {
    tU08 srrw0	:1;		/*reduced drive bits (0:full;1:reduced) */
    tU08 srrw1	:1;
    tU08 srrw2	:1;
    tU08 srrw3	:1;
    tU08 srrw4	:1;
    tU08 srrw5	:1;
    tU08 srrw6	:1;
    tU08 srrw7	:1;
    }bit;
  }tSRRW;

#define SRRW0	0x01	/*bit masks */
#define SRRW1	0x02
#define SRRW2	0x04
#define SRRW3	0x08
#define SRRW4	0x10
#define SRRW5	0x20
#define SRRW6	0x40
#define SRRW7	0x80

typedef union uPERW		/*pull-up/dn enable register */
  {
  tU08	byte;
  struct
    {
    tU08 perw0	:1;		/*pull-up/dn bits (1:enabled) */
    tU08 perw1	:1;
    tU08 perw2	:1;
    tU08 perw3	:1;
    tU08 perw4	:1;
    tU08 perw5	:1;
    tU08 perw6	:1;
    tU08 perw7	:1;
    }bit;
  }tPERW;

#define PERW0	0x01	/*bit masks */
#define PERW1	0x02
#define PERW2 	0x04
#define PERW3 	0x08
#define PERW4 	0x10
#define PERW5 	0x20
#define PERW6 	0x40
#define PERW7 	0x80

typedef union uPPSW		/*pull-up/dn polarity register */
  {
  tU08	byte;
  struct
    {
    tU08 ppsw0	:1;		/*pull-up/dn bits (0:pull-up;1:pull-dn) */
    tU08 ppsw1	:1;
    tU08 ppsw2	:1;
    tU08 ppsw3	:1;
    tU08 ppsw4	:1;
    tU08 ppsw5	:1;
    tU08 ppsw6	:1;
    tU08 ppsw7	:1;
    }bit;
  }tPPSW;

#define PPSW0	0x01	/*bit masks */
#define PPSW1	0x02
#define PPSW2 	0x04
#define PPSW3 	0x08
#define PPSW4 	0x10
#define PPSW5 	0x20
#define PPSW6 	0x40
#define PPSW7 	0x80
                        

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
           tU08		rsvm;		/*reserved (maintaining memory map) */

  								/*PORT P */
  volatile tPTP		ptp;		/*i/o register */
  volatile tPTIP	ptip;		/*input register */
  volatile tDDRP	ddrp;		/*data direction register */
  volatile tRDRP	rdrp;		/*reduced drive register */
  volatile tPERP	perp;		/*pull-up/dn enable register */
  volatile tPPSP	ppsp;		/*pull-up/dn polarity register */
           tU08		rsvp[2];	/*reserved (maintaining memory map) */
           
  								/*PORT H */
  volatile tPTH		pth;		/*i/o register */
  volatile tPTIH	ptih;		/*input register */
  volatile tDDRH	ddrh;		/*data direction register */
  volatile tRDRH	rdrh;		/*reduced drive register */
  volatile tPERH	perh;		/*pull-up/dn enable register */
  volatile tPPSH	ppsh;		/*pull-up/dn polarity register */
  volatile tPIEH	pieh;		/*interrupt enable register */
  volatile tPIFH	pifh;		/*interrupt flag register */

  								/*PORT J */
  volatile tPTJ		ptj;		/*i/o register */
  volatile tPTIJ	ptij;		/*input register */
  volatile tDDRJ	ddrj;		/*data direction register */
  volatile tRDRJ	rdrj;		/*reduced drive register */
  volatile tPERJ	perj;		/*pull-up/dn enable register */
  volatile tPPSJ	ppsj;		/*pull-up/dn polarity register */
  volatile tPIEJ	piej;		/*interrupt enable register */
  volatile tPIFJ	pifj;		/*interrupt flag register */
  
                  /*PORT L */
  volatile tPTL		ptl;		/*i/o register */
  volatile tPTIL	ptil;		/*input register */
  volatile tDDRL	ddrl;		/*data direction register */
  volatile tRDRL	rdrl;		/*reduced drive register */
  volatile tPERL	perl;		/*pull-up/dn enable register */
  volatile tPPSL	ppsl;		/*pull-up/dn polarity register */
           tU08		rsvl[2];	/*reserved (maintaining memory map) */

  							/*PORT U */
  volatile tPTU		ptu;		/*i/o register */
  volatile tPTIU	ptiu;		/*input register */
  volatile tDDRU	ddru;		/*data direction register */
  volatile tSRRU	srru;		/*reduced drive register */
  volatile tPERU	peru;		/*pull-up/dn enable register */
  volatile tPPSU	ppsu;		/*pull-up/dn polarity register */
           tU08		rsvu[2];	/*reserved (maintaining memory map) */
           
  							/*PORT V */
  volatile tPTV		ptv;		/*i/o register */
  volatile tPTIV	ptiv;		/*input register */
  volatile tDDRV	ddrv;		/*data direction register */
  volatile tSRRV	srrv;		/*reduced drive register */
  volatile tPERV	perv;		/*pull-up/dn enable register */
  volatile tPPSV	ppsv;		/*pull-up/dn polarity register */
           tU08		rsvv[2];	/*reserved (maintaining memory map) */
           
  							/*PORT W */
  volatile tPTW		ptw;		/*i/o register */
  volatile tPTIW	ptiw;		/*input register */
  volatile tDDRW	ddrw;		/*data direction register */
  volatile tSRRW	srrw;		/*reduced drive register */
  volatile tPERW	perw;		/*pull-up/dn enable register */
  volatile tPPSW	ppsw;		/*pull-up/dn polarity register */
           tU08		rsvw[2];	/*reserved (maintaining memory map) */        
  } tPIM;


#endif /*S12H256PIMV1_H*/
