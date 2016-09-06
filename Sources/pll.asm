RegBase:	equ	$0000	 	
;                       
;		xdef  pll_init    MOVED TO END OF FILE TO PREVENT WARNING        
		include	"CRG.Asm"

OscClk:	equ	16000000
Eclock:	equ	40000000		; final E-clock frequency (PLL)
RefClock:	equ	8000000
;
REFDVVal:	equ	(OscClk/RefClock)-1	
SYNRVal:	equ	(Eclock/RefClock)-1

           

DEFAULT_ROM  	SECTION   

pll_init 	equ	*
 
     	
 		ldab	#REFDVVal		; set the REFDV register to give us a 1.0 MHz reference.
		stab	REFDV
		ldab	#SYNRVal		; set the SYNR register to give us a 24.0 MHz E-clock.
		stab	SYNR
		nop			; nops required for bug in initial silicon.
		nop
		nop
		nop
		brclr	CRGFLG,#LOCK,*		; wait here till the PLL is locked.	
		bset	CLKSEL,#PLLSEL		; switch the bus clock to the PLL.

		rts
		
		xdef pll_init