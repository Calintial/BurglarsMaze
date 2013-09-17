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

void draw_tilemap(void) {
	unsigned char x,y;
	//set the tiles of the map. In this example, the tile map is 32x16 tile
	//Tile Map configuration file: TileMapConf.asm
	
	y=0;
	for(x=0; x<40;x++) {
	      cpc_SetTile(x,y,3);
	}
	for(y=0;y<20;y++) {
		for (x=0; x<40;x++) {
	      cpc_SetTile(x,y,3);
		}
	}
	y=15;
	for (x=0; x<40;x++) {
	      cpc_SetTile(x,y,3);
	}
}

main(){

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

	draw_tilemap();
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
