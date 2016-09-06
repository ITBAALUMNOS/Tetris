;
;
;	MMC Module Register and bit definitions
;
INITRM:	equ	RegBase+$0010
INITRG:	equ	RegBase+$0011
INITEE:	equ	RegBase+$0012
MISC:	equ	RegBase+$0013
MTST0:	equ	RegBase+$0014
MTST1:	equ	RegBase+$0017
MEMSIZ0:	equ	RegBase+$001c
MEMSIZ1:	equ	RegBase+$001d
;
;	Bit definitions for the INITRM register
;
RAMHAL:	equ	$01
;
;	Bit definitions for the INITEE register
;
EEON:	equ	$01
;
;	Bit definitions for the MISC register
;
ROMHM:	equ	$02
ROMON:	equ	$01
;
