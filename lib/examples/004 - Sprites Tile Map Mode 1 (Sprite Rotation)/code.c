#include "cpcrslib.h"
#include <stdio.h>


extern unsigned char sp_3x16[];

// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384

#asm
._sp_3x16
defb 3,16
._sp_3x16_sd
defb $ff,$10,$ff,$e0,$ff,$00
defb $ff,$10,$ff,$3c,$ff,$00
defb $ff,$10,$ff,$1e,$ff,$00
defb $ff,$10,$ff,$96,$ff,$00
defb $ff,$00,$ff,$f0,$ff,$00
defb $ff,$00,$ff,$40,$ff,$00
defb $ff,$10,$ff,$40,$ff,$c0
defb $ff,$00,$ff,$f0,$ff,$80
defb $ff,$00,$ff,$60,$ff,$00
defb $ff,$00,$ff,$60,$ff,$00
defb $ff,$00,$ff,$60,$ff,$00
defb $ff,$00,$ff,$60,$ff,$00
defb $ff,$10,$ff,$b0,$ff,$00
defb $ff,$10,$ff,$10,$ff,$80
defb $ff,$10,$ff,$00,$ff,$c0
defb $ff,$10,$ff,$88,$ff,$31
#endasm

void pausa(){ //pause
	#asm	
	ld b,2
	.pausamiento
	halt
	djnz pausamiento
	#endasm
}

main(){
	
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
   	struct sprite sprite00, sprite01;
   	unsigned char i,j,c1;
   	
   	cpc_SetModo(1);
   	
	sprite00.sp1=sp_3x16;
	sprite00.sp0=sp_3x16;

	sprite01.sp1=sp_3x16;
	sprite01.sp0=sp_3x16;
	
		
	sprite00.ox=10;
	sprite00.oy=100; 	
	sprite00.cx=10;
	sprite00.cy=100; 	//first time cx=ox and cy=oy

	sprite01.ox=10;
	sprite01.oy=100; 	
	sprite01.cx=10;
	sprite01.cy=100; 	

		
	cpc_ResetTouchedTiles();
	
	cpc_ShowTileMap(0);		//Shows map

	cpc_SpRLM1(sp_3x16);	//Masked Sprite Left Rotation
	cpc_SpRLM1(sp_3x16);
	cpc_SpRLM1(sp_3x16);	
	
	c1=0;
	for (i=10;i<200;i++) { 
		//pausa();
		sprite00.cy=30;
		sprite01.cy=10;
		c1++;
		if (c1==4) {	//each 3 steps, sprite return to left
			c1=0;
			cpc_SpRLM1(sp_3x16);	//Masked Sprite Left Rotation
			cpc_SpRLM1(sp_3x16);
			cpc_SpRLM1(sp_3x16);
			sprite00.cx++;
			sprite01.cx++;
		} else {
			cpc_SpRRM1(sp_3x16);	//Masked Sprite Right Rotation
		}
		
		
		cpc_PutSpTileMap(sprite00);
		cpc_PutSpTileMap(sprite01);
		
		cpc_UpdScr(); 				
		
		cpc_PutMaskSpTileMap2b(sprite00);
		cpc_PutMaskSpTileMap2b(sprite01);
		
		cpc_ShowTouchedTiles();			
		
		cpc_ResetTouchedTiles();
	}  

	while (1);	//ad infinitum
}
