#include "lib/cpcrslib.h"
#include <stdio.h>

extern unsigned char moneda[];
extern unsigned char bomba[];
extern unsigned char explosion[];
extern unsigned char malo14x8[];
extern unsigned char malo14x16[];
extern unsigned char malo14x16reves[];
extern unsigned char malo24x16[];
extern unsigned char malo24x16reves[];
// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384

#asm
._malo24x16reves
defb 2,16
defb $04,$0C
defb $04,$0C
defb $0C,$0C
defb $50,$CF
defb $45,$CF
defb $45,$CF
defb $01,$03
defb $01,$03
defb $01,$03
defb $F0,$F0
defb $01,$A1
defb $01,$03
defb $01,$03
defb $01,$03
defb $05,$0F
defb $50,$50

._malo24x16
defb 2,16
defb $51,$00
defb $F3,$A2
defb $F3,$A2
defb $CF,$A0
defb $CF,$8A
defb $CF,$8A
defb $CC,$88
defb $CC,$88
defb $CC,$88
defb $CC,$F0
defb $CC,$F0
defb $D8,$F0
defb $F0,$88
defb $E4,$88
defb $F3,$A2
defb $A0,$A0

._moneda
defb 4,8
defb $00,$15,$2A,$00
defb $00,$15,$3F,$00
defb $00,$45,$A0,$00
defb $00,$45,$8A,$00
defb $00,$01,$02,$00
defb $00,$01,$02,$00
defb $00,$04,$08,$00
defb $00,$50,$A0,$00
._malo14x8
defb 2,8
defb $3F,$00
defb $3F,$2A
defb $DA,$00
defb $CF,$00
defb $0F,$F0
defb $0F,$A0
defb $0C,$00
defb $F0,$00
._malo14x16
defb 2,16
defb $0C,$08
defb $0C,$08
defb $0C,$0C
defb $CF,$A0
defb $CF,$8A
defb $CF,$8A
defb $03,$02
defb $03,$02
defb $F0,$F0
defb $52,$02
defb $03,$02
defb $03,$02
defb $03,$02
defb $0F,$0A
defb $0F,$0A
defb $A0,$A0
._malo14x16reves
defb 2,16
defb $04,$0C
defb $04,$0C
defb $0C,$0C
defb $50,$CF
defb $45,$CF
defb $45,$CF
defb $01,$03
defb $01,$03
defb $01,$03
defb $F0,$F0
defb $01,$A1
defb $01,$03
defb $01,$03
defb $01,$03
defb $05,$0F
defb $50,$50
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
struct sprite sprite_enemigo,sprite_bomba,sprite_enemigo2;

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
	sprite_enemigo.sp1 = malo14x16;
	sprite_enemigo.sp0 = malo14x16;

	sprite_enemigo.ox=50;
	sprite_enemigo.oy=70; 	
	sprite_enemigo.cx=50;
	sprite_enemigo.cy=70; 
	sprite_enemigo.move=0;

	cpc_SuperbufferAddress(sprite_enemigo);

	sprite_bomba.sp1 = bomba;
	sprite_bomba.sp0 = bomba;

	sprite_bomba.ox=60;
	sprite_bomba.oy=50; 	
	sprite_bomba.cx=60;
	sprite_bomba.cy=50; 
	sprite_bomba.move=0;

	cpc_SuperbufferAddress(sprite_bomba);

	sprite_enemigo2.sp1 = malo24x16;
	sprite_enemigo2.sp0 = malo24x16;

	sprite_enemigo2.ox=40;
	sprite_enemigo2.oy=40; 	
	sprite_enemigo2.cx=40;
	sprite_enemigo2.cy=40; 
	sprite_enemigo2.move=0;
	cpc_SuperbufferAddress(sprite_enemigo2);

	draw_tilemap();
	cpc_ShowTileMap(0);		//Show entire tile map in the screen

	while(1)
	{

		if (cpc_TestKey(0)==1 && sprite_enemigo.cx<60){
		 cpc_SpUpdX(sprite_enemigo,1)
		 	sprite_enemigo.sp1 = malo14x16;
			sprite_enemigo.sp0 = malo14x16;
		};

		if (cpc_TestKey(1)==1 && sprite_enemigo.cx>0){ 
			cpc_SpUpdX(sprite_enemigo,-1)
			sprite_enemigo.sp1 = malo14x16reves;
			sprite_enemigo.sp0 = malo14x16reves;
		};
		if (cpc_TestKey(2)==1 && sprite_enemigo.cy>0){
		 cpc_SpUpdY(sprite_enemigo,-1)
		};			
		if (cpc_TestKey(3)==1 && sprite_enemigo.cy<112){
		 cpc_SpUpdY(sprite_enemigo,1)
		};


		updateSprites();
		if (cpc_CollSp(sprite_enemigo,sprite_bomba))
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

	cpc_PutSpTileMap(sprite_enemigo);
	cpc_PutSpTileMap(sprite_bomba);
	cpc_PutSpTileMap(sprite_enemigo2);
	cpc_UpdScr(); 
	//cpc_PutMaskSpriteTileMap2b(figura); //con mascara
	cpc_PutORSpTileMap2b(sprite_enemigo); //Sin mascara
	cpc_PutORSpTileMap2b(sprite_bomba);
	cpc_PutORSpTileMap2b(sprite_enemigo2);
	cpc_ShowTouchedTiles();	
}
