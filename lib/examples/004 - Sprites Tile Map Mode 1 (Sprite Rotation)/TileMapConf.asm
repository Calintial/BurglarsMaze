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



; VALORES QUE DEFINEN EL BUFFER Y LA PANTALLA
defc posicion_inicial_area_visible = $c050
defc posicion_inicial_superbuffer = $100

defc T_WIDTH = 32 ;32 ;28 ;32 ;28 ;16			;max=40		;dimensiones de la pantalla en tiles
defc T_HEIGHT = 16 ;16			;max=20


defc ancho_pantalla_bytes = 2*T_WIDTH ; 2*T_WIDTH;		; El ancho de pantalla influye determinantemente en numerosas rutinas que hay que actualizar si se cambia
											; OJO con el modo
defc alto_pantalla_bytes = 8*T_HEIGHT;

defc ancho_pantalla_bytes_visible = 2*T_WIDTH ;32  ; 64;		;dentro del area definida, cuanto se debe mostrar. 2*T_WIDTH

;El tamaño del buffer es ancho_pantalla_bytes*alto_pantalla_bytes


.TileMapConf
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
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*16
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*17
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*18
defw posicion_inicial_superbuffer+8*ancho_pantalla_bytes*19




;defw $1000, $1480, $1900, $1d80, $2200, $2680, $2b00, $2f80, $3400, $3880

;Rutinas para transferir bloques independientes a la pantalla

;Se busca el subbloque de 8x8 correspondiente a las coordenadas x,y
;el bloque se calcula dividiendo la coordenada x /8

.pantalla_actual defw 0
.pantalla_juego  ;en tiles
defs T_WIDTH*T_HEIGHT


;defs T_WIDTH*T_HEIGHT
;.pantalla_juego defs 180
defb $FF	;Este byte es importante, marca el fin de la pantalla.

.tiles_tocados defs 150 ;150	;cuando un tile es tocado, se marca en esta tabla para luego restaurarlo. Es una tabla sin duplicados.
	

.tiles ;Son de 2x8 bytes

;defb 2,8
;defb $70,$c0
;defb $f0,$68
;defb $f0,$84
;defb $f0,$e0
;defb $f0,$a4
;defb $e0,$c0
;defb $50,$60
;defb $00,$00

;defs 16

;hueco
defb $00,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$00
defb $40,$C0
defb $00,$00

