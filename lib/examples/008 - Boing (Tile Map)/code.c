#include "cpcrslib.h"
//#include <stdio.h>

// Ejemplo de pelota que rebota hasta pararse. Sólo movimiento vertical.
extern unsigned char sp_16x16[];
extern unsigned char sp_1x1[];
extern unsigned char sp_1x1_2[];
// Para compilar:
// zcc +cpc  TileMapConf.asm rutinas_comunes.asm -create-app -make-app -O3 -unsigned -o uno.bin ejemplo_mapeador.c -lcpcrslib -lndos -zorg=16384

#asm
._sp_16x16
defb 4,16
._sp_16x16_sin_dimensiones
defb $FF,$00,$FF,$00,$FF,$00,$FF,$00
defb $FF,$00,$FF,$00,$FF,$00,$FF,$00
defb $FF,$00,$00,$0F,$55,$0A,$FF,$00
defb $AA,$05,$00,$0F,$00,$25,$FF,$00
defb $AA,$05,$00,$0F,$00,$1A,$FF,$00
defb $00,$0F,$00,$0F,$00,$1A,$55,$0A
defb $00,$0F,$00,$0F,$00,$0F,$55,$0A
defb $00,$0F,$00,$0F,$00,$0F,$55,$0A
defb $00,$0F,$00,$0F,$00,$0F,$55,$0A
defb $00,$0F,$00,$0F,$00,$0F,$55,$0A
defb $00,$0F,$00,$0F,$00,$0F,$55,$0A
defb $00,$0F,$00,$0F,$00,$0F,$55,$0A
defb $AA,$05,$00,$0F,$00,$0F,$FF,$00
defb $AA,$05,$00,$0F,$00,$0F,$FF,$00
defb $FF,$00,$00,$0F,$55,$0A,$FF,$00
defb $FF,$00,$FF,$00,$FF,$00,$FF,$00
._sp_1x1
defb $ff,$ff,$ff,$ff
._sp_1x1_2
defb $00,0,0,0
#endasm



void establecer_colores(void) {
#asm
	//GATE_ARRAY	equ	&7F
	//TINTA		equ %01000000

ld hl,paleta1
xor a
.establecer_colores1
	ld b,(hl)
	ld c,b
	push af
	push hl
	call $bc32	
	pop hl
	pop af
	inc hl
	inc a
	cp 17	
	jp z, salto
	jp establecer_colores1
.paleta1
defb 11,17,25,25,25,25,25,25,25,25,24,19,15,6,26,0,0
.salto
    
#endasm
}


        
	void pause(void){
		#asm
		
		ld b,8
		.kolo
			halt
		djnz kolo
		
		#endasm
	}


main() {
	struct sprite {				// estructura mínima para usar la librería de dibujar sprites capturando el fondo.
	   	int sp0;		//2 bytes 	01
	   	int sp1;		//2 bytes	23
	   	int coord0;		//2 bytes	45	posición en superbuffer
	   	int coord1;	//2 bytes	67  posición anterior en superbuffer
	   	unsigned char cx, cy;	//2 bytes 	coordenadas nuevas	89
	   	unsigned char ox, oy;	//2 bytes   coordenadas actuales	1011
	   	unsigned char move;	// si NO es 0, el sprite se mueve.	
	   							// Si es 8 en cuanto se mueva se pone a 0 y ya no se mueve más hasta nueva orden.
	   	
   	};
   	struct sprite pelota00, disparo;
   	unsigned char t,t0;
   	unsigned char h,x,direccion,tm;
   		int spriteList[10];
   	unsigned char MinX,MinY,MaxX, MaxY,HorzSpd,VertSpd,gravityAccel;
   	
   	MaxX=60;
   	MaxY=110;
   	MinX=0;
   	MinY=0;
	VertSpd=1;
	HorzSpd=1;
	gravityAccel=2;
	
	spriteList[0]=pelota00;
	spriteList[1]=0xffff;
	establecer_colores();
   	cpc_SetModo(0);
   	x=8;
   	direccion=0;
   	pelota00.cy=20;
   	pelota00.cx=x;
   	pelota00.sp1=sp_16x16;
	pelota00.sp0=sp_16x16;
	pelota00.move=5;


	
	cpc_ShowTileMap(0);		//rellena el buffer con el mapa y lo envía a pantalla. Es el método para mostrar toda la pantalla


	
while(1){	
   	
	cpc_ResetTouchedTiles();		//borra la lista de tiles tocados
	
		pause();
			
            //check for bounce
            if (pelota00.cx >= MaxX)
            {
                HorzSpd = -HorzSpd;
                pelota00.cx = MaxX;
            }
            else if (pelota00.cx <= MinX)
            {
                HorzSpd = -HorzSpd;
                pelota00.cx = MinX;
            }

            if (pelota00.cy >= MaxY)
            {
                VertSpd = -VertSpd;
                pelota00.cy = MaxY;
            }
            else if (pelota00.cy <= MinY)
            {
                VertSpd = -VertSpd;
                pelota00.cy = MinY;
            }

            VertSpd += gravityAccel - 1;

            
            pelota00.cx += HorzSpd;
            pelota00.cy += VertSpd;
	
	cpc_UpdateTileMap(spriteList);
	


}
   		

	
}

