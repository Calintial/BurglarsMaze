extern unsigned char rojo[];
extern unsigned char muro[];
extern unsigned char punto[];
extern unsigned char borrar[];
#asm
._borrar
defb 2,8
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
defb $00,$00
._rojo
defb 2,8
defb $44,$88
defb $10,$20
defb $45,$8A
defb $CC,$CD
defb $CE,$88
defb $44,$88
defb $50,$88
defb $00,$A0
._muro
defb 2,8
defb $03,$03
defb $53,$A3
defb $53,$A3
defb $53,$A3
defb $53,$A3
defb $53,$A3
defb $03,$03
defb $03,$03
._punto
defb 2,8
defb $00,$00
defb $00,$00
defb $45,$8A
defb $45,$8A
defb $45,$8A
defb $00,$00
defb $00,$00
defb $00,$00
#endasm

typedef struct
{
	int sp; //Sprite a dibujar
	int pX,pY; //coordenadas X,Y actuales
	int pXold,pYold; //coordenadas
}mysprite;

void putSprite(mysprite* sprite, int x, int y)
{
	int coord = cpc_GetScrAddress(x,y);
	cpc_PutSprite(sprite->sp, coord);
}

void putTile(int numSprite, int x, int y)
{
	int coord = cpc_GetScrAddress(x,y);
	if(numSprite == 0) cpc_PutSprite(borrar, coord);
	else if(numSprite == 1) cpc_PutSprite(muro, coord);
}

void updateSprite(mysprite* sprite)
{
	if(sprite->pXold!=sprite->pX || sprite->pYold!=sprite->pY) putTile(0,sprite->pXold*2,sprite->pYold*8); //Si cambia la posición del sprite, se restaura la posición
	putSprite(sprite,sprite->pX*2,sprite->pY*8); //Pone el sprite en la nueva posicion
	sprite->pXold = sprite->pX;
	sprite->pYold = sprite->pY;
}