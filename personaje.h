
#include <stdlib.h>
#include <time.h>
extern unsigned char malo12x8[];
extern unsigned char malo12x8reves[];
extern unsigned char malo24x16[];
extern unsigned char malo24x16reves[];
extern unsigned char mostrar[];


// Compiling:
// zcc +cpc  TileMapConf.asm -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384

#asm
._mostrar defb 0,0,0,0
._malo12x8
defb 2,8
defb $3F,$00
defb $3F,$2A
defb $DA,$00
defb $CF,$00
defb $0F,$F0
defb $0F,$A0
defb $03,$00
defb $30,$00
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
}

void movimientoEnemigo(int * matriz[], mysprite* personaje){
   int movimiento_random=0; 
   int *mov[4];//Arriba, Abajo, Derecha,Izquierda
   int movimiento_siguiente=0;
   mov[0]=0;
   mov[1]=0;
   mov[2]=0;
   mov[3]=0;

   movimiento_siguiente= moverEnemigo(matriz,mov,personaje)
   if(movimiento_siguiente==0){
      ultimo_mov=0;
      sprite_enemigo.pXold=sprite_enemigo.pX;
      sprite_enemigo.pYold=sprite_enemigo.pY;
      sprite_enemigo.pY=sprite_enemigo.pY-1;
   }
   else if(movimiento_siguiente==1){
      ultimo_mov=1;
      sprite_enemigo.pXold=sprite_enemigo.pX;
      sprite_enemigo.pYold=sprite_enemigo.pY;
      sprite_enemigo.pY=sprite_enemigo.pY+1;
     /* numero(sprite_enemigo.pX);
      cpc_PrintGphStrXY(mostrar,100,0);
      numero(sprite_enemigo.pY);
      cpc_PrintGphStrXY(mostrar,200,0);*/
   }
   else if(movimiento_siguiente==2){
      ultimo_mov=2;
      sprite_enemigo.pXold=sprite_enemigo.pX;
      sprite_enemigo.pYold=sprite_enemigo.pY;
      sprite_enemigo.pX=sprite_enemigo.pX+1;
   }
   else if(movimiento_siguiente==3){
      ultimo_mov=3;
      sprite_enemigo.pXold=sprite_enemigo.pX;
      sprite_enemigo.pYold=sprite_enemigo.pY;
      sprite_enemigo.pX=sprite_enemigo.pX-1;
   }

  
}
void numero(unsigned char a){
   unsigned char b;
   b=a/10;
   mostrar[0]=b+48;
   mostrar[1]=a-b*10+48;
   mostrar[2]=0;
 
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
void moverEnemigo(int * matriz[],int *mov[],mysprite personaje){
   int cant_movimientos=0;
   int i=0;
   
   if(matriz[sprite_enemigo.pY-1][sprite_enemigo.pX]==0){
     
      mov[0]=1*random(100);
   
   }
   if(matriz[sprite_enemigo.pY+1][sprite_enemigo.pX]==0){
      mov[1]=1*random(100);
         
   }
   if(matriz[sprite_enemigo.pY][sprite_enemigo.pX+1]==0){
      mov[2]=1*random(100);

   }
  if(matriz[sprite_enemigo.pY][sprite_enemigo.pX-1]==0){
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
  /* numero(personaje->pX);
      cpc_PrintGphStrXY(mostrar,100,0);*/
   if(personaje->pX==sprite_enemigo.pX){
      if(personaje->pY>sprite_enemigo.pY && mov[1]!=0){
            return 1;
      }
      else if(mov[0]!=0){
       return 0;
    }
   }
   if(personaje->pY==sprite_enemigo.pY){
      if(personaje->pX>sprite_enemigo.pX && mov[2]!=0){
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

