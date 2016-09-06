;
;
;	ECT Module Register and bit definitions
;

TIOS:  equ RegBase+$40 ;timer input/output select
CFORC: equ RegBase+$41 ;timer compare force
OC7M:  equ RegBase+$42 ;timer output compare 7 mask
OC7D:  equ RegBase+$43 ;timer output compare 7 data
TCNT:  equ RegBase+$44 ;timer counter register hi
*TCNT: equ RegBase+$45 ;timer counter register lo
;
TSCR1: equ RegBase+$46 ;timer system control register 1
TTOV:  equ RegBase+$47 ;reserved
;
TCTL1: equ RegBase+$48 ;timer control register 1
TCTL2: equ RegBase+$49 ;timer control register 2
TCTL3: equ RegBase+$4A ;timer control register 3
TCTL4: equ RegBase+$4B ;timer control register 4
;
TIER:   equ RegBase+$4C ;timer interrupt enable register
TSCR2: equ RegBase+$4D ;timer system control register 2
TFLG1: equ RegBase+$4E ;timer flags 1
TFLG2: equ RegBase+$4F ;timer flags 2
;

TC0: equ RegBase+$50 ;timer capture/compare register 0
*TC0: equ RegBase+$51 ;
TC1: equ RegBase+$52 ;timer capture/compare register 1
*TC1: equ RegBase+$53 ;
TC2: equ RegBase+$54 ;timer capture/compare register 2
*TC2: equ RegBase+$55 ;
TC3: equ RegBase+$56 ;timer capture/compare register 3
*TC3: equ RegBase+$57 ;
TC4: equ RegBase+$58 ;timer capture/compare register 4
*TC4: equ RegBase+$59 ;
TC5: equ RegBase+$5A ;timer capture/compare register 5
*TC5: equ RegBase+$5B ;
TC6: equ RegBase+$5C ;timer capture/compare register 6
*TC6: equ RegBase+$5D ;
TC7: equ RegBase+$5E ;timer capture/compare register 7
*TC7: equ RegBase+$5F ;

;
PACTL: equ RegBase+$60 ;pulse accumulator control
PAFLG: equ RegBase+$61 ;pulse accumulator flags
;
PACN3: equ RegBase+$62 ;pulse accumulator counter 3
PACN2: equ RegBase+$63 ;pulse accumulator counter 2
PACN1: equ RegBase+$64 ;pulse accumulator counter 1
PACN0: equ RegBase+$65 ;pulse accumulator counter 0
;
MCCTL: equ RegBase+$66 ;Modulus down conunter control
MCFLG: equ RegBase+$67 ;down counter flags
ICPAR: equ RegBase+$68 ;Input pulse accumulator control
DLYCT: equ RegBase+$69 ;Delay count to down counter
ICOVW: equ RegBase+$6A ;Input control overwrite register
ICSYS: equ RegBase+$6B ;Input control system control
;
TIMTST: equ RegBase+$6D ;timer test register
;
PBCTL: equ RegBase+$70 ; Pulse accumulator B control
PBFLG: equ RegBase+$71 ; Pulse accumulator B flags
;
PA3H: equ RegBase+$72 ; Pulse Accumulator holding register 3
PA2H: equ RegBase+$73 ; Pulse Accumulator holding register 2
PA1H: equ RegBase+$74 ; Pulse Accumulator holding register 1
PA0H: equ RegBase+$75 ; Pulse Accumulator holding register 0
;
MCCNT: equ RegBase+$76 ; Modulus down counter register
*MCCNTL: equ RegBase+$77 ; low byte
;
TCOH: equ RegBase+$78 ; Capture 0 holding register
TC1H: equ RegBase+$7A ; Capture 1 holding register
TC2H: equ RegBase+$7C ; Capture 2 holding register
TC3H: equ RegBase+$7E ; Capture 3 holding register



CH7     equ     1 << 7
CH6     equ     1 << 6
CH5     equ     1 << 5
CH4     equ     1 << 4
CH3     equ     1 << 3
CH2     equ     1 << 2
CH1     equ     1 << 1
CH0     equ     1 << 0


;Prescaler selection

DIVX1   equ     0
DIVX2   equ     1
DIVX4   equ     2
DIVX8   equ     3
DIVX16  equ     4
DIVX32  equ     5
DIVX64  equ     6
DIVX128 equ     7


;OM OL bit definition

;TCTL1

OM7	EQU	7   ;OMX OLX CONFIGURACION	
OL7	EQU	6   ;0	0  Desabilitado  	
OM6	EQU	5   ;0	1  Cambia al estado contrario por cada comparacion
OL6	EQU	4   ;1	0  Clear	
OM5	EQU	3   ;1	1  Set	
OL5	EQU	2
OM4	EQU	1
OL4	EQU	0

;TCTL2

OM3	EQU	7   ;OMX OLX CONFIGURACION	
OL3	EQU	6   ;0	0  Desabilitado  	
OM2	EQU	5   ;0	1  Cambia al estado contrario por cada comparacion
OL2	EQU	4   ;1	0  Clear	
OM1	EQU	3   ;1	1  Set	
OL1	EQU	2
OM0	EQU	1
OL0	EQU	0

OCDIS		EQU	0
TOGGLE	EQU	1
OCCLR		EQU	2
OCSET		EQU	3





