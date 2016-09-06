;
;
;	PIM Module Register and bit definitions
;
PORTT:	equ	RegBase+$0240	; Port T data register (alternate name).
PTT:	equ	RegBase+$0240	; Port T data register.
PTIT:	equ	RegBase+$0241	; Port T input pin register.
DDRT:	equ	RegBase+$0242	; Port T data direction register.
RDRT:	equ	RegBase+$0243	; Port T Reduced drive enable register.
PERT:	equ	RegBase+$0244	; Port T pull up/down enable register.
PPST:	equ	RegBase+$0245	; Port T pull up/down select (polarity) register.
;
PORTS:	equ	RegBase+$0248	; Port S data register (alternate name).
PTS:	equ	RegBase+$0248	; Port S data register.
PTIS:	equ	RegBase+$0249	; Port S input pin register.
DDRS:	equ	RegBase+$024a	; Port S data direction register.
RDRS:	equ	RegBase+$024b	; Port S Reduced drive enable register.
PERS:	equ	RegBase+$024c	; Port S pull up/down enable register.
PPSS:	equ	RegBase+$024d	; Port S pull up/down select (polarity) register.
WOMS:	equ	RegBase+$024e	; Port S Wired-Or (open drain) select register.
;
PORTM:	equ	RegBase+$0250	; Port M data register (alternate name).
PTM:	equ	RegBase+$0250	; Port M data register.
PTIM:	equ	RegBase+$0251	; Port M input pin register.
DDRM:	equ	RegBase+$0252	; Port M data direction register.
RDRM:	equ	RegBase+$0253	; Port M Reduced drive enable register.
PERM:	equ	RegBase+$0254	; Port M pull up/down enable register.
PPSM:	equ	RegBase+$0255	; Port M pull up/down select (polarity) register.
WOMM:	equ	RegBase+$0256	; Port M Wired-Or (open drain) select register.
;
PORTP:	equ	RegBase+$0258	; Port P data register (alternate name).
PTP:	equ	RegBase+$0258	; Port P data register.
PTIP:	equ	RegBase+$0259	; Port P input pin register.
DDRP:	equ	RegBase+$025a	; Port P data direction register.
RDRP:	equ	RegBase+$025b	; Port P Reduced drive enable register.
PERP:	equ	RegBase+$025c	; Port P pull up/down enable register.
PPSP:	equ	RegBase+$025d	; Port P pull up/down select (polarity) register.
PIEP:	equ	RegBase+$025e	; Port P interrupt enable register.
PIFP:	equ	RegBase+$025f	; Prot P interrupt Flag register.
;
PORTH:	equ	RegBase+$0260	; Port H data register (alternate name).
PTH:	equ	RegBase+$0260	; Port H data register.
PTIH:	equ	RegBase+$0261	; Port H input pin register.
DDRH:	equ	RegBase+$0262	; Port H data direction register.
RDRH:	equ	RegBase+$0263	; Port H Reduced drive enable register.
PERH:	equ	RegBase+$0264	; Port H pull up/down enable register.
PPSH:	equ	RegBase+$0265	; Port H pull up/down select (polarity) register.
PIEH:	equ	RegBase+$0266	; Port H interrupt enable register.
PIFH:	equ	RegBase+$0267	; Prot H interrupt Flag register.
;
PORTJ:	equ	RegBase+$0268	; Port J data register (alternate name).
PTJ:	equ	RegBase+$0268	; Port J data register.
PTIJ:	equ	RegBase+$0269	; Port J input pin register.
DDRJ:	equ	RegBase+$026a	; Port J data direction register.
RDRJ:	equ	RegBase+$026b	; Port J Reduced drive enable register.
PERJ:	equ	RegBase+$026c	; Port J pull up/down enable register.
PPSJ:	equ	RegBase+$026d	; Port J pull up/down select (polarity) register.
PIEJ:	equ	RegBase+$026e	; Port J interrupt enable register.
PIFJ:	equ	RegBase+$026f	; Prot J interrupt Flag register.
;
