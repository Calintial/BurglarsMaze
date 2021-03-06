#include <cpcrslib.h>
#include <stdio.h>
#include <stdlib.h>	

#include "keyboard.h"
#include "inicio.h"
#include "mapa.h"
#include "sprites.h"
#include "bomba.h"
#include "personaje.h"




#asm
._mostrar2 defb 0,0,0,0
#endasm

main(){
	int *matriz[22];
	mysprite sp1;
	
	int timeToUpdate;

	int cont;

	int puntos = 0;
	int estado = 0;

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

	// cpc_AssignKey(0, 0x4704);
	// cpc_AssignKey(1, 0x4780);
	do
	{
		pintaInicio(puntos,estado);

		
		if(cpc_TestKey(9)==1)
		{
			timeToUpdate = 500;
			cont = 0;
			puntos = 0;
			estado = 0;



			sp1.pX = 1;
			sp1.pY = 3;
			sp1.pXold = 1;
			sp1.pYold = 3;
			sp1.Width = 1;
			sp1.Height = 1;
			sp1.sp = ladron;

			cpc_ClrScr();
			init_tilemap(matriz);
			draw_tilemap(matriz);

			crearEnemigo();	
			updateSprite(sprite_enemigo,matriz);
			updateSprite(sprite_enemigo2,matriz);
			initBomb();

			while(1){
				
				int numMonedas = 76;
				timeToUpdate--;
				if(timeToUpdate<=0) {

					//timeToUpdate = 5500;
					timeToUpdate = 500;
					printPuntos(puntos);

					if(cont<40)
					{
						ReadKeyboard();
						movimientoEnemigo(sprite_enemigo,matriz,sp1);
						movimientoEnemigo(sprite_enemigo2,matriz,sp1);
						//Movimiento

						if(cpc_TestKey(0)==1 && matriz[sp1.pY-1][sp1.pX] != 1 && matriz[sp1.pY-1][sp1.pX] != 2){sp1.pY--; sp1.sp=ladron;} 
						if(cpc_TestKey(1)==1 && matriz[sp1.pY][sp1.pX-1] != 1 && matriz[sp1.pY][sp1.pX-1] != 2){sp1.pX--; sp1.sp=ladronizq;} 
						if(cpc_TestKey(2)==1 && matriz[sp1.pY+1][sp1.pX] != 1 && matriz[sp1.pY+1][sp1.pX] != 2){sp1.pY++; sp1.sp=ladron;} 
						if(cpc_TestKey(3)==1 && matriz[sp1.pY][sp1.pX+1] != 1 && matriz[sp1.pY][sp1.pX+1] != 2){sp1.pX++; sp1.sp=ladronder;} 
			
						
						//Poner bomba
						if(cpc_TestKey(4)==1)
						{
							putBomb(sp1.pX, sp1.pY,matriz);
						}

						cont++;		
					}
					else
					{
						cont = 0;
						
					}
					
					updateSprite(sp1,matriz);
					updateSprite(sprite_enemigo,matriz);
					updateSprite(sprite_enemigo2,matriz);

	                if(matriz[sp1.pY][sp1.pX]==3)
					{
						puntos++;
						matriz[sp1.pY][sp1.pX]=0;
					}

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
								estado = 2;
			    				cpc_ClrScr();
				      	 		break;
					    	}
						}

					}

					if(RectangleColission(sp1,sprite_enemigo) || RectangleColission(sp1,sprite_enemigo2)){
						cpc_ClrScr();
						estado = 2;
						break;
					}

				}

				if(puntos == numMonedas){
					cpc_ClrScr();
					estado = 1;
					break;
				}
			}			
		}

	}while(cpc_TestKey(7)==0);

}
