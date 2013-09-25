
#include <time.h>

extern unsigned char malo12x8reves[];




// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384

#asm

._malo12x8reves
defb 2,8
defb $3F,$00
defb $3F,$2A
defb $DA,$00
defb $CF,$00
defb $0F,$F0
defb $0F,$A0
defb $03,$00
defb $30,$00
#endasm



mysprite sprite_enemigo, sprite_enemigo2;
int ultimo_mov;

void crearEnemigo(){

   sprite_enemigo.pX = 19;
   sprite_enemigo.pY = 9;
   sprite_enemigo.pXold = 19;
   sprite_enemigo.pYold =9;
   sprite_enemigo.Width = 1;
   sprite_enemigo.Height = 1;
   sprite_enemigo.sp = malo12x8reves;
   ultimo_mov=5;

   sprite_enemigo2.pX = 25;
   sprite_enemigo2.pY = 9;
   sprite_enemigo2.pXold = 25;
   sprite_enemigo2.pYold =9;
   sprite_enemigo2.Width = 1;
   sprite_enemigo2.Height = 1;
   sprite_enemigo2.sp = malo12x8reves;
   ultimo_mov=5;
}


void movimientoEnemigo(mysprite* enemigo, int * matriz[], mysprite* personaje){
   int movimiento_random=0; 
   int *mov[4];//Arriba, Abajo, Derecha,Izquierda
   int movimiento_siguiente=0;
   mov[0]=0;
   mov[1]=0;
   mov[2]=0;
   mov[3]=0;

   movimiento_siguiente= moverEnemigo(enemigo,matriz,mov,personaje);
   if(movimiento_siguiente==0){
      ultimo_mov=0;
      enemigo->pXold=enemigo->pX;
      enemigo->pYold=enemigo->pY;
      enemigo->pY=enemigo->pY-1;
   }
   else if(movimiento_siguiente==1){
      ultimo_mov=1;
      enemigo->pXold=enemigo->pX;
      enemigo->pYold=enemigo->pY;
      enemigo->pY=enemigo->pY+1;
   }
   else if(movimiento_siguiente==2){
      ultimo_mov=2;
      enemigo->pXold=enemigo->pX;
      enemigo->pYold=enemigo->pY;
      enemigo->pX=enemigo->pX+1;
   }
   else if(movimiento_siguiente==3){
      ultimo_mov=3;
      enemigo->pXold=enemigo->pX;
      enemigo->pYold=enemigo->pY;
      enemigo->pX=enemigo->pX-1;
   }

  
}
int mejor(int *mejor[]){
   int c=0;
   int maximum=mejor[0];
   int location=0;
   for (c = 0; c < 4; c++)
  {
    if (mejor[c] > maximum)
    {
       maximum  = mejor[c];
       location = c;
    }
  }
  return location;
}
void moverEnemigo(mysprite* enemigo,int * matriz[],int *mov[],mysprite personaje){
   int cant_movimientos=0;
   int i=0;
   
   if(matriz[enemigo->pY-1][enemigo->pX]==0){
     
      mov[0]=1*random(100);
   
   }
   if(matriz[enemigo->pY+1][enemigo->pX]==0){
      mov[1]=1*random(100);
         
   }
   if(matriz[enemigo->pY][enemigo->pX+1]==0){
      mov[2]=1*random(100);

   }
  if(matriz[enemigo->pY][enemigo->pX-1]==0){
      mov[3]=1*random(100);

   }
   for(i=0;i<4;i++){
      
      if(mov[i]!=0){
         cant_movimientos=cant_movimientos+1;
      }
   }

   //Mirar el personaje
   if(cant_movimientos!=1){
       if(ultimo_mov!=5){
        if(ultimo_mov==1){
          mov[0]=0;
        }
        else if(ultimo_mov==0){
          mov[1]=0;
        }
        else if(ultimo_mov==2){
          mov[3]=0;
        }
        else if(ultimo_mov==3){
          mov[2]=0;
        }

        
      }
   }
   if(personaje->pX==enemigo->pX){
      if(personaje->pY>enemigo->pY && mov[1]!=0){
            return 1;
      }
      else if(mov[0]!=0){
       return 0;
    }
   }
   if(personaje->pY==enemigo->pY){
      if(personaje->pX>enemigo->pX && mov[2]!=0){
         return 2;
      }
      else if(mov[3]!=0){
      return 3;
    }
   }

   return mejor(mov);
}

int random(int max) {
	int r=0;	
	r= (rand() %max );
	return r;

}

