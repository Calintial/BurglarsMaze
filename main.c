#include <cpcrslib.h>
#include "keyboard.h"
#include "inicio.h"
#include "mapa.h"
#include "sprites.h"
#include "bomba.h"
#include <stdio.h>

main(){
	int *matriz[22];
	unsigned char bucle;
	unsigned char bucleTotal;

	mysprite sp1,sp2,sp3;
	
	int timeToUpdate;

	int cont;

	timeToUpdate = 2500;
	cont = 0;
	sp1.pX = 19;
	sp1.pY = 10;
	sp1.pXold = 19;
	sp1.pYold = 10;
	sp1.Width = 1;
	sp1.Height = 1;
	sp1.sp = ladron;

	sp2.pX = 11;
	sp2.pY = 10;
	sp2.pXold = 11;
	sp2.pYold = 10;
	sp2.Width = 1;
	sp2.Height = 1;
	sp2.sp = punto;

	//initBomb();

	cpc_SetModo(0);

	//cpc_SetColour();
	pintaInicio();
	init_tilemap(matriz);
	draw_tilemap(matriz);

	bucle=1;
	while(bucle){
		timeToUpdate--;
		if(timeToUpdate<=0) {
			timeToUpdate = 2500;
			
			if(cont<40)
			{	
				//Movimiento
				if(cpc_TestKey(0)==1 && matriz[sp1.pY-1][sp1.pX] != 1){sp1.pY--; sp1.sp=ladron;} 
				if(cpc_TestKey(1)==1 && matriz[sp1.pY][sp1.pX-1] != 1){sp1.pX--; sp1.sp=ladronizq;} 
				if(cpc_TestKey(2)==1 && matriz[sp1.pY+1][sp1.pX] != 1){sp1.pY++; sp1.sp=ladron;} 
				if(cpc_TestKey(3)==1 && matriz[sp1.pY][sp1.pX+1] != 1){sp1.pX++; sp1.sp=ladronder;} 
				if(sp1.pX<=1)sp1.pX=1;
				else if(sp1.pX>=38)sp1.pX=38;
				if(sp1.pY<=1)sp1.pY=1;
				else if(sp1.pY>=20)sp1.pY=20;
				

				//Poner bomba
				if(cpc_TestKey(4)==1)
				{
					putBomb(sp1.pX, sp1.pY);
				}

				cont = 0;			
			}
			else
			{
				cont++;
			}
			
			updateSprite(sp1);
			updateSprite(sp2);
			if(bomb_exist)
			{
				updateSpriteBomb();
				if(explosion_exist)
				{
			    	if(bombCollide(sp1))
			    	{
		      	 		cpc_PrintGphStrXY("BOOOOM; X(",100,0);
		      	 		//pintaInicio();
		      	 		//cpc_ClrScr();
			    	}
				}

			}
			//pause();
		}
	}
}
