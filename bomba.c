#include "lib/cpcrslib.h"
#include <stdio.h>

extern unsigned char bomba[];
extern unsigned char bomba2[];
extern unsigned char explosion[];

#asm

._bomba
defb 6,24
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$10,$00,$00
defb $00,$00,$10,$20,$00,$00
defb $00,$00,$50,$A0,$00,$00
defb $00,$00,$B0,$F0,$00,$00
defb $00,$00,$F0,$F0,$00,$00
defb $00,$00,$F0,$F0,$00,$00
defb $00,$00,$F0,$F0,$00,$00
defb $00,$00,$50,$A0,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00



._bomba2
defb 6,24
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$10,$00,$00
defb $00,$00,$10,$20,$00,$00
defb $00,$00,$44,$88,$00,$00
defb $00,$00,$98,$CC,$00,$00
defb $00,$00,$CC,$CC,$00,$00
defb $00,$00,$CC,$CC,$00,$00
defb $00,$00,$CC,$CC,$00,$00
defb $00,$00,$44,$88,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00
defb $00,$00,$00,$00,$00,$00


._explosion
defb 6,24
defb $00,$00,$44,$88,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$98,$64,$00,$00
defb $00,$00,$98,$64,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$44,$88,$00,$00
defb $44,$88,$44,$88,$44,$88
defb $C8,$C4,$C8,$C4,$C8,$C4
defb $C8,$C4,$C8,$C4,$C8,$C4
defb $98,$64,$98,$64,$98,$64
defb $98,$64,$98,$64,$98,$64
defb $C8,$C4,$C8,$C4,$C8,$C4
defb $C8,$C4,$C8,$C4,$C8,$C4
defb $44,$88,$44,$88,$44,$88
defb $00,$00,$44,$88,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$98,$64,$00,$00
defb $00,$00,$98,$64,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$C8,$C4,$00,$00
defb $00,$00,$44,$88,$00,$00



#endasm

int bomb_exist = 0;
int explosion_exist = 0;
unsigned int bomb_time = 0;

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
struct sprite sprite_bomba;

void initBomb(void)
{
	sprite_bomba.sp1 = bomba;
	sprite_bomba.sp0 = bomba;

	sprite_bomba.ox=0;
	sprite_bomba.oy=0; 	
	sprite_bomba.cx=0;
	sprite_bomba.cy=0; 
	sprite_bomba.move=0;
	cpc_SuperbufferAddress(sprite_bomba);
}

void putBomb(char x, char y)
{
	sprite_bomba.sp0 = bomba;
	sprite_bomba.cx=x;
	sprite_bomba.cy=y; 
	cpc_ResetTouchedTiles();

	cpc_PutSpTileMap(sprite_bomba);
	cpc_UpdScr(); 
	//cpc_PutMaskSpriteTileMap2b(figura); //con mascara
	cpc_PutORSpTileMap2b(sprite_bomba); //Sin mascara
	cpc_ShowTouchedTiles();
	bomb_exist = 1;
	bomb_time = 0;
}

void updateSpriteBomb()
{
	if(sprite_bomba.sp0 != explosion)
	{
		if(bomb_time == 500)
		{
			sprite_bomba.sp0 = explosion;
			bomb_time = 0;
		}
		else if(bomb_time >= 300 && bomb_time%5==0)
		{
			if(sprite_bomba.sp0 == bomba)
			{
				sprite_bomba.sp0 = bomba2;
			}
			else
			{
				sprite_bomba.sp0 = bomba;
			}
			bomb_time++;
		}
		else
		{
			bomb_time++;
		}

	}
	else if(sprite_bomba.sp0 == explosion)
	{
		if(bomb_time == 150)
		{
			bomb_time = 0;
			bomb_exist = 0;
		}
		else
		{
			bomb_time++;
			
		}
	}
	updateBomb();

}

void updateBomb(void)
{
	cpc_ResetTouchedTiles();

	cpc_PutSpTileMap(sprite_bomba);
	cpc_UpdScr(); 
	if(bomb_exist)
	{
		//cpc_PutMaskSpriteTileMap2b(figura); //con mascara
		cpc_PutORSpTileMap2b(sprite_bomba); //Sin mascara	
	}
	cpc_ShowTouchedTiles();	

	if(!bomb_exist)
	{
		sprite_bomba.cx = 0;
		sprite_bomba.cy = 0;
		sprite_bomba.ox = 0;
		sprite_bomba.oy = 0;
	}
}


int collisionBomb(struct sprite* sprite1, struct sprite* sprite2)
{
	if(sprite_bomba.sp0 == explosion)
	{
		return cpc_CollSp(sprite1,sprite2);
	}
	else
	{
		return 0;
	}
}

void collisionWall(int *matrix[],int x,int y)
{
	int tileX = x/2;
	int tileY = x/8;

	if(matrix[tileY + 1][tileX] == 5)
	{
		
	}
	if(matrix[tileY - 1][tileX] == 5)
	{

	}
	if(matrix[tileY][tileX + 1] == 5)
	{

	}
	if(matrix[tileY][tileX - 1] == 5)
	{

	}
}