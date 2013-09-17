#include "cpcrslib.h"

extern unsigned char sp_1[];	//masked sprite data
extern unsigned char sp_2[];	//masked sprite data
extern unsigned char tintas[];	//inks
extern unsigned char buffer[];	//inks
// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o out.bin code.c -lcpcrslib -lndos -zorg=16384
// Sample by Raúl Simarro 2008 (artaburu)



void set_colours(void) {
	unsigned char x;
	for (x=0;x<16;x++){ 
		cpc_SetInk(x,tintas[x]);
	}
	cpc_SetBorder(0);
}
void pause(void) {
	#asm
	ld b,80
	.pause_loop
	halt
	djnz pause_loop
	#endasm
}
void collide(void) {
	cpc_SetColour(16,1);
	pause();
	cpc_SetColour(16,9);
}
	
void draw_tilemap(void) {
	unsigned char x,y;
	//set the tiles of the map. In this example, the tile map is 32x16 tile
	//Tile Map configuration file: TileMapConf.asm
	
	y=0;
	for(x=0; x<32;x++) {
	      cpc_SetTile(x,y,1);
	}
	for(y=1;y<15;y++) {
		for (x=0; x<32;x++) {
	      cpc_SetTile(x,y,0);
		}
	}
	y=15;
	for (x=0; x<32;x++) {
	      cpc_SetTile(x,y,2);
	}
}

void print_credits(void) {
	cpc_PrintGphStrXY("SMALL;SPRITE;DEMO",9*2,20*8);
	cpc_PrintGphStrXY("Z88DK;;CPCRSLIB",10*2,21*8);
	cpc_PrintGphStrXY("BY;ARTABURU;2008",10*2-1,22*8);
	cpc_PrintGphStrXY("WWW<AMSTRAD<ES",10*2+1,24*8);
}

main(){
	unsigned char a;
	struct sprite {		// minimun sprite structure
	   	int sp0;		//2 bytes 	01
	   	int sp1;		//2 bytes	23
	   	int coord0;		//2 bytes	45	current superbuffer address
	   	int coord1;		//2 bytes	67  old superbuffer address		
	   	unsigned char cx, cy;	//2 bytes 89 	current coordinates 
	   	unsigned char ox, oy;	//2 bytes 1011  old coordinates 
	   	unsigned char move1;	// los bits 4,3,2 definen el tipo de dibujo!!
	   	unsigned char move;		// 	in this example, to know the movement direction of the sprite
	   							
	   	
   	};
   	struct sprite sprite00,sprite01,sprite02;
	int spriteList[10];
	
	spriteList[0]=sprite00;
	spriteList[1]=sprite01;
	spriteList[2]=sprite02;
	spriteList[3]=0xffff;
   	
   	set_colours();
   	
   	cpc_SetModo(0);
   	
   	cpc_DisableFirmware();
   	// All the sprite values are initilized
	sprite00.sp1=sp_1;
	sprite00.sp0=sp_1;
	sprite00.ox=50;
	sprite00.oy=70; 	
	sprite00.cx=50;
	sprite00.cy=70; 	
	sprite00.move1=3;
	cpc_SuperbufferAddress(sprite00); //first time it's important to do this
	
	sprite01.sp1=sp_2;
	sprite01.sp0=sp_2;
	sprite01.ox=50;
	sprite01.oy=106; 	
	sprite01.cx=50;
	sprite01.cy=106;
	sprite01.move=1; 	
	sprite01.move1=3;
	cpc_SuperbufferAddress(sprite01); 
		
	sprite02.sp1=sp_2;
	sprite02.sp0=sp_2;
	sprite02.ox=20;
	sprite02.oy=100; 	
	sprite02.cx=20;
	sprite02.cy=100; 	
	sprite02.move=2; 
	sprite02.move1=3;
	cpc_SuperbufferAddress(sprite02); 
	
	
		
	//Drawing the tile map
	draw_tilemap();
	cpc_ShowTileMap(0);		//Show entire tile map in the screen
	print_credits();
	cpc_SetTile(0,1,2);
	cpc_GetTiles(0,0,2,3, buffer);
	
	cpc_PutTiles(0,13,2,3, buffer);
	cpc_GetTiles(0,13,2,3, buffer);
	cpc_PutTiles(8,9,2,3, buffer);	
	
	cpc_ShowTileMap(0);		//Show entire tile map in the screen
	while(1){	
		
		//Default number keys for moving one of the sprites:
		// 0: cursor right
		// 1: cursor left
		// 2: cursor up
		// 3: cursor down
		
		//for example., if key 0 is pressed, and the sprite is inside tilemap, then
		//the sprite is moved one byte to the right:
		if (cpc_TestKey(0)==1 && sprite00.cx<60) cpc_SpUpdX(sprite00,1);	
		if (cpc_TestKey(1)==1 && sprite00.cx>0) cpc_SpUpdX(sprite00,-1);
		if (cpc_TestKey(2)==1 && sprite00.cy>0) cpc_SpUpdY(sprite00,-1);			
		if (cpc_TestKey(3)==1 && sprite00.cy<112) cpc_SpUpdY(sprite00,1);

				
		// The other sprites are automatically moved 
		if (sprite01.move==0) { //0 = left, 1 = right								
			if (sprite01.cx>0) cpc_SpUpdX(sprite01,-1);
				else sprite01.move=1;
		}
		if (sprite01.move==1) { //0 = left, 1 = right								
			if (sprite01.cx<60) cpc_SpUpdX(sprite01,1);
				else sprite01.move=0;
		}		

		if (sprite02.move==2) { //2 = up, 3 = down								
			if (sprite02.cy>0) cpc_SpUpdY(sprite02,-2);
				else sprite02.move=3;
		}
		if (sprite02.move==3) {  //2 = up, 3 = down								
			if (sprite02.cy<106) cpc_SpUpdY(sprite02,2);
				else sprite02.move=2;
		}	
		
						
		cpc_ResetTouchedTiles();		//clear touched tile table		
		
		
//		sprite tile map update, using a sprite list: 

//		Method 1

//		cpc_UpdateTileMap(spriteList);

// 	  	End of method 1


		
//    Alternative Method, without sprite list:  

//		Method 2
		//Sprite phase 1
		cpc_PutSpTileMap(sprite00);		//search the tiles where is and was the sprite
		cpc_PutSpTileMap(sprite01);		
		cpc_PutSpTileMap(sprite02);	
		
		
		cpc_UpdScr(); 					//Update the screen to new situatio (show the touched tiles)
		
		//Sprite phase 2
		cpc_PutMaskSpriteTileMap2b(sprite00);	//Requires to move sprite with cpc_SpUpdX or cpc_SpUpdY
		cpc_PutMaskSpriteTileMap2b(sprite01);	
		cpc_PutMaskSpriteTileMap2b(sprite02);
		
		cpc_ShowTouchedTiles();			//Show the touched tiles-> show the new sprite situatuion

// 	  	End of method 2

		
		if (cpc_CollSp(sprite00,sprite01)) collide();  //test if there is collision between sprite00 and sprite01
		if (cpc_CollSp(sprite00,sprite02)) collide();
		
	}
}




#asm
._buffer
defs 30
._sp_1
defb 4,16								//sprite dimensions in bytes withd, height 
defb $FF,$00,$00,$CF,$00,$CF,$FF,$00	//data: mask, sprite, mask, sprite...
defb $AA,$45,$00,$3C,$00,$3C,$55,$8A
defb $00,$8A,$00,$55,$00,$AA,$00,$45
defb $00,$8A,$00,$20,$00,$00,$00,$65
defb $00,$28,$00,$55,$00,$AA,$00,$14
defb $00,$7D,$00,$BE,$00,$FF,$00,$BE
defb $AA,$14,$00,$FF,$00,$BE,$55,$28
defb $AA,$00,$00,$3C,$00,$79,$55,$00
defb $00,$51,$00,$51,$00,$A2,$55,$A2
defb $00,$F3,$00,$10,$00,$20,$00,$F3
defb $00,$F3,$00,$51,$00,$A2,$00,$F3
defb $55,$28,$00,$0F,$00,$0F,$AA,$14
defb $FF,$00,$55,$0A,$AA,$05,$FF,$00
defb $55,$02,$55,$28,$AA,$14,$AA,$01
defb $00,$03,$55,$02,$AA,$01,$00,$03
defb $FF,$00,$FF,$00,$FF,$00,$FF,$00
._sp_2
defb 4,22
defb $FF,$00,$FF,$00,$FF,$00,$FF,$00
defb $FF,$00,$00,$CC,$00,$CC,$FF,$00
defb $FF,$00,$AA,$44,$55,$88,$FF,$00
defb $FF,$00,$AA,$44,$55,$88,$FF,$00
defb $FF,$00,$AA,$44,$55,$88,$FF,$00
defb $FF,$00,$00,$CF,$00,$CF,$FF,$00
defb $AA,$45,$00,$CF,$00,$CF,$55,$8A
defb $AA,$45,$00,$E5,$00,$DA,$55,$8A
defb $AA,$45,$00,$CF,$00,$CF,$55,$8A
defb $AA,$45,$00,$CF,$00,$CF,$55,$8A
defb $AA,$45,$00,$CF,$00,$CF,$55,$8A
defb $AA,$45,$00,$CF,$00,$CF,$55,$8A
defb $FF,$00,$00,$CF,$00,$CF,$FF,$00
defb $AA,$01,$00,$03,$00,$03,$55,$02
defb $00,$A9,$00,$03,$00,$03,$00,$56
defb $00,$A9,$00,$03,$00,$03,$00,$56
defb $AA,$01,$00,$03,$00,$03,$55,$02
defb $AA,$01,$00,$03,$00,$03,$55,$02
defb $AA,$01,$00,$06,$00,$09,$55,$02
defb $FF,$00,$00,$0C,$00,$0C,$FF,$00
defb $FF,$00,$00,$0C,$00,$0C,$FF,$00
defb $FF,$00,$00,$0C,$00,$0C,$FF,$00

// There is a tool called Sprot that allows to generate masked sprites for z88dk.
// ask for it: www.amstrad.es/forum/


._tintas  //firmware inks
defb 0,13,1,6,26,24,15,8,10,22,14,3,18,4,11,25
#endasm
