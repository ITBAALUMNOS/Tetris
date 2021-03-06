;
;
;	CRG Module Register and bit definitions
;
SYNR:	equ	RegBase+$0034	; synthesizer loop divider register.
REFDV:	equ	RegBase+$0035	; reference divider register.
CTFLG:	equ	RegBase+$0036	;
CRGFLG:	equ	RegBase+$0037	; CRG flag register.
CRGINT:	equ	RegBase+$0038	; CRG interrupt flag register.
CLKSEL:	equ	RegBase+$0039	; CRG clock select register.
PLLCTL:	equ	RegBase+$003a
RTICTL:	equ	RegBase+$003b	; RTI control register
COPCTL:	equ	RegBase+$003c	; COP Watchdog control register.
FORBYP:	equ	RegBase+$003d	; GRC prescaler bypass control register.
CTCTL:	equ	RegBase+$003e	;
ARMCOP:	equ	RegBase+$003f	; COP reset register.
;
;	Bit definitions for the CRGFLG register
;
RTIF:	equ	$80
PROF:	equ	$40
LOCKIF:	equ	$10
LOCK:	equ	$08
TRACK:	equ	$04
SCMIF:	equ	$02
SCM:	equ	$01
;
;	Bit definitions for the CRGINT register
;
RTIE:	equ	$80
LOCKIE:	equ	$10
SCMIE:	equ	$02
;
;	Bit definitions for the CLKSEL register
;
PLLSEL:	equ	$80	; use PLL for system clocks.
PSTP:	equ	$40
SYSWAI:	equ	$20
ROAWAI:	equ	$10
PLLWAI:	equ	$08
CWAI:	equ	$04
RTIWAI:	equ	$02
COPWAI:	equ	$01
;
;	Bit definitions for the PLLCTL register
;
CME:	equ	$80
PLLON:	equ	$40	; PLL on/off control bit.
AUTO:	equ	$20	; auto/manual acquisiton mode.
ACQ:	equ	$10
SCME:	equ	$01
;
;	Bit definitions for the COPCTL register
;
WCOP:	equ	$80
;
;	Bit definitions for the FORBYP register
;
RTIBYP:	equ	$80
COPBYP:	equ	$40
PLLBYP:	equ	$10
FCM:	equ	$02
;
