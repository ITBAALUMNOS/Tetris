;
NSCMode:	equ	$90		; run in normal single-chip mode.
;
RegBase:	equ	$0000		; base address of I/O register block.
INITRGDF:	equ	$0011		; default (out of reset) address of INITRG (I/O mapping register)
EClock:	equ	24000000		; system clock frequency.
RAMBase:	equ	$1000		; base address of on chip RAM.
RAMSize:	equ	12*1024		; number of bytes of on-chip RAM
EEBase:	equ	$0400		; base address of on-chip EEPROM.
EESize:	equ	3*1024		; number of bytes of on-chip EEPROM.
;
