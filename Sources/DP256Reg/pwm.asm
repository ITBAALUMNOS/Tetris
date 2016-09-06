PWME: EQU RegBase+$A0 ;PWM enable
PWMPOL: EQU RegBase+$A1 ;PWM polarity
PWMCLK: EQU RegBase+$A2 ;PWM clock select register
PWMPRCLK: EQU RegBase+$A3 ;PWM Prescale clock select register
PWMCAE: EQU RegBase+$A4 ;PWM center align select register
PWMCTL: EQU RegBase+$A5 ;PWM control register
PWMTST: EQU RegBase+$A6 ;reserved
PWMPRSC: EQU RegBase+$A7 ;reserved
PWMSCLA: EQU RegBase+$A8 ;PWM Scale A
PWMSCLB: EQU RegBase+$A9 ;PWM scale B
PWMSCNTA: EQU RegBase+$AA ;reserved
PWMSCNTB: EQU RegBase+$AB ;reserved
PWMCNT0: EQU RegBase+$AC ;PWM channel 0 counter
PWMCNT1: EQU RegBase+$AD ;PWM channel 1 counter
PWMCNT2: EQU RegBase+$AE ;PWM channel 2 counter
PWMCNT3: EQU RegBase+$AF ;PWM channel 3 counter
PWMCNT4: EQU RegBase+$B0 ;PWM channel 4 counter
PWMCNT5: EQU RegBase+$B1 ;PWM channel 5 counter
PWMCNT6: EQU RegBase+$B2 ;PWM channel 6 counter
PWMCNT7: EQU RegBase+$B3 ;PWM channel 7 counter
PWMPER0: EQU RegBase+$B4 ;PWM channel 0 period
PWMPER1: EQU RegBase+$B5 ;PWM channel 1 period
PWMPER2: EQU RegBase+$B6 ;PWM channel 2 period
PWMPER3: EQU RegBase+$B7 ;PWM channel 3 period
PWMPER4: EQU RegBase+$B8 ;PWM channel 4 period
PWMPER5: EQU RegBase+$B9 ;PWM channel 5 period
PWMPER6: EQU RegBase+$BA ;PWM channel 6 period
PWMPER7: EQU RegBase+$BB ;PWM channel 7 period
PWMDTY0: EQU RegBase+$BC ;PWM channel 0 duty cycle
PWMDTY1: EQU RegBase+$BD ;PWM channel 1 duty cycle
PWMDTY2: EQU RegBase+$BE ;PWM channel 2 duty cycle
PWMDTY3: EQU RegBase+$BF ;PWM channel 3 duty cycle
PWMDTY4: EQU RegBase+$C0 ;PWM channel 0 duty cycle
PWMDTY5: EQU RegBase+$C1 ;PWM channel 1 duty cycle
PWMDTY6: EQU RegBase+$C2 ;PWM channel 2 duty cycle
PWMDTY7: EQU RegBase+$C3 ;PWM channel 3 duty cycle
PWMSDN: EQU RegBase+$C4 ;PWM shutdown register


PWM7     equ     7 
PWM6     equ     6 
PWM5     equ     5 
PWM4     equ     4 
PWM3     equ     3 
PWM2     equ     2 
PWM1     equ     1 
PWM0     equ     0 



;Polarity bits

CPOL_HIGH	equ	1
CPOL_LOW	equ	0

;PWM Clock Select bits (PWMCLK)

SEL_CLK_SB_7	equ	1 	 ;Source Clock B Scaled
SEL_CLK_B_7		equ	0	 ;Source Clock B 

SEL_CLK_SB_6	equ	1 
SEL_CLK_B_6		equ	0

SEL_CLK_SA_5	equ	1 
SEL_CLK_A_5		equ	0

SEL_CLK_SA_4	equ	1 
SEL_CLK_A_4		equ	0

SEL_CLK_SB_3	equ	1 
SEL_CLK_B_3		equ	0

SEL_CLK_SB_2	equ	1 
SEL_CLK_B_2		equ	0

SEL_CLK_SA_1	equ	1 
SEL_CLK_A_1		equ	0

SEL_CLK_SA_0	equ	1 
SEL_CLK_A_0		equ	0


;PWM  Prescale Clock Select bits (PWMPRCLK)

BUS_CLK_1		equ	0 
BUS_CLK_2		equ	1 
BUS_CLK_4		equ	2 
BUS_CLK_8		equ	3 
BUS_CLK_16        equ	4 
BUS_CLK_32        equ	5 
BUS_CLK_64        equ	6 
BUS_CLK_128       equ	7 

CLK_A			equ	0	;Bits 0-2
CLK_B			equ	4	;bits 4-6


;********************************************************************
;Try to do things tidy and neat  !!!!!!!!

;Sample Code  
;
;1-  Clk A is BUS CLOCK /64
;
;     movb	  #(BUS_CLK_64 << CLK_A),PWMPRCLK
;     
;2- Clk A is BUS CLOCK /4 while Clk B is BUS_CLK /16
;
;     movb	  #((BUS_CLK_4 << CLK_A)|(BUS_CLK_16 << CLK_B)),PWMPRCLK
;
; Don't make this  "movb  #10101010b,PWMPRCLK " !!!!!!!!!
;
;Daniel
;********************************************************************



;PWM Center align bits enable (PWMCAE)

CENTER	equ	1
LEFT		equ	0

;Sample Code  
;
;1-  Channel 7 is left aligned
;
;     movb	  #(LEFT << PWM7),PWMCAE
;

;PWM Control bits  (PWMCTL)

CON67		equ	$80
CON45		equ	$40
CON23		equ	$20
CON01		equ	$10

;Sample Code  
;
;1-  Channel 6 and 7 are concatenated
;
;     movb	  #CON67,PWMCAE  ; 
;
;2-  Channel 4 and 5 are concatenated also are channel 6 and 7
;
;     movb	  #(CON67|CON45),PWMCAE  ; 
;














