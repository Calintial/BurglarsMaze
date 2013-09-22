#include <cpcrslib.h>
#include "keyboard.h"
#include "mapa.h"
#include "sprites.h"
#include "bomba.h"
#include <stdio.h>
#include "personaje.h"



main(){
	int *matriz[22];
	mysprite sp1,sp2,sp3;
	
	int timeToUpdate = 40;

	int cont = 0;
	

	sp1.pX = 19;
	sp1.pY = 10;
	sp1.pXold = 19;
	sp1.pYold = 10;
	sp1.Width = 1;
	sp1.Height = 1;
	sp1.sp = rojo;

	sp2.pX = 11;
	sp2.pY = 10;
	sp2.pXold = 11;
	sp2.pYold = 10;
	sp2.Width = 1;
	sp2.Height = 1;
	sp2.sp = punto;

	//initBomb();

	cpc_SetModo(0);
	
	init_tilemap(matriz);
	draw_tilemap(matriz);

	crearEnemigo();
	while(1){
		timeToUpdate--;
		if(timeToUpdate<=0) {
			timeToUpdate = 100;
			
			if(cont<40)
			{
				ReadKeyboard();
				
				//Movimiento
				if(IsKeyPressed(Key_W) && matriz[sp1.pY-1][sp1.pX] != 1) sp1.pY--;
				if(IsKeyPressed(Key_A) && matriz[sp1.pY][sp1.pX-1] != 1) sp1.pX--;
				if(IsKeyPressed(Key_S) && matriz[sp1.pY+1][sp1.pX] != 1) sp1.pY++;
				if(IsKeyPressed(Key_D) && matriz[sp1.pY][sp1.pX+1] != 1) sp1.pX++;
				if(sp1.pX<=1)sp1.pX=1;
				else if(sp1.pX>=38)sp1.pX=38;
				if(sp1.pY<=1)sp1.pY=1;
				else if(sp1.pY>=20)sp1.pY=20;	
				
				//Poner bomba
				if(IsKeyPressed(Key_Space))
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
			updateSprite(sprite_enemigo);
			if(bomb_exist)
			{
				updateSpriteBomb();
				if(explosion_exist)
				{
			    	if(bombCollide(sp1))
		      	 		cpc_PrintGphStrXY("BOOOOM; X(",200,0);
				}

			}

		}
	}
}
