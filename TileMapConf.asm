XLIB TileMapConf

; Data for small_sprite_demo.c file
; Raúl Simarro 2008 (artaburu)

XDEF tiles
XDEF pantalla_juego
XDEF tiles_tocados
XDEF posiciones_pantalla
XDEF posiciones_super_buffer

XDEF posicion_inicial_area_visible
XDEF posicion_inicial_superbuffer
XDEF ancho_pantalla_bytes
XDEF alto_pantalla_bytes
XDEF ancho_pantalla_bytes_visible

XDEF mascara2
XDEF mascara1

; VALORES QUE DEFINEN EL BUFFER Y LA PANTALLA
defc posicion_inicial_area_visible = $c056		;Upper left screen addres
defc posicion_inicial_superbuffer = $100	;Start of tile map buffer

;Tile Map dimensions:
defc T_WIDTH =  32  ;max=40		
defc T_HEIGHT = 16  ;max=20

defc mascara1 = 0
defc mascara2 = 0


defc ancho_pantalla_bytes = 2*T_WIDTH 	;Screen width in bytes
defc alto_pantalla_bytes = 8*T_HEIGHT	;Screen height in bytes

defc ancho_pantalla_bytes_visible = 2*T_WIDTH ;dentro del area definida, cuanto se debe mostrar. 2*T_WIDTH

;El tamaño del buffer es ancho_pantalla_bytes*alto_pantalla_bytes
.TileMapConf
.posiciones_pantalla		;Posiciones en las que se dibujan los tiles
defw posicion_inicial_area_visible+$50*0
defw posicion_inicial_area_visible+$50*1  
defw posicion_inicial_area_visible+$50*2
defw posicion_inicial_area_visible+$50*3
defw posicion_inicial_area_visible+$50*4
defw posicion_inicial_area_visible+$50*5 
defw posicion_inicial_area_visible+$50*6 
defw posicion_inicial_area_visible+$50*7 
defw posicion_inicial_area_visible+$50*8 
defw posicion_inicial_area_visible+$50*9 
defw posicion_inicial_area_visible+$50*10 
defw posicion_inicial_area_visible+$50*11 
defw posicion_inicial_area_visible+$50*12 
defw posicion_inicial_area_visible+$50*13 
defw posicion_inicial_area_visible+$50*14 
defw posicion_inicial_area_visible+$50*15
;defw posicion_inicial_area_visible+$50*16
;defw posicion_inicial_area_visible+$50*17
;defw posicion_inicial_area_visible+$50*18
;defw posicion_inicial_area_visible+$50*19 

.posiciones_super_buffer	;muestra el inicio de cada línea (son 10 tiles de 8x16 de alto)

;defw $1000, $1200, $1400, $1600, $1800, $1a00, $1c00, $1e00, $2000, $2200, $2400, $2600, $2800, $2a00, $2c00, $2f00
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*0
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*1
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*2
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*3
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*4
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*5
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*6
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*7
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*8
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*9
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*10
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*11
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*12
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*13
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*14
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*15
;defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*16
;defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*17
;defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*18
;defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*19

.pantalla_actual defw 0
.pantalla_juego  ;en tiles
defs T_WIDTH*T_HEIGHT	;tile map data
defb $FF	;Este byte es importante, marca el fin de la pantalla.

.tiles_tocados defs 150 ;touched tile table

.tiles ;2x8 bytes each tile

;tile 0
defb $00,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$C0
defb $00,$00
;tile 1
defb $3C,$00
defb $3C,$00
defb $00,$3C
defb $00,$3C
defb $3C,$00
defb $3C,$00
defb $00,$3C
defb $00,$3C
;tile 2
defb $00,$00
defb $15,$00
defb $00,$2A
defb $15,$00
defb $00,$2A
defb $15,$00
defb $00,$00
defb $00,$00

;tile 3
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00

;tile 4
defb $80,$40
defb $00,$04
defb $00,$04
defb $00,$08
defb $00,$08
defb $04,$00
defb $04,$00
defb $80,$40

;pared
defb $FF,$D7
defb $FF,$D7
defb $FF,$D7
defb $C3,$C3
defb $FF,$EB
defb $FF,$EB
defb $FF,$EB
defb $C3,$C3