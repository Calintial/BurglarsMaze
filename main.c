#include <cpcrslib.h>
#include "keyboard.h"
#include "sprites.h"
#include <stdio.h>




void draw_tilemap(int *matriz[]) {
	//set the tiles of the map. In this example, the tile map is 32x16 tile
	//Tile Map configuration file: TileMapConf.asm

	int i;
	int j;
	int linea1[40];
	int linea2[40];
	int linea3[40];
	int linea4[40];
	int linea5[40];
	int linea6[40];
	int linea7[40];
	int linea8[40];
	int linea9[40];
	int linea10[40];
	int linea11[40];
	int linea12[40];
	int linea13[40];
	int linea14[40];
	int linea15[40];
	int linea16[40];
	int linea17[40];
	int linea18[40];
	int linea19[40];
	int linea20[40];
	int linea21[40];
	int linea22[40];
	
	matriz[0] = linea1;
	matriz[1] = linea2;
	matriz[2] = linea3;
	matriz[3] = linea4;
	matriz[4] = linea5;
	matriz[5] = linea6;
	matriz[6] = linea7;
	matriz[7] = linea8;
	matriz[8] = linea9;
	matriz[9] = linea10;
	matriz[10] = linea11;
	matriz[11] = linea12;
	matriz[12] = linea13;
	matriz[13] = linea14;
	matriz[14] = linea15;
	matriz[15] = linea16;
	matriz[16] = linea17;
	matriz[17] = linea18;
	matriz[18] = linea19;
	matriz[19] = linea20;
	matriz[20] = linea21;
	matriz[21] = linea22;
	
	//   [fila][columna]
	matriz[2][2] = 1;
	matriz[2][3] = 1;
	matriz[2][4] = 1;
	matriz[3][2] = 1;
	matriz[4][2] = 1;
	
	matriz[2][6] = 1;
	matriz[2][7] = 1;
	matriz[2][8] = 1;
	
	matriz[6][2] = 1;
	matriz[7][2] = 1;
	matriz[8][2] = 1;
	
	matriz[10][1] = 1;
	matriz[10][2] = 1;
	
	matriz[4][4] = 1;
	matriz[4][5] = 1;
	matriz[4][6] = 1;
	
	matriz[6][4] = 1;
	matriz[6][5] = 1;
	matriz[6][6] = 1;
	matriz[7][4] = 1;
	matriz[8][4] = 1;
	
	matriz[10][4] = 1;
	matriz[10][5] = 1;
	matriz[10][6] = 1;
	matriz[10][7] = 1;
	matriz[10][8] = 1;
	matriz[10][9] = 1;
	matriz[9][6] = 1;
	matriz[9][7] = 1;
	matriz[8][6] = 1;
	matriz[8][7] = 1;
	
	matriz[4][8] = 1;
	matriz[5][8] = 1;
	matriz[6][8] = 1;
	
	matriz[4][10] = 1;
	matriz[5][10] = 1;
	matriz[6][10] = 1;
	matriz[7][10] = 1;
	matriz[8][10] = 1;
	matriz[8][9] = 1;

	matriz[2][10] = 1;
	matriz[2][11] = 1;
	matriz[2][12] = 1;
	matriz[3][12] = 1;
	matriz[4][12] = 1;
	matriz[5][12] = 1;
	
	matriz[7][12] = 1;
	matriz[8][12] = 1;
	matriz[8][13] = 1;
	matriz[9][13] = 1;
	matriz[9][12] = 1;
	matriz[10][11] = 1;
	matriz[10][12] = 1;
	matriz[10][13] = 1;
	
	matriz[4][14] = 1;
	matriz[5][14] = 1;
	matriz[6][14] = 1;
	
	matriz[2][14] = 1;
	matriz[2][15] = 1;
	matriz[2][16] = 1;
	matriz[2][17] = 1;
	matriz[3][16] = 1;
	matriz[4][16] = 1;
	
	matriz[6][16] = 1;
	matriz[7][16] = 1;
	matriz[8][16] = 1;
	matriz[8][15] = 1;
	
	matriz[10][15] = 1;
	
	matriz[10][17] = 1;
	matriz[10][18] = 1;
	
	matriz[8][18] = 1;
	matriz[8][19] = 1;
	
	matriz[1][19] = 1;
	matriz[2][19] = 1;
	matriz[3][19] = 1;
	matriz[4][18] = 1;
	matriz[4][19] = 1;
	matriz[5][18] = 1;
	matriz[5][19] = 1;
	matriz[6][18] = 1;
	matriz[6][19] = 1;
	
	matriz[1][1] = 2;
	matriz[1][5] = 2;
	matriz[1][9] = 2;
	matriz[1][13] = 2;
	matriz[1][18] = 2;
	matriz[3][3] = 2;
	matriz[3][5] = 2;
	matriz[3][7] = 2;
	matriz[3][9] = 2;
	matriz[3][11] = 2;
	matriz[3][13] = 2;
	matriz[3][15] = 2;
	matriz[3][17] = 2;
	matriz[3][18] = 2;
	matriz[5][1] = 2;
	matriz[5][3] = 2;
	matriz[5][7] = 2;
	matriz[5][15] = 2;
	matriz[5][17] = 2;
	matriz[6][11] = 2;
	matriz[6][13] = 2;
	matriz[7][5] = 2;
	matriz[7][7] = 2;
	matriz[7][8] = 2;
	matriz[7][9] = 2;
	matriz[7][13] = 2;
	matriz[7][14] = 2;
	matriz[7][15] = 2;
	matriz[7][17] = 2;
	matriz[9][1] = 2;
	matriz[9][3] = 2;
	matriz[9][5] = 2;
	matriz[9][8] = 2;
	matriz[9][10] = 2;
	matriz[9][11] = 2;
	matriz[9][14] = 2;
	matriz[9][16] = 2;
	matriz[9][17] = 2;

	
	for(i=0;i<11;i++) {
		for(j=0;j<20;j++) {
			matriz[i][39-j] = matriz[i][j];
			matriz[21-i][j] = matriz[i][j];
			matriz[21-i][39-j] = matriz[i][j];
		}
	}
	
	for(i=0;i<22;i++) {
		for(j=0;j<40;j++) {
			if(i==0 || j==0 || j==39 || i==21) {
				matriz[i][j] = 1;
			}
			else {
				//matriz[i][j] = 0;
			}
		}
	}
}



main(){
	mysprite sp1,sp2,sp3;
	int i, j;
	
	int timeToUpdate = 40;
	
	int *matriz[22];
	

	sp1.pX = 19;
	sp1.pY = 10;
	sp1.pXold = 19;
	sp1.pYold = 10;
	sp1.sp = rojo;

	sp2.pX = 11;
	sp2.pY = 10;
	sp2.pXold = 11;
	sp2.pYold = 10;
	sp2.sp = punto;

	cpc_SetModo(0);
	
	draw_tilemap(matriz);
	for(i=0;i<22;i++) {
		for(j=0;j<40;j++) {
			putTile(matriz[i][j],j*2,i*8);
		}
	}
	
	while(1){
		timeToUpdate--;
		if(timeToUpdate<=0) {
			timeToUpdate = 40;
			
			ReadKeyboard();
			
			if(IsKeyPressed(Key_W)) sp1.pY--;
			if(IsKeyPressed(Key_A)) sp1.pX--;
			if(IsKeyPressed(Key_S)) sp1.pY++;
			if(IsKeyPressed(Key_D)) sp1.pX++;
			if(sp1.pX<=1)sp1.pX=1;
			else if(sp1.pX>=38)sp1.pX=38;
			if(sp1.pY<=1)sp1.pY=1;
			else if(sp1.pY>=20)sp1.pY=20;
			
			updateSprite(sp1);
			updateSprite(sp2);
		}
	}
}
