#include "lib/cpcrslib.h"
#include <stdio.h>


extern unsigned char moneda[];
extern unsigned char bomba[];
extern unsigned char explosion[];
#define WIDTH 40
#define HEIGHT 20

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


	// Borde superior
	y=0;
	for(x=0; x<WIDTH;x++) {
	    cpc_SetTile(x,y,5);
										    if (matrix[x][y] == 99)
										    {
										    	cpc_SetTile(x,y,4);
										    }
	}
	// Filas de en medio
	for(y=1;y<HEIGHT-1;y++) {
		x=0;
		cpc_SetTile(x,y,5);
											if (matrix[x][y] == 99)
										    {
										    	cpc_SetTile(x,y,4);
										    }
		for (x=1; x<WIDTH-1;x++) {
	      	cpc_SetTile(x,y,3);
									      	if (matrix[x][y] == 99)
										    {
										    	cpc_SetTile(x,y,4);
										    }
		}
		cpc_SetTile(x,y,5);
											if (matrix[x][y] == 99)
										    {
										    	cpc_SetTile(x,y,4);
										    }
	}
	// Borde inferior
	//y=19;
	for (x=0; x<40;x++) {
	    cpc_SetTile(x,y,5);
	    									if (matrix[x][y] == 99)
										    {
										    	cpc_SetTile(x,y,4);
										    }
	}

}

main(){
	//char cadena_puntos[11];
	int i,j;
	int *matrix[HEIGHT];
	int linea0[WIDTH];
	int linea1[WIDTH];
	int linea2[WIDTH];
	int linea3[WIDTH];
	int linea4[WIDTH];
	int linea5[WIDTH];
	int linea6[WIDTH];
	int linea7[WIDTH];
	int linea8[WIDTH];
	int linea9[WIDTH];
	int linea10[WIDTH];
	int linea11[WIDTH];
	int linea12[WIDTH];
	int linea13[WIDTH];
	int linea14[WIDTH];
	int linea15[WIDTH];
	int linea16[WIDTH];
	int linea17[WIDTH];
	int linea18[WIDTH];
	int linea19[WIDTH];

	matrix[0] = linea0;
	matrix[1] = linea1;
	matrix[2] = linea2;
	matrix[3] = linea3;
	matrix[4] = linea4;
	matrix[5] = linea5;
	matrix[6] = linea6;
	matrix[7] = linea7;
	matrix[8] = linea8;
	matrix[9] = linea9;
	matrix[10] = linea10;
	matrix[11] = linea11;
	matrix[12] = linea12;
	matrix[13] = linea13;
	matrix[14] = linea14;
	matrix[15] = linea15;
	matrix[16] = linea16;
	matrix[17] = linea17;
	matrix[18] = linea18;
	matrix[19] = linea19;

	matrix[0][0] = 99;
	matrix[0][2] = 99;
	matrix[2][0] = 99;
	matrix[2][2] = 99;

	
	for (i = 0; i < WIDTH; i++)
	{
		// for (j = 0; j < WIDTH; j++)
		// {
			matrix[i][10]=99;
		//}
	}
	//sprintf(cadena_puntos,"BIEN\0");
	//matrix[21][10]=99;
	//printPuntos(matrix[21][10]);

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
