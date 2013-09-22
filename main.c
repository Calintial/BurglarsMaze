#include <cpcrslib.h>
#include "keyboard.h"
#include "mapa.h"
#include "sprites.h"
#include "bomba.h"
#include <stdio.h>


main(){
	int *matriz[22];
	mysprite sp1;
	
	int timeToUpdate = 40;

	int cont = 0;
	

	sp1.pX = 19;
	sp1.pY = 10;
	sp1.pXold = 19;
	sp1.pYold = 10;
	sp1.Width = 1;
	sp1.Height = 1;
	sp1.sp = rojo;

	//initBomb();

	cpc_SetModo(0);
	
	init_tilemap(matriz);
	draw_tilemap(matriz);

	
	while(1){
		timeToUpdate--;
		if(timeToUpdate<=0) {
			timeToUpdate = 100;
			
			if(cont<40)
			{
				ReadKeyboard();
				
				//Movimiento
				if(IsKeyPressed(Key_W) && matriz[sp1.pY-1][sp1.pX] != 1 && matriz[sp1.pY-1][sp1.pX] != 2) sp1.pY--;
				if(IsKeyPressed(Key_A) && matriz[sp1.pY][sp1.pX-1] != 1 && matriz[sp1.pY][sp1.pX-1] != 2) sp1.pX--;
				if(IsKeyPressed(Key_S) && matriz[sp1.pY+1][sp1.pX] != 1 && matriz[sp1.pY+1][sp1.pX] != 2) sp1.pY++;
				if(IsKeyPressed(Key_D) && matriz[sp1.pY][sp1.pX+1] != 1 && matriz[sp1.pY][sp1.pX+1] != 2) sp1.pX++;
	
				
				//Poner bomba
				if(IsKeyPressed(Key_Space))
				{
					putBomb(sp1.pX, sp1.pY,matriz);
				}

				cont = 0;			
			}
			else
			{
				cont++;
			}
			
			updateSprite(sp1);
			if(bomb_exist)
			{
				updateSpriteBomb(matriz);
				if(explosion_exist)
				{
			    	if(bombCollide(sp1))
		      	 		cpc_PrintGphStrXY("BOOOOM; X(",200,0);
				}

			}

		}
	}
}
