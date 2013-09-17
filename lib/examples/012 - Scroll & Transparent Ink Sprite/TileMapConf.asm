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


; ***************************************************
; Transparent colour for cpc_PutTrSpTileMap2b routine
XDEF mascara1
XDEF mascara2
; ***************************************************


;XDEF tile
; ***************************************************
; Scroll Left Addresses column
; not requiered if scroll not used
XDEF ColumnScr
; ***************************************************


; ***************************************************
; Transparent colour for cpc_PutTrSpTileMap2b routine
; For printing sprites using transparent color (mode 0) transparent color selection is requiered. 
; Selección color transparente. Escribir las 2 máscaras que correspondan al color elegido.
;Example colour number 7:
defc mascara1 = $54	
defc mascara2 = $a8
;0: $00, $00
;1: $80, $40
;2: $04, $08
;3: $44, $88
;4: $10, $20
;5: $50, $A0
;6: $14, $28
;7: $54, $A8
;8: $01, $02
;9: $41, $82
;10: $05, $0A
;11: $45, $8A
;12: $11, $22
;13: $51, $A2
;14: $15, $2A
;15: $55, $AA
; ***************************************************




;------------------------------------------------------------------------------------
; SCREEN AND BUFFER ADDRESSES
; VALORES QUE DEFINEN EL BUFFER Y LA PANTALLA
;------------------------------------------------------------------------------------

defc posicion_inicial_area_visible = $c0AA
defc posicion_inicial_superbuffer = $100
;------------------------------------------------------------------------------------

;------------------------------------------------------------------------------------
; TILE MAP DIMENSIONS
;------------------------------------------------------------------------------------

defc T_WIDTH = 30 			;max=40		;dimensiones de la pantalla en tiles
defc T_HEIGHT = 18			;max=20
;------------------------------------------------------------------------------------


;------------------------------------------------------------------------------------
; Other parameters (internal use)
;------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------

defc ancho_pantalla_bytes = 2*T_WIDTH ; 2*T_WIDTH;		; El ancho de pantalla influye determinantemente en numerosas rutinas que hay que actualizar si se cambia
											; OJO con el modo
defc alto_pantalla_bytes = 8*T_HEIGHT;
defc ancho_pantalla_bytes_visible = 2*T_WIDTH ;32  ; 64;		;dentro del area definida, cuanto se debe mostrar. 2*T_WIDTH

;El tamaño del buffer es ancho_pantalla_bytes*alto_pantalla_bytes

.TileMapConf
;------------------------------------------------------------------------------------
;Con la definición del mapeado hay que tener en cuenta que las coordenadas son:
;ANCHO=64 bytes (128 pixels en modo 0)
;ALTO=128 pixels
;el máximo que entra en el CPC es 20 líneas
;SI NO SE VAN A USAR TODAS LAS LINEAS, PARA AHORRA MEMORIA ES INTERESANTE COMENTARLAS
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




; ***************************************************
; Scroll Left Addresses column
; not requiered if scroll not used comment it ;)
.ColumnScr
defw $C0AA
defw $C8AA
defw $D0AA
defw $D8AA
defw $E0AA
defw $E8AA
defw $F0AA
defw $F8AA
defw $C0FA
defw $C8FA
defw $D0FA
defw $D8FA
defw $E0FA
defw $E8FA
defw $F0FA
defw $F8FA
defw $C14A
defw $C94A
defw $D14A
defw $D94A
defw $E14A
defw $E94A
defw $F14A
defw $F94A
defw $C19A
defw $C99A
defw $D19A
defw $D99A
defw $E19A
defw $E99A
defw $F19A
defw $F99A
defw $C1EA
defw $C9EA
defw $D1EA
defw $D9EA
defw $E1EA
defw $E9EA
defw $F1EA
defw $F9EA
defw $C23A
defw $CA3A
defw $D23A
defw $DA3A
defw $E23A
defw $EA3A
defw $F23A
defw $FA3A
defw $C28A
defw $CA8A
defw $D28A
defw $DA8A
defw $E28A
defw $EA8A
defw $F28A
defw $FA8A
defw $C2DA
defw $CADA
defw $D2DA
defw $DADA
defw $E2DA
defw $EADA
defw $F2DA
defw $FADA
defw $C32A
defw $CB2A
defw $D32A
defw $DB2A
defw $E32A
defw $EB2A
defw $F32A
defw $FB2A
defw $C37A
defw $CB7A
defw $D37A
defw $DB7A
defw $E37A
defw $EB7A
defw $F37A
defw $FB7A
defw $C3CA
defw $CBCA
defw $D3CA
defw $DBCA
defw $E3CA
defw $EBCA
defw $F3CA
defw $FBCA
defw $C41A
defw $CC1A
defw $D41A
defw $DC1A
defw $E41A
defw $EC1A
defw $F41A
defw $FC1A
defw $C46A
defw $CC6A
defw $D46A
defw $DC6A
defw $E46A
defw $EC6A
defw $F46A
defw $FC6A
defw $C4BA
defw $CCBA
defw $D4BA
defw $DCBA
defw $E4BA
defw $ECBA
defw $F4BA
defw $FCBA
defw $C50A
defw $CD0A
defw $D50A
defw $DD0A
defw $E50A
defw $ED0A
defw $F50A
defw $FD0A
defw $C55A
defw $CD5A
defw $D55A
defw $DD5A
defw $E55A
defw $ED5A
defw $F55A
defw $FD5A
defw $C5AA
defw $CDAA
defw $D5AA
defw $DDAA
defw $E5AA
defw $EDAA
defw $F5AA
defw $FDAA
defw $C5FA
defw $CDFA
defw $D5FA
defw $DDFA
defw $E5FA
defw $EDFA
defw $F5FA
defw $FDFA
; ***************************************************


.pantalla_actual defw 0
.pantalla_juego  ;en tiles
defs T_WIDTH*T_HEIGHT
defb $FF	;Este byte es importante, marca el fin de la pantalla.
.tiles_tocados defs 150 ;150	;cuando un tile es tocado, se marca en esta tabla para luego restaurarlo. Es una tabla sin duplicados.

;------------------------------------------------------------------------------------
; TILE DATA. TILES MUST BE DEFINED HERE
;------------------------------------------------------------------------------------
	

.tiles ;Son de 2x8 bytes
._tilescpc200

._tilescpc200_DATA
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
._tilescpc201

._tilescpc201_DATA
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
._tilescpc202

._tilescpc202_DATA
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
._tilescpc203

._tilescpc203_DATA
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0
defb $C0, $C0


;defs 16*4
defb 3,3
defb 3,3
defb 3,3
defb 3,3
defb 3,3
defb 3,3
defb 3,3
defb 3,3

defb 88,88
defb 88,88
defb 88,88
defb 88,88
defb 88,88
defb 88,88
defb 88,88
defb 88,88

defb $aa,$aa
defb $aa,$aa
defb $aa,$aa
defb $aa,$aa
defb $aa,$aa
defb $aa,$aa
defb $aa,$aa
defb $aa,$aa

defb 0,0
defb 0,0
defb 0,0
defb 0,0
defb 0,0
defb 0,0
defb 0,0
defb 0,0
