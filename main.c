#include <cpcrslib.h>
#include "keyboard.h"
#include "mapa.h"
#include "sprites.h"
#include "bomba.h"
#include <stdio.h>

#include "personaje.h"



main(){
	int *matriz[22];
	mysprite sp1;
	
	int timeToUpdate;

	int cont;


	cpc_SetModo(0);
	

	

	
	cpc_AssignKey(0, 0x4704);
	cpc_AssignKey(1, 0x4780);
	do
	{
		cpc_PrintGphStrXY("PULSA E PARA EMPEZAR;",0,0);
		cpc_PrintGphStrXY("PULSA X PARA SALIR;",0,10);
		if(cpc_TestKey(0)==1)
		{
			timeToUpdate = 500;

			cont = 0;
			



			sp1.pX = 21;
			sp1.pY = 9;
			sp1.pXold = 21;
			sp1.pYold = 9;
			sp1.Width = 1;
			sp1.Height = 1;
			sp1.sp = rojo;

			cpc_ClrScr();
			init_tilemap(matriz);
			draw_tilemap(matriz);
				crearEnemigo();	
				updateSprite(sprite_enemigo);

			while(1){
				timeToUpdate--;
				if(timeToUpdate<=0) {
					timeToUpdate =10000;
					
					if(cont<40)
					{
						ReadKeyboard();
						movimientoEnemigo(matriz,sp1);
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
					updateSprite(sprite_enemigo);
					if(bomb_exist)
					{
						updateSpriteBomb(matriz);
						if(explosion_exist)
						{
					    	if(bombCollide(sp1))
					    	{
					    		bomb_time = 0;
								bomb_exist = 0;
								explosion_exist = 0;
								borrarExplosion(matriz);
			    				cpc_ClrScr();
				      	 		break;
					    	}
						}

					}

				}
			}			
		}

	}while(cpc_TestKey(1)==0);

}
