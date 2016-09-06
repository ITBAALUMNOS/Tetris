;
;	MEBI Module Register and bit definitions
;
PORTA:	equ	RegBase+$0000	; Port A data register.
PORTB:	equ	RegBase+$0001	; Port B data register.
DDRA:	equ	RegBase+$0002	; Port A data direction register.
DDRB:	equ	RegBase+$0003	; Port B data direction register.
PORTE:	equ	RegBase+$0008	; Port E data register.
DDRE:	equ	RegBase+$0009	; Port E data direction register.
PEAR:	equ	RegBase+$000a	; Port E pin asignment register.
MODE:	equ	RegBase+$000b	; CPU operating mode select register.
PUCR:	equ	RegBase+$000c	; Port A, B, E & K pullup control register.
RDRIV:	equ	RegBase+$000d	; Port A, B, E & K drive reduction control register.
EBICTL:	equ	RegBase+$000e	; External Bus Interface control register.
INTCR:	equ	RegBase+$001e	; External IRQ interrupt control register.
PPAGE:	equ	RegBase+$0030	
PORTK:	equ	RegBase+$0032
DDRK:	equ	RegBase+$0033
;
;
;	Bit definitions for the PEAR register
;
NNOACCE:	equ	$80		; enable/disable the NNOACCE control signal on pin PE7.
PIPOE:	equ	$20		; enable/disable pipe signals on pins PE5 & PE6.
NECLK:	equ	$10		; enable/disable the E-clock on pin PE4.
LSTRE:	equ	$08		; enable/disable the low strobe signal on pin PE3.
RDWE:	equ	$04		; enable/disable the R/w signal onpin PE2.
;
;
;	Bit definitions for the MODE register
;
MODC:	equ	$80		; Special mode select bit.
MODB:	equ	$40		; Mode control 'B' bit.
MODA:	equ	$20		; Mode control 'A' bit.
IVIS:	equ	$08		; Internal visibility enable bit.
EMK:	equ	$01		; Emulate port E control bit.
EME:	equ	$01		; Emulate port E control bit.
;
;
;	Bit definitions for the PUCR register
;
PUPKE:	equ	$80		; Port K pullup enable control bit.
PUPEE:	equ	$10		; Port E pullup enable control bit.
PUPBE:	equ	$02		; Port B pullup enable control bit.
PUPAE:	equ	$01		; Port A pullup enable control bit.
;
;
;	Bit definitions for the RDRIV register
;
RDPK:	equ	$80		; Port K reduced drive control bit.
RDPE:	equ	$10		; Port E reduced drive control bit.
RDPB:	equ	$02		; Port B reduced drive control bit.
RDPA:	equ	$01		; Port A reduced drive control bit.
;
;
;
;	Bit definitions for the EBICTL register
;
ESTR:	equ	$01		;