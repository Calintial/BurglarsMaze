#include "cpcrslib.h"
#include "datos.h"

int pointer=0;

void establecer_colores(void) {
	unsigned char i;
	for (i=0;i<16;i++)
		cpc_SetInk(i,paleta[i]);
}

void draw_bloque(unsigned char x, unsigned char y, unsigned char b){
	cpc_SetTile(2*x,2*y,bloques[b*4]);
	cpc_SetTile(2*x+1,2*y,bloques[b*4+1]);
	cpc_SetTile(2*x,2*y+1,bloques[b*4+2]);
	cpc_SetTile(2*x+1,2*y+1,bloques[b*4+3]);
}

void draw_bloqueL(unsigned int z, unsigned char v){
	unsigned char y,t;
    for(y=0;y<9;y++) {
		t=test_map0[100*y+z];	    
		cpc_SetTile(0,2*y,bloques[t*4+v]);
		cpc_SetTile(0,2*y+1,bloques[t*4+2+v]);
	}
}
void draw_bloqueR (unsigned int z, unsigned char v){
	unsigned char y,t;
    for(y=0;y<9;y++) {
		t=test_map0[100*y+z];
		cpc_SetTile(29,2*y,bloques[t*4+v]);
		cpc_SetTile(29,2*y+1,bloques[t*4+2+v]);
	}
}

void draw_tilemap(void) {
	unsigned char x,y;
	int t;
    for(y=0;y<9;y++) {
		for(x=0; x<15;x++) {
			t=test_map0[100*y+x];
	      	draw_bloque(x,y,t);	
		}	
	}
}


void drawColumn(void){
	unsigned char i;
	unsigned int z;
	z=(pointer+30)>>1;		//situa en columna a leer	    
    i=(char)pointer&1;	
	pointer++;
	draw_bloqueR(z,i);	
}

	

void drawColumnI(void){
	unsigned char i;
	unsigned int z;
	pointer--;
	z=pointer>>1;		//situa en columna a leer	
	i=(char)pointer&1;
	draw_bloqueL(z,i);	
}



main(){
	struct sprite {		// minimun sprite structure
	   	int sp0;		//2 bytes 	01
	   	int sp1;		//2 bytes	23
	   	int coord0;		//2 bytes	45	current superbuffer address
	   	int coord1;		//2 bytes	67  old superbuffer address		
	   	unsigned char cx, cy;	//2 bytes 89 	current coordinates 
	   	unsigned char ox, oy;	//2 bytes 1011  old coordinates 
	   	unsigned char move1;	
	   	unsigned char move;		// 	in this example, to know the movement direction of the sprite
	   							
	   	
   	};
   	
   	struct sprite sprite00;	
	
    unsigned char sc,i,j;
    pointer=0;
    sprite00.sp1=sprite1;
	sprite00.sp0=sprite1;
	sprite00.ox=20;
	sprite00.oy=70; 	
	sprite00.cx=20;
	sprite00.cy=70; 	
	sprite00.move1=3;
	cpc_SuperbufferAddress(sprite00); //first time it's important to do this
	
	
    
  	establecer_colores();
   	cpc_SetModo(0);
   	
    draw_tilemap();
	cpc_ShowTileMap(0);		//rellena el buffer con el mapa y lo envía a pantalla

	while(1){
		cpc_ResetTouchedTiles();		//clear touched tile table	
		sc=1;
		if (cpc_TestKey(0)==1 && sprite00.cx<56) {
			
			if (sprite00.cx==52 && pointer<94){	// Left scroll condition
				for (j=0;j<6;j++) {
					cpc_ScrollLeft0();
					drawColumn();
					cpc_ScrollLeft();
				}
				cpc_SpUpdX(sprite00,-12);		//because screen is scrolled 6 times = 12 tiles
				cpc_PutSpTileMap(sprite00);	    //to mantain sprite in its relative position
				sc=0;
			}
			
			if (sc) cpc_SpUpdX(sprite00,1);	
		 }
		if (cpc_TestKey(1)==1 && sprite00.cx>0) {
			
			if (sprite00.cx==3 && pointer>3){ // Right scroll condition
				for (j=0;j<6;j++) {				// scroll 6 times
					cpc_ScrollRight0();
					drawColumnI();
					cpc_ScrollRight();
				}
				cpc_SpUpdX(sprite00,12);		//because screen is scrolled 6 times = 12 tiles
				cpc_PutSpTileMap(sprite00);		//to mantain sprite in its relative position
				sc=0;
			}
			if (sc) cpc_SpUpdX(sprite00,-1);
		}
		
		// more sprite movement
		if (cpc_TestKey(2)==1 && sprite00.cy>0) cpc_SpUpdY(sprite00,-1);			
		if (cpc_TestKey(3)==1 && sprite00.cy<112) cpc_SpUpdY(sprite00,1);
		
		cpc_PutSpTileMap(sprite00);	
		cpc_UpdScr();
		cpc_PutTrSpTileMap2b(sprite00);
		cpc_ShowTouchedTiles();
	}
}
