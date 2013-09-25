
extern unsigned char bomba[];
extern unsigned char bomba_roja[];
extern unsigned char explosion[];

#asm

._bomba
defb 2,8
defb $00,$30
defb $10,$20
defb $50,$A0
defb $B0,$F0
defb $F0,$F0
defb $F0,$F0
defb $F0,$F0
defb $50,$A0

._bomba_roja
defb 2,8
defb $00,$30
defb $10,$20
defb $44,$88
defb $98,$CC
defb $CC,$CC
defb $CC,$CC
defb $CC,$CC
defb $44,$88

._explosion
defb 2,8
defb $00,$00
defb $44,$88
defb $C8,$C4
defb $98,$64
defb $98,$64
defb $C8,$C4
defb $44,$88
defb $00,$00

#endasm

int bomb_exist = 0;
int explosion_exist = 0;
unsigned int bomb_time = 0;

mysprite sprite_bomba;

void initBomb(void)
{
	//Init bomba
	sprite_bomba.pX = 0;
	sprite_bomba.pY = 0;
	sprite_bomba.pXold = 0;
	sprite_bomba.pYold = 0;
	sprite_bomba.Width = 1;
	sprite_bomba.Height = 1;
	sprite_bomba.sp = bomba;
}

void putBomb(char x, char y,int* matriz[])
{	
	if(bomb_exist)
	{
		if(!explosion_exist)
			deleteSprite(sprite_bomba);
		else
			borrarExplosion(matriz);
	}

	sprite_bomba.sp = bomba;
	sprite_bomba.pX=x;
	sprite_bomba.pY=y;
	sprite_bomba.pXold=x;
	sprite_bomba.pYold=y;  
	bomb_exist = 1;
	bomb_time = 0;
	explosion_exist = 0;
}

void updateSpriteBomb(int* matriz[])
{
	if(!explosion_exist)
	{
		if(bomb_time == 30)
		{
			explotar(matriz);
			bomb_time = 0;
			explosion_exist = 1;
		}
		else if(bomb_time >= 15 && bomb_time%5==0)
		{
			if(sprite_bomba.sp == bomba)
			{
				sprite_bomba.sp = bomba_roja;
			}
			else
			{
				sprite_bomba.sp = bomba;
			}
			bomb_time++;
		}
		else
		{
			bomb_time++;
		}
		updateBomb(matriz);
	}
	else
	{
		if(bomb_time == 30)
		{
			bomb_time = 0;
			bomb_exist = 0;
			explosion_exist = 0;
			borrarExplosion(matriz);
		}
		else
		{
			bomb_time++;
			updateBomb(matriz);
		}
	}
	

}

void updateBomb(int* matriz[])
{

	if(!explosion_exist)
	{
		updateSprite(sprite_bomba,matriz);
	}
	else
	{
		explotar(matriz);
	}

}

void explotar(int* matriz[])
{
	int x = sprite_bomba.pX;
	int y = sprite_bomba.pY;

	//Dibujar las explosiones
	if(matriz[y][x+1] != 1 && matriz[y][x+1] != 3 && matriz[y][x+1] != 2)
	{
		putElement(explosion,(x+1)*2,y*8);
	}
	else if(matriz[y][x+1] == 3)
	{

	}
	else if(matriz[y][x+1] == 2)
	{
		putElement(explosion,(x+1)*2,y*8);
		matriz[y][x+1] = 0;
	}

	if(matriz[y][x-1] != 1 && matriz[y][x-1] != 3 && matriz[y][x-1] != 2)
	{
		putElement(explosion,(x-1)*2,y*8);
	}
	else if(matriz[y][x-1] == 3)
	{

	}
	else if(matriz[y][x-1] == 2)
	{
		putElement(explosion,(x-1)*2,y*8);
		matriz[y][x-1] = 0;
	}

	if(matriz[y+1][x] != 1 && matriz[y+1][x] != 3 && matriz[y+1][x] != 2)
	{
		putElement(explosion,x*2,(y+1)*8);
	}
	else if(matriz[y+1][x] == 3)
	{

	}
	else if(matriz[y+1][x] == 2)
	{
		putElement(explosion,x*2,(y+1)*8);
		matriz[y+1][x] = 0;
	}
	
	if(matriz[y-1][x] != 1 && matriz[y-1][x] != 3 && matriz[y-1][x] != 2)
	{
		putElement(explosion,x*2,(y-1)*8);
	}
	else if(matriz[y-1][x] == 3)
	{

	}
	else if(matriz[y-1][x] == 2)
	{
		putElement(explosion,x*2,(y-1)*8);
		matriz[y-1][x] = 0;
	}
	
	putElement(explosion,x*2,y*8);
}

void borrarExplosion(int* matriz[])
{
	int x = sprite_bomba.pX;
	int y = sprite_bomba.pY;

	putTile(matriz[y][x+1],(x+1)*2,y*8);
	putTile(matriz[y][x-1],(x-1)*2,y*8);
	putTile(matriz[y+1][x],x*2,(y+1)*8);
	putTile(matriz[y-1][x],x*2,(y-1)*8);
	putTile(matriz[y][x],x*2,y*8);
}

void bombCollide(mysprite* sprite)
{
	if(	(sprite->pX == sprite_bomba.pX && sprite->pY == sprite_bomba.pY) ||
		(sprite->pX == sprite_bomba.pX+1 && sprite->pY == sprite_bomba.pY) ||
		(sprite->pX == sprite_bomba.pX-1 && sprite->pY == sprite_bomba.pY) ||
		(sprite->pX == sprite_bomba.pX && sprite->pY == sprite_bomba.pY+1) ||
		(sprite->pX == sprite_bomba.pX && sprite->pY == sprite_bomba.pY-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}