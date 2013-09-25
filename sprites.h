extern unsigned char muro[];
extern unsigned char punto[];
extern unsigned char borrar[];
extern unsigned char ladron[];
extern unsigned char ladronarriba[];
extern unsigned char ladronder[];
extern unsigned char ladronizq[];
extern unsigned char cristal[];
extern unsigned char pared[];

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
defb $40,$80
defb $40,$80
defb $40,$80
defb $00,$00
defb $00,$00
defb $00,$00
._ladron
defb 2,8
defb $04,$08
defb $0C,$0C
defb $90,$60
defb $C0,$C0
defb $CC,$CC
defb $C4,$C8
defb $CC,$CC
defb $82,$41
._ladronder
defb 2,8
defb $04,$08
defb $0C,$0C
defb $C0,$30
defb $C0,$C0
defb $CC,$CC
defb $CC,$C0
defb $CC,$CC
defb $C3,$C3
._ladronizq
defb 2,8
defb $04,$08
defb $0C,$0C
defb $60,$C0
defb $C0,$C0
defb $CC,$CC
defb $C0,$CC
defb $CC,$CC
defb $C3,$C3
._ladronarriba
defb 2,8
defb $04,$08
defb $0C,$0C
defb $C0,$C0
defb $C0,$C0
defb $CC,$CC
defb $CC,$CC
defb $CC,$CC
defb $C3,$C3
._cristal
defb 2,8
defb $0C,$0C
defb $00,$04
defb $08,$00
defb $00,$08
defb $04,$00
defb $00,$04
defb $08,$08
defb $00,$00
._pared
defb 2,8
defb $30,$92
defb $30,$92
defb $30,$92
defb $C3,$C3
defb $30,$61
defb $30,$61
defb $30,$61
defb $C3,$C3

#endasm

typedef struct
{
	int sp; //Sprite a dibujar
	int pX,pY; //coordenadas X,Y actuales
	int pXold,pYold; //coordenadas
	int Width;
	int Height;
}mysprite;

//Inserta un Sprite sin Struct
void putElement(int sprite, int x, int y)
{
	int coord = cpc_GetScrAddress(x,y);
	cpc_PutSprite(sprite, coord);
}

//Inserta un Sprite con Struct
void putSprite(mysprite* sprite, int x, int y)
{
	int coord = cpc_GetScrAddress(x,y);
	cpc_PutSprite(sprite->sp, coord);
}

void putTile(int numSprite, int x, int y)
{
	int coord = cpc_GetScrAddress(x,y);
	if(numSprite == 0) cpc_PutSprite(borrar, coord);
	else if(numSprite == 1) cpc_PutSprite(pared, coord);
	else if(numSprite == 2) cpc_PutSprite(cristal, coord);
	else if(numSprite == 3) cpc_PutSprite(punto, coord);
}

void updateSprite(mysprite* sprite, int* matriz[])
{
	if(sprite->pXold!=sprite->pX || sprite->pYold!=sprite->pY) 
		putTile(matriz[sprite->pYold][sprite->pXold],sprite->pXold*2,sprite->pYold*8); //Si cambia la posición del sprite, se restaura la posición
	putSprite(sprite,sprite->pX*2,sprite->pY*8); //Pone el sprite en la nueva posicion
	sprite->pXold = sprite->pX;
	sprite->pYold = sprite->pY;
}

int RectangleColission(mysprite* sp1, mysprite* sp2)
{
    if ( (sp1->pX*2 < sp2->pX*2 + sp2->Width) && (sp2->pX*2 < sp1->pX*2 + sp1->Width) && (sp1->pY*8 < sp2->pY*8 + sp2->Height) && (sp2->pY*2 < sp1->pY*2 + sp1->Height))
    {
      	return 1;
    }
    else
    {
    	return 0;
    }
}

void deleteSprite(mysprite* sprite)
{
	putTile(0,sprite->pX*2,sprite->pY*8);
}