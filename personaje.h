#include <stdlib.h>
#include <time.h>

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



#endasm



mysprite sprite_enemigo;


void crearEnemigo(){

   sprite_enemigo.pX = 10;
   sprite_enemigo.pY = 10;
   sprite_enemigo.pXold = 10;
   sprite_enemigo.pYold = 10;
   sprite_enemigo.Width = 1;
   sprite_enemigo.Height = 1;
   sprite_enemigo.sp = malo24x16;

}

void movimientoEnemigo(int * matriz[], mysprite* personaje){
   int movimiento_random=0; 
   int movimiento_siguiente=0;
   int mov_buscado=0;

   do{
      if(personaje->pX==sprite_enemigo.pX && mov_buscado==0){
         if(personaje->pY>sprite_enemigo.pY){
            movimiento_random=4;
         }
         else{
            movimiento_random=3;
         }

      }
      else if(personaje->pY==sprite_enemigo.pY && mov_buscado==0){
         if(personaje->pX>sprite_enemigo.pX){
            movimiento_random=1;
         }
         else{
            movimiento_random=2;
         }
      }
      else{
         movimiento_random = random(4);
      }
      if(moverEnemigo(movimiento_random,matriz)){
         movimiento_siguiente=1;
      }
      else{
         mov_buscado=1;
      }
   }while(movimiento_siguiente==0);         


   if (movimiento_random==1){
      cpc_SpUpdX(sprite_enemigo,1)
      sprite_enemigo.sp = malo14x16;
      movimiento_siguiente=1;
   }

   else if (movimiento_random==2 ){ 
      cpc_SpUpdX(sprite_enemigo,-1)
      sprite_enemigo.sp = malo14x16reves;
      movimiento_siguiente=1;
   }
   else if (movimiento_random==3 ){
      cpc_SpUpdY(sprite_enemigo,-1)
      movimiento_siguiente=1;
   }        
   else{
      cpc_SpUpdY(sprite_enemigo,1)
      movimiento_siguiente=1;
   }

   
}


int moverEnemigo(int mov, int * matriz[]){

	if(mov==1){
		if(matriz[sprite_enemigo.pY][sprite_enemigo.pX+1]!=0){
			return 1;
		}
		return 0;
	}
	else if(mov==2){
		if(matriz[sprite_enemigo.pY][sprite_enemigo.pX-1]!=0){
			return 1;
		}
      return 0;
   }
   else if(mov==3){
    if(matriz[sprite_enemigo.pY+1][sprite_enemigo.pX]!=0){
      return 1;
   }
   return 0;
   }

   else{
    if(matriz[sprite_enemigo.pY-1][sprite_enemigo.pX]!=0){
      return 1;
   }
   return 0;
   }
}

int random(int max) {
	int r=0;	
	r= (rand() %max );
	return r;

}

