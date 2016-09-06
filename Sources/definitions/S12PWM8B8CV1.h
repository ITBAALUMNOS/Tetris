/*****************************************************************************/
/*                                             COPYRIGHT (c) MOTOROLA 2002   */
/* FILE NAME: S12PWM8B8CV1.h                                      	  		 */
/*                                                                           */
/* PURPOSE: Header File for S12 PWM_8B8C						 		     */
/*                                                                           */
/* DESCRIPTION: Defines the PWM_8B8C module register block as a      		 */
/* datastructure of type tPWM.         	                 					 */
/* 																		     */
/*                                                                           */
/* AUTHOR: r32151        LOCATION: EKB			   							 */
/*                                                                           */
/*****************************************************************************/

#ifndef S12PWM8B8CV1_H           /*prevent duplicated includes */
#define S12PWM8B8CV1_H

#ifndef MOTTYPES_H        /*prevent duplicated includes */
#include "MOTTYPES.h"
#endif

typedef union uPWME
  {
  tU08  byte;
  struct
    {
    tU08 pwme0  :1;     /*pwm channel enable */
    tU08 pwme1  :1;
    tU08 pwme2  :1;
    tU08 pwme3  :1;
    tU08 pwme4  :1;     
    tU08 pwme5  :1;
    tU08 pwme6  :1;
    tU08 pwme7  :1;
    }bit;
  }tPWME;

#define PWME0   0x01    /*bit masks */
#define PWME1   0x02
#define PWME2   0x04
#define PWME3   0x08
#define PWME4   0x10
#define PWME5   0x20
#define PWME6   0x40
#define PWME7   0x80

typedef union uPWMPOL
  {
  tU08  byte;
  struct
    {
    tU08 ppol0  :1;     /*pwm channel polarity */
    tU08 ppol1  :1;
    tU08 ppol2  :1;
    tU08 ppol3  :1;
    tU08 ppol4  :1;     
    tU08 ppol5  :1;
    tU08 ppol6  :1;
    tU08 ppol7  :1;
    }bit;
  }tPWMPOL;

#define PPOL0   0x01    /*bit masks */
#define PPOL1   0x02
#define PPOL2   0x04
#define PPOL3   0x08
#define PPOL4   0x10
#define PPOL5   0x20
#define PPOL6   0x40
#define PPOL7   0x80

typedef union uPWMCLK
  {
  tU08  byte;
  struct
    {
    tU08 pclk0  :1;     /*pwm clock select */
    tU08 pclk1  :1;
    tU08 pclk2  :1;
    tU08 pclk3  :1;
    tU08 pclk4  :1;     
    tU08 pclk5  :1;
    tU08 pclk6  :1;
    tU08 pclk7  :1;
    }bit;
  }tPWMCLK;

#define PCLK0   0x01    /*bit masks */
#define PCLK1   0x02
#define PCLK2   0x04
#define PCLK3   0x08
#define PCLK4   0x10
#define PCLK5   0x20
#define PCLK6   0x40
#define PCLK7   0x80

typedef union uPWMPRCLK
  {
  tU08  byte;
  struct
    {
    tU08 pcka   :3;     /*prescaler for clock A (1,2,4,8,16,32,64,128) */
    tU08        :1;     /*not used*/                                   
    tU08 pckb   :3;     /*prescaler for clock B (1,2,4,8,16,32,64,128) */
    tU08        :1;     /*not used */                                      
    }bit;
  }tPWMPRCLK;

#define PCKA0   0x01    /*bit masks */
#define PCKA1   0x02
#define PCKA2   0x04
#define PCKA    0x07    /*prescaler A mask */
#define PCKB0   0x10
#define PCKB1   0x20
#define PCKB2   0x40    
#define PCKB    0x70    /*prescaler B mask */


typedef union uPWMCAE
  {
  tU08  byte;
  struct
    {
    tU08 cae0   :1;     /*pwm channel center align enable */
    tU08 cae1   :1;
    tU08 cae2   :1;
    tU08 cae3   :1;
    tU08 cae4   :1;     
    tU08 cae5   :1;
    tU08 cae6   :1;
    tU08 cae7   :1;
    }bit;
  }tPWMCAE;

#define CAE0    0x01    /*bit masks */
#define CAE1    0x02
#define CAE2    0x04
#define CAE3    0x08
#define CAE4    0x10
#define CAE5    0x20
#define CAE6    0x40
#define CAE7    0x80

typedef union uPWMCTL
  { 
  tU08  byte;
  struct
    {
    tU08        :2;     /*not used */
    tU08 pfrz   :1;     /*pwm stops in freeze mode*/
    tU08 pswai  :1;     /*pwm stops in wait mode */
    tU08 con01  :1;     /*concatenate channels 6 & 7 */
    tU08 con23  :1;     /*concatenate channels 6 & 7 */
    tU08 con45  :1;     /*concatenate channels 6 & 7 */
    tU08 con67  :1;     /*concatenate channels 6 & 7 */
    }bit;
  }tPWMCTL;

#define PFRZ    0x04    /*bit masks */
#define PSWAI   0x08
#define CON01   0x10
#define CON23   0x20
#define CON45   0x40
#define CON67   0x80

typedef union uPWMSDN
  {
  tU08  byte;
  struct
    {
    tU08 pwm7en     :1;     /*emergency shutdown enable */
    tU08 pwm7inl    :1;     /*shutdown i/p polarity (ch7) */
    tU08 pwm7in     :1;     /*ch7 i/p pin state */
    tU08            :1;     
    tU08 pwmlvl     :1;     /* shutdown output level */
    tU08 pwmrstrt   :1;     /* restart control */
    tU08 pwmie      :1;     /* pwm interrupt enable */
    tU08 pwmif      :1;     /* pwm interrupt flag */
    }bit;
  }tPWMSDN;

#define PWM7EN      0x01    /*bit masks */
#define PWM7INL     0x02
#define PWM7IN      0x04
#define PWMLVL      0x10
#define PWMRSTRT    0x20
#define PWMIE       0x40
#define PWMIF       0x80

typedef struct                  /*pwm module used on the mscDP256 */
  {
  volatile tPWME    	pwme;       /*pwm enable */
  volatile tPWMPOL  	pwmpol;     /*pwm polarity  */
  volatile tPWMCLK  	pwmclk;     /*pwm clocks select */
  volatile tPWMPRCLK 	pwmprclk;   /*pwm prescale clock select*/
  volatile tPWMCAE  	pwmcae;     /*pwm center align enable*/
  volatile tPWMCTL  	pwmctl;     /*pwm control register */
  volatile tREG08     	pwmtst;     /*pwm special mode test register */
  volatile tREG08     	pwmprsc;    /*pwm reserved register */
  volatile tREG08     	pwmscla;    /*pwm scale register A*/
  volatile tREG08     	pwmsclb;    /*pwm scale register B*/
  volatile tREG08     	pwmscnt[2]; /*pwm reseved test */
  volatile tREG08     	pwmcnt[8];  /*pwm channel counters */
  volatile tREG08     	pwmper[8];  /*pwm channel period counters */
  volatile tREG08     	pwmdty[8];  /*pwm channel duty counters */
  volatile tPWMSDN  	pwmsdn;     /*pwm shutdown register*/
  volatile tREG08     	pwmrsv[3];  /*reserved */
  }tPWM;
#endif /*S12PWM8B8CV1_H */
