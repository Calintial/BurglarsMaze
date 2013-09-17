XLIB TileMapConf

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


	XDEF mascara1
	XDEF mascara2
	
	; Voy a definir como máscara de los sprites el color 2
	
	; 0: $00, $00
	; 1: $80, $40
	; 2: $04, $08
	; 3: $44, $88
	; 4: $10, $20
	; 5: $50, $A0
	; 6: $14, $28
	; 7: $54, $A8
	; 8: $01, $02
	; 9: $41, $82
	; 10: $05, $0A
	; 11: $45, $8A
	; 12: $11, $22
	
	defc mascara1 = $04 ;
	defc mascara2 = $08 ;


; VALORES QUE DEFINEN EL BUFFER Y LA PANTALLA
defc posicion_inicial_area_visible = $c058
defc posicion_inicial_superbuffer = $100

defc T_WIDTH = 32  ;max=40		;dimensiones de la pantalla en tiles
defc T_HEIGHT = 16 ;max=20


defc ancho_pantalla_bytes = 2*T_WIDTH ; 2*T_WIDTH;		; El ancho de pantalla influye determinantemente en numerosas rutinas que hay que actualizar si se cambia
											; OJO con el modo
defc alto_pantalla_bytes = 8*T_HEIGHT;

defc ancho_pantalla_bytes_visible = 2*T_WIDTH ;32  ; 64;		;dentro del area definida, cuanto se debe mostrar. 2*T_WIDTH

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
defw posicion_inicial_area_visible+$50*16
defw posicion_inicial_area_visible+$50*17
defw posicion_inicial_area_visible+$50*18
defw posicion_inicial_area_visible+$50*19

 

.posiciones_super_buffer	;muestra el inicio de cada línea (son 10 tiles de 8x16 de alto)

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
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*16
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*17
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*18
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*19



.pantalla_actual defw 0
.pantalla_juego  ;en tiles
defs T_WIDTH*T_HEIGHT


defb $FF	;Este byte es importante, marca el fin de la pantalla.

.tiles_tocados defs 150 	;cuando un tile es tocado, se marca en esta tabla para luego restaurarlo. Es una tabla sin duplicados.
	

.tiles ;Son de 2x8 bytes
;tile 0
defb $00,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$C0
defb $00,$00

