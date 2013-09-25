extern unsigned char moneda[];
extern unsigned char champ[];
extern unsigned char cuadrado[];
extern unsigned char cuadrado2[];
extern unsigned char ladron[];
extern unsigned char ladronarriba[];
extern unsigned char ladronder[];
extern unsigned char ladronizq[];
extern unsigned char ladronpeq[];
extern unsigned char bomba[];
extern unsigned char explosion[];
extern unsigned char sprite3[];

#asm
._moneda
defb 4,16
defb $00,$40,$80,$00
defb $00,$C0,$C0,$00
defb $00,$C0,$C0,$00
defb $40,$C0,$C0,$80
defb $40,$30,$C0,$80
defb $C0,$30,$C0,$C0
defb $90,$30,$C0,$C0
defb $90,$60,$C0,$C0
defb $C0,$C0,$C0,$C0
defb $C0,$C0,$C0,$C0
defb $C0,$C0,$C0,$60
defb $C0,$C0,$90,$60
defb $40,$C0,$30,$80
defb $40,$C0,$60,$80
defb $00,$C0,$C0,$00
defb $00,$40,$80,$00

._champ
defb 2,8
defb $40,$80
defb $C4,$C0
defb $C0,$C4
defb $C0,$C0
defb $41,$82
defb $41,$82
defb $41,$82
defb $41,$82

._cuadrado
defb 4,16
defb $00,$40,$80,$00
defb $00,$C0,$C0,$00
defb $00,$C0,$C0,$00
defb $40,$C0,$C0,$80
defb $40,$30,$C0,$80
defb $C0,$30,$C0,$C0
defb $90,$30,$C0,$C0
defb $90,$60,$C0,$C0
defb $C0,$C0,$C0,$C0
defb $C0,$C0,$C0,$C0
defb $C0,$C0,$C0,$60
defb $C0,$C0,$90,$60
defb $40,$C0,$30,$80
defb $40,$C0,$60,$80
defb $00,$C0,$C0,$00
defb $00,$40,$80,$00

._cuadrado2
defb 4,16
defb $00,$00,$00,$00
defb $00,$00,$00,$00
defb $00,$00,$00,$00
defb $00,$00,$00,$00
defb $00,$00,$00,$00
defb $00,$40,$80,$00
defb $00,$C0,$C0,$00
defb $00,$80,$40,$00
defb $00,$80,$40,$00
defb $00,$80,$40,$00
defb $00,$80,$40,$00
defb $00,$C0,$C0,$00
defb $00,$00,$00,$00
defb $00,$00,$00,$00
defb $00,$00,$00,$00
defb $00,$00,$00,$00

._ladron
defb 2,16
defb $50,$A0
defb $50,$A0
defb $F0,$F0
defb $F0,$F0
defb $B0,$70
defb $B0,$70
defb $F0,$F0
defb $F0,$F0
defb $FF,$FF
defb $FF,$FF
defb $55,$AA
defb $55,$AA
defb $50,$A0
defb $50,$A0
defb $F0,$F0
defb $F0,$F0

._ladronder
defb 2,16
defb $50,$A0
defb $50,$A0
defb $F0,$F0
defb $F0,$F0
defb $F0,$30
defb $F0,$30
defb $F0,$F0
defb $F0,$F0
defb $FF,$FF
defb $FF,$FF
defb $FF,$AA
defb $FF,$AA
defb $F0,$A0
defb $F0,$A0
defb $F0,$F0
defb $F0,$F0

._ladronizq
defb 2,16
defb $50,$A0
defb $50,$A0
defb $F0,$F0
defb $F0,$F0
defb $30,$F0
defb $30,$F0
defb $F0,$F0
defb $F0,$F0
defb $FF,$FF
defb $FF,$FF
defb $55,$FF
defb $55,$FF
defb $50,$F0
defb $50,$F0
defb $F0,$F0
defb $F0,$F0

._ladronarriba
defb 2,16
defb $50,$A0
defb $50,$A0
defb $F0,$F0
defb $F0,$F0
defb $F0,$F0
defb $F0,$F0
defb $F0,$F0
defb $F0,$F0
defb $FF,$FF
defb $FF,$FF
defb $55,$AA
defb $55,$AA
defb $50,$A0
defb $50,$A0
defb $F0,$F0
defb $F0,$F0


._ladronpeq
defb 2,8
defb $50,$A0
defb $F0,$F0
defb $B0,$70
defb $F0,$F0
defb $FF,$FF
defb $55,$AA
defb $50,$A0
defb $F0,$F0

._sprite3
defb $4, $10
._sprite3_DATA
defb $F, $4E, $A7, $F
defb $F, $CD, $FC, $F
defb $F, $59, $33, $F
defb $4E, $DB, $62, $F
defb $E, $F3, $F9, $AD
defb $4E, $F3, $F3, $F6
defb $F, $59, $F3, $F3
defb $F, $D9, $F3, $AF
defb $F, $5C, $A7, $7
defb $F, $D1, $F6, $F
defb $F, $FC, $F3, $F
defb $8F, $DE, $F3, $F
defb $F6, $E2, $F6, $F
defb $F9, $F3, $AD, $F
defb $5B, $F6, $20, $F
defb $F, $A, $30, $F

._bomba
defb 4,16
defb $00,$00,$FF,$AA
defb $00,$55,$AA,$00
defb $00,$F0,$F0,$00
defb $50,$F0,$F0,$A0
defb $50,$30,$F0,$A0
defb $F0,$30,$F0,$F0
defb $F0,$30,$F0,$F0
defb $F0,$F0,$F0,$F0
defb $F0,$F0,$F0,$F0
defb $F0,$F0,$F0,$F0
defb $F0,$F0,$F0,$F0
defb $F0,$F0,$F0,$F0
defb $50,$F0,$F0,$A0
defb $50,$F0,$F0,$A0
defb $00,$F0,$F0,$00
defb $00,$50,$A0,$00

._explosion
defb 4,16
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4
defb $C8,$C8,$C8,$C8
defb $C4,$C4,$C4,$C4

#endasm