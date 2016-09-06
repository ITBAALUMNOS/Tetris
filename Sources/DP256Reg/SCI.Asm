;
;
;	SCI Module Register and bit definitions
;
SCI0BD:	equ	+$c8	; SCI 0 baud rate register word.
SCI0BDH:	equ	RegBase+$c8	; SCI 0 baud rate register high byte.
SCI0BDL:	equ	RegBase+$c9	; SCI 0 baud rate register low byte.
SCI0CR1:	equ	RegBase+$ca	; SCI 0 control register 1.
SCI0CR2:	equ	RegBase+$cb	; SCI 0 control register 2.
SCI0SR1:	equ	RegBase+$cc	; SCI 0 status register 1.
SCI0SR2:	equ	RegBase+$cd	; SCI 0 status register 2.
SCI0DRH:	equ	RegBase+$ce	; SCI 0 data register high byte.
SCI0DRL:	equ	RegBase+$cf	; SCI 0 data register low byte.

SCI1BD:	equ	RegBase+$d0	; SCI 1 baud rate register word.
SCI1BDH:	equ	RegBase+$d0	; SCI 1 baud rate register high byte.
SCI1BDL:	equ	RegBase+$d1	; SCI 1 baud rate register low byte.
SCI1CR1:	equ	RegBase+$d2	; SCI 1 control register 1.
SCI1CR2:	equ	RegBase+$d3	; SCI 1 control register 2.
SCI1SR1:	equ	RegBase+$d4	; SCI 1 status register 1.
SCI1SR2:	equ	RegBase+$d5	; SCI 1 status register 2.
SCI1DRH:	equ	RegBase+$d6	; SCI 1 data register high byte.
SCI1DRL:	equ	RegBase+$d7	; SCI 1 data register low byte.
;
;	Bit definitions for the SCIxBDH register
;
BTST:	equ	$80		; reserved for factory test.
BSPL:	equ	$40		; reserved for factory test.
BRDL:	equ	$20		; reserved for factory test.
;
;	Bit definitions for the SCIxCR1 register
;
LOOPS:	equ	$80		; Loop/Single wire mode select.
WOMSCI:	equ	$40		; Tx/Rx pin Open drain enable.
RSRC:	equ	$20		; Select receiver source.
M:	equ	$10		; Data length select control bit.
WAKE:	equ	$08		; Address Mark/Idle Line wake-up mode select.
ILT:	equ	$04		; short/long idle line wake-up mode select.
PE:	equ	$02		; parity enable/disable control bit.
PT:	equ	$01		; odd/even parity select control bit.
;
;	Bit definitions for the SCIxCR2 register
;
TIE:	equ	$80		; Transmit interrupt enable.
TCIE:	equ	$40		; Transmit complete interrupt enable.
RIE:	equ	$20		; Receive interrupt enable.
ILIE:	equ	$10		; Idle line interrupt enable.
TE:	equ	$08		; Transmitter enable.
RE:	equ	$04		; Receiver enable.
RWU:	equ	$02		; Receiver wake-up mode enable.
SBK:	equ	$01		; Send break control bit.
;
;	Bit definitions for the SCIxSR1 register
;
TDRE:	equ	$80		; Transmit data register empty status bit.
TC:	equ	$40		; Transmit data complete flag.
RDRF:	equ	$20		; Receive data register full flag.
IDLE:	equ	$10		; Receiver idle line detect flag.
OR:	equ	$08		; Receiver data overrun flag.
NF:	equ	$04		; Noise detect flag.
FE:	equ	$02		; Framing error flag.
PF:	equ	$01		; Parity error flag.
;
;	Bit definitions for the SCIxSR2 register
;
RAF:	equ	$01		; receiver active flag.
TXDIR:	equ	$02
;
;	Bit definitions for the SCIxDRH register
;
R8:	equ	$80		; Received Ninth data bit.
T8:	equ	$40		; Transmitted Ninth data bit.
;
