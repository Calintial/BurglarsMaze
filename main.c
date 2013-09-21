#include "bomba.c"
#include <stdio.h>


extern unsigned char moneda[];
#define WIDTH 40
#define HEIGHT 20

// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384

#asm
._moneda
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

#endasm

struct sprite sprite_moneda;

void draw_tilemap(int *matrix[]) {
	unsigned char x,y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			cpc_SetTile(x,y,matrix[y][x]);
		}
	}
}


main(){


	int y,x;
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


	
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if(x == 0)
			{
				matrix[y][x] = 5;
			}
			else if(x == WIDTH-1)
			{
				matrix[y][x] = 5;
			}
			else if(y == 0)
			{
				matrix[y][x] = 5;
			}
			else if(y == HEIGHT-1)
			{
				matrix[y][x] = 5;
			}
			else
			{
				matrix[y][x] = 3;
			}

		}
	}

	cpc_SetModo(0);

	cpc_DisableFirmware();

	/*Init Sprites*/
	InitMoneda();
	initBomb();

	/*Init map*/
	draw_tilemap(matrix);
	cpc_ShowTileMap(0);		//Show entire tile map in the screen

	/*Init keys*/
	cpc_AssignKey(4, 0x4580); 

	while(1)
	{

		if (cpc_TestKey(0)==1 && sprite_moneda.cx<76)
		{
			cpc_SpUpdX(sprite_moneda, 1);
		}
		if (cpc_TestKey(1)==1 && sprite_moneda.cx>2)
		{
			cpc_SpUpdX(sprite_moneda, -1);
		} 
		if(cpc_TestKey(2)==1 && sprite_moneda.cy>8)
		{
			cpc_SpUpdY(sprite_moneda, -1);
		} 	
		if (cpc_TestKey(3)==1 && sprite_moneda.cy<112)
		{
			cpc_SpUpdY(sprite_moneda, 1);
		}
		if(cpc_TestKey(4)==1)
		{
			putBomb(sprite_moneda.cx-2,sprite_moneda.cy-4);
		}
		updateSprites();

		if(collisionBomb(sprite_moneda,sprite_bomba))
		{
			cpc_PrintGphStr("DEAD!",0xc190);    
		}
	}

}

void updateSprites(void)
{
	cpc_ResetTouchedTiles();

	cpc_PutSpTileMap(sprite_moneda);
	cpc_UpdScr(); 
	//cpc_PutMaskSpriteTileMap2b(figura); //con mascara
	cpc_PutORSpTileMap2b(sprite_moneda); //Sin mascara
	cpc_ShowTouchedTiles();


	if(bomb_exist)
	{
		updateSpriteBomb();
	}


}

void InitMoneda(void)
{
	sprite_moneda.sp1 = moneda;
	sprite_moneda.sp0 = moneda;

	sprite_moneda.ox=50;
	sprite_moneda.oy=70; 	
	sprite_moneda.cx=50;
	sprite_moneda.cy=70; 
	sprite_moneda.move=0;

	cpc_SuperbufferAddress(sprite_moneda);

}
