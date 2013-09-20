#include "lib/cpcrslib.h"
#include <stdio.h>


extern unsigned char moneda[];
extern unsigned char bomba[];
extern unsigned char explosion[];


// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384

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
struct sprite sprite_moneda,sprite_bomba;

void draw_tilemap(int *matrix[]) {
	unsigned char x,y;
	//set the tiles of the map. In this example, the tile map is 32x16 tile
	//Tile Map configuration file: TileMapConf.asm
	
	y=0;
	for(x=0; x<40;x++) {
		if (matrix[x][y] == 0)
		{
			cpc_SetTile(x,y,5);
		}else{
			cpc_SetTile(x,y,4);
		}
	    
	}
	for(y=1;y<19;y++) {
		if (matrix[x][y] == 0)
		{
			cpc_SetTile(x,y,5);
		}else{
			cpc_SetTile(x,y,4);
		}
		for (x = 1; x < 39; x++)
		{
			if (matrix[x][y] == 0)
			{
				cpc_SetTile(x,y,3);
			}else{
				cpc_SetTile(x,y,2);
			}
		}
		if (matrix[x][y] == 0)
		{
			cpc_SetTile(x,y,5);
		}else{
			cpc_SetTile(x,y,4);
		}
	}
	
	for (x=0; x<40;x++) {
	    if (matrix[x][y] == 0)
		{
			cpc_SetTile(x,y,5);
		}else{
			cpc_SetTile(x,y,4);
		}
	}

}

main(){
	int *matrix[20];
	int linea0[40];
	int linea1[40];
	int linea2[40];
	int linea3[40];
	int linea4[40];
	int linea5[40];
	int linea6[40];
	int linea7[40];
	int linea8[40];
	int linea9[40];
	int linea10[40];
	int linea11[40];
	int linea12[40];
	int linea13[40];
	int linea14[40];
	int linea15[40];
	int linea16[40];
	int linea17[40];
	int linea18[40];
	int linea19[40];

	matrix[0] = linea0;
	matrix[0] = linea1;
	matrix[0] = linea2;
	matrix[0] = linea3;
	matrix[0] = linea4;
	matrix[0] = linea5;
	matrix[0] = linea6;
	matrix[0] = linea7;
	matrix[0] = linea8;
	matrix[0] = linea9;
	matrix[0] = linea10;
	matrix[0] = linea11;
	matrix[0] = linea12;
	matrix[0] = linea13;
	matrix[0] = linea14;
	matrix[0] = linea15;
	matrix[0] = linea16;
	matrix[0] = linea17;
	matrix[0] = linea18;
	matrix[0] = linea19;

	cpc_SetModo(0);


	cpc_DisableFirmware();

	/*Init Sprites*/
	sprite_moneda.sp1 = moneda;
	sprite_moneda.sp0 = moneda;

	sprite_moneda.ox=50;
	sprite_moneda.oy=70; 	
	sprite_moneda.cx=50;
	sprite_moneda.cy=70; 
	sprite_moneda.move=0;

	cpc_SuperbufferAddress(sprite_moneda);

	sprite_bomba.sp1 = bomba;
	sprite_bomba.sp0 = bomba;

	sprite_bomba.ox=60;
	sprite_bomba.oy=50; 	
	sprite_bomba.cx=60;
	sprite_bomba.cy=50; 
	sprite_bomba.move=0;

	cpc_SuperbufferAddress(sprite_bomba);

	draw_tilemap(matrix);
	cpc_ShowTileMap(0);		//Show entire tile map in the screen

	while(1)
	{
		
		if (cpc_TestKey(0)==1 && sprite_moneda.cx<60) cpc_SpUpdX(sprite_moneda,1);	
		if (cpc_TestKey(1)==1 && sprite_moneda.cx>0) cpc_SpUpdX(sprite_moneda,-1);
		if (cpc_TestKey(2)==1 && sprite_moneda.cy>0) cpc_SpUpdY(sprite_moneda,-1);			
		if (cpc_TestKey(3)==1 && sprite_moneda.cy<112) cpc_SpUpdY(sprite_moneda,1);


		updateSprites();
		if (cpc_CollSp(sprite_moneda,sprite_bomba))
		{
			sprite_bomba.sp0 = explosion;
		}
		else
		{
			sprite_bomba.sp0 = bomba;
		}
	}

}

void updateSprites(void)
{
	cpc_ResetTouchedTiles();

	cpc_PutSpTileMap(sprite_moneda);
	cpc_PutSpTileMap(sprite_bomba);
	cpc_UpdScr(); 
	//cpc_PutMaskSpriteTileMap2b(figura); //con mascara
	cpc_PutORSpTileMap2b(sprite_moneda); //Sin mascara
	cpc_PutORSpTileMap2b(sprite_bomba);
	cpc_ShowTouchedTiles();	
}
