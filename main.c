#include <cpcrslib.h>
#include "keyboard.h"
#include "inicio.h"
#include "mapa.h"
#include "sprites.h"
#include "bomba.h"
#include <stdio.h>

main(){
	int *matriz[22];
	mysprite sp1;
	
	int timeToUpdate;

	int cont;

	cpc_SetModo(0);

	//cpc_SetColour();

	// Redefinir tecla R
	cpc_AssignKey(8,0x4604);
	// Redefinir tecla E	
	cpc_AssignKey(9,0x4704);
	// Redefinir tecla X
	cpc_AssignKey(7, 0x4780);
	// Redefinir teclas iniciales
	cpc_AssignKey(0,0x4708);
	cpc_AssignKey(1,0x4820);
	cpc_AssignKey(2,0x4710);
	cpc_AssignKey(3,0x4720);
	cpc_AssignKey(4,0x4580);
	
	do
	{
		pintaInicio();
		
		if(cpc_TestKey(9)==1)
		{
			timeToUpdate = 2500;
			cont = 0;

			sp1.pX = 19;
			sp1.pY = 10;
			sp1.pXold = 19;
			sp1.pYold = 10;
			sp1.Width = 1;
			sp1.Height = 1;
			sp1.sp = ladron;

			cpc_ClrScr();
			init_tilemap(matriz);
			draw_tilemap(matriz);
			while(1){
				timeToUpdate--;
				if(timeToUpdate<=0) {
					timeToUpdate = 2500;
					
					if(cont<40)
					{
						ReadKeyboard();
						
						//Movimiento

						if(cpc_TestKey(0)==1 && matriz[sp1.pY-1][sp1.pX] != 1 && matriz[sp1.pY-1][sp1.pX] != 2){sp1.pY--; sp1.sp=ladron;} 
						if(cpc_TestKey(1)==1 && matriz[sp1.pY][sp1.pX-1] != 1 && matriz[sp1.pY][sp1.pX-1] != 2){sp1.pX--; sp1.sp=ladronizq;} 
						if(cpc_TestKey(2)==1 && matriz[sp1.pY+1][sp1.pX] != 1 && matriz[sp1.pY+1][sp1.pX] != 2){sp1.pY++; sp1.sp=ladron;} 
						if(cpc_TestKey(3)==1 && matriz[sp1.pY][sp1.pX+1] != 1 && matriz[sp1.pY][sp1.pX+1] != 2){sp1.pX++; sp1.sp=ladronder;} 
						if(sp1.pX<=1)sp1.pX=1;
						else if(sp1.pX>=38)sp1.pX=38;
						if(sp1.pY<=1)sp1.pY=1;
						else if(sp1.pY>=20)sp1.pY=20;
			
						
						//Poner bomba
						if(cpc_TestKey(4)==1)
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

	}while(cpc_TestKey(7)==0);

}
