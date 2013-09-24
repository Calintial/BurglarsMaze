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
		pintaInicio();
		
		if(cpc_TestKey(9)==1)
		{
			timeToUpdate = 2500;
			cont = 0;



			sp1.pX = 21;
			sp1.pY = 9;
			sp1.pXold = 21;
			sp1.pYold = 9;
			sp1.Width = 1;
			sp1.Height = 1;
			sp1.sp = ladron;

			// ================ MIRAR ANTES DE DEBUGUEAR =============================

			// si comentas toda la inicialización, funciona, muestra el personaje y el score,
			// y cuando va a leer la matriz explota porque no está inicializada

			// si solo comentas draw, crearEnemigo y updateSprite, no llega a funcionar, muestra una línea y peta

			// si comentas el bucle principal completo, el mapa se dibuja correctamente, y aparece el enemigo, 
			// con las letras del menú puestas por encima (porque no hace ClrScr)

			// no sé qué puede ser, no veo que sea una instrucción concreta la que hace que pete,
			// es la combinación de todas, algo raro está pasando a bajo nivel :S

			cpc_ClrScr();
			init_tilemap(matriz);
			draw_tilemap(matriz);
			crearEnemigo();	
			updateSprite(sprite_enemigo);

			while(1){
				int puntos = 0;
				int numMonedas = 76;
				timeToUpdate--;
				if(timeToUpdate<=0) {
					//timeToUpdate = 5500;
					timeToUpdate = 2500;
					printPuntos(puntos);
					if(cont<40)
					{
						ReadKeyboard();
						movimientoEnemigo(matriz,sp1);
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
					
					updateSprite(sp1);
					updateSprite(sprite_enemigo);

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
			    				cpc_ClrScr();
				      	 		break;
					    	}
						}

					}

				}

				if(puntos == numMonedas){
					cpc_ClrScr();
					printYouWin(puntos);
					while(cpc_TestKey(8)!=1 && cpc_TestKey(7)!=1){}
					cpc_ClrScr();
					break;
				}
			}			
		}

	}while(cpc_TestKey(7)==0);

}
