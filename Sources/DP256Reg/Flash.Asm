;
;	Flash Module Register and bit definitions
;
FCLKDIV:	equ	RegBase+$0100	; Flash clock divider register.
FSEC:	equ	RegBase+$0101	; Flash security register.
FCNFG:	equ	RegBase+$0103	; Flash configuration register.
FPROT:	equ	RegBase+$0104	; Flash protection register.
FSTAT:	equ	RegBase+$0105	; Flash status register.
FCMD:	equ	RegBase+$0106	; Flash command buffer & command register.
;
;	EEPROM Module Register and bit definitions
;
ECLKDIV:	equ	RegBase+$0110	; EEPROM clock divider register.
ECNFG:	equ	RegBase+$0113	; EEPROM configuration register.
EPROT:	equ	RegBase+$0114	; EEPROM protection register.
ESTAT:	equ	RegBase+$0115	; EEPROM status register.
ECMD:	equ	RegBase+$0116	; EEPROM command buffer & command register.
;
;	Bit definitions for the ECLKDV register
;
EDIVLD:	equ	$80	; EEPROM clock divider register loaded.
PRDIV8:	equ	$40	; Enable /8 prescaler.
;
;
;	Bit definitions for the FCLKDV register
;
FDIVLD:	equ	$80	; Flash clock divider register loaded.
FDIV8:	equ	$40	; Enable /8 prescaler.
;
;	Bit definitions for the FSEC register
;
KEYEN:	equ	$80	; Enable access to security key.
;
;	Bit definitions for the ECNFG/FCNFG register
;
CBEIE:	equ	$80	; Command Buffer Empty Interrupt Enable.
CCIE:	equ	$40	; Command complete interrupt enable.
KEYACC:	equ	$20	; Enable security key writing.
;
;	Bit definitions for the FPROT register
;
FPOPEN:	equ	$80	; Enable (open) a Flash block for program or erase.
FPHDIS:	equ	$20
FPLDIS:	equ	$04
;
;	Bit definitions for the EPROT register
;
EPOPEN:	equ	$80	; Enable (open) a Flash block for program or erase.
EPDIS:	equ	$08
;
;	Bit definitions for the FSTAT register
;
CBEIF:	equ	$80	; Command buffers empty interrupt flag.
CCIF:	equ	$40	; Command complete interrupt flag.
PVIOL:	equ	$20	; Protection violation flag.
ACCERR:	equ	$10	; Flash access error.
BLANK:	equ	$04	; Flash block blank flag.
;
;	Bit definitions for the FCMD register
;
ERASE:	equ	$40	; Erase Flash command bit.
PROG:	equ	$20	; Program Flash command bit.
ERVER:	equ	$04	; Erase verify command enable bit.
MASS:	equ	$01	; Mass (Bulk) erase command bit.
;
