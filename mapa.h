void init_tilemap(int *matriz[]) {
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
	/*int linea21[40];
	int linea22[40];*/
	
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
	/*matriz[20] = linea21;
	matriz[21] = linea22;*/
	
	//   [fila][columna]
	
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 40; j++)
		{
			matriz[i][j] = 0;
		}
	}

	//matriz[][] = ;
	matriz[6][1] = 2;
	matriz[9][1] = 1;
	matriz[10][1] = 1;
	matriz[11][1] = 1;
	matriz[6][2] = 2;
	matriz[9][2] = 1;
	matriz[10][2] = 1;
	matriz[11][2] = 1;
	matriz[14][2] = 1;
	matriz[15][2] = 1;
	matriz[16][2] = 1;
	matriz[1][3] = 1;
	matriz[2][3] = 1;
	matriz[3][3] = 1;
	matriz[6][3] = 1;
	matriz[11][3] = 1;
	matriz[14][3] = 1;
	matriz[1][4] = 1;
	matriz[2][4] = 1;
	matriz[3][4] = 1;
	matriz[6][4] = 1;
	matriz[11][4] = 1;
	matriz[14][4] = 1;
	matriz[17][4] = 1;
	matriz[18][4] = 1;
	matriz[1][5] = 3;
	matriz[2][5] = 3;
	matriz[3][5] = 2;
	matriz[6][5] = 1;
	matriz[7][5] = 3;
	matriz[8][5] = 3;
	matriz[11][5] = 2;
	matriz[14][5] = 1;
	matriz[1][6] = 3;
	matriz[2][6] = 3;
	matriz[3][6] = 2;
	matriz[6][6] = 1;
	matriz[7][6] = 3;
	matriz[8][6] = 3;
	matriz[11][6] = 2;
	matriz[14][6] = 1;
	matriz[15][6] = 1;
	matriz[16][6] = 1;
	matriz[1][7] = 1;
	matriz[2][7] = 1;
	matriz[3][7] = 1;
	matriz[4][7] = 1;
	matriz[5][7] = 1;
	matriz[6][7] = 1;
	matriz[7][7] = 1;
	matriz[8][7] = 1;
	matriz[9][7] = 1;
	matriz[10][7] = 1;
	matriz[11][7] = 1;
	matriz[12][7] = 1;
	matriz[13][7] = 1;
	matriz[14][7] = 1;
	matriz[1][8] = 3;
	matriz[2][8] = 3;
	matriz[4][8] = 2;
	matriz[7][8] = 3;
	matriz[8][8] = 3;
	matriz[9][8] = 1;
	matriz[10][8] = 3;
	matriz[11][8] = 3;
	matriz[14][8] = 1;
	matriz[17][8] = 1;
	matriz[18][8] = 1;
	matriz[1][9] = 3;
	matriz[2][9] = 3;
	matriz[4][9] = 2;
	matriz[7][9] = 3;
	matriz[8][9] = 3;
	matriz[9][9] = 1;
	matriz[10][9] = 3;
	matriz[11][9] = 3;
	matriz[14][9] = 1;
	matriz[1][10] = 1;
	matriz[2][10] = 1;
	matriz[3][10] = 2;
	matriz[4][10] = 2;
	matriz[7][10] = 1;
	matriz[8][10] = 1;
	matriz[9][10] = 1;
	matriz[14][10] = 2;
	matriz[17][10] = 3;
	matriz[18][10] = 3;
	matriz[1][11] = 3;
	matriz[2][11] = 3;
	matriz[4][11] = 2;
	matriz[9][11] = 1;
	matriz[14][11] = 2;
	matriz[17][11] = 3;
	matriz[18][11] = 3;
	matriz[1][12] = 3;
	matriz[2][12] = 3;
	matriz[4][12] = 2;
	matriz[9][12] = 1;
	matriz[14][12] = 1;
	matriz[15][12] = 1;
	matriz[16][12] = 1;
	matriz[17][12] = 1;
	matriz[18][12] = 1;
	matriz[1][13] = 1;
	matriz[2][13] = 1;
	matriz[3][13] = 2;
	matriz[4][13] = 2;
	matriz[9][13] = 1;
	matriz[1][14] = 3;
	matriz[2][14] = 3;
	matriz[4][14] = 2;
	matriz[9][14] = 1;
	matriz[10][14] = 3;
	matriz[11][14] = 3;
	matriz[1][15] = 3;
	matriz[2][15] = 3;
	matriz[4][15] = 2;
	matriz[9][15] = 1;
	matriz[10][15] = 3;
	matriz[11][15] = 3;
	matriz[1][16] = 1;
	matriz[2][16] = 1;
	matriz[3][16] = 2;
	matriz[4][16] = 2;
	matriz[9][16] = 1;
	matriz[10][16] = 1;
	matriz[11][16] = 1;
	matriz[12][16] = 1;
	matriz[13][16] = 1;
	matriz[14][16] = 1;
	matriz[15][16] = 1;
	matriz[16][16] = 1;
	matriz[17][16] = 2;
	matriz[18][16] = 2;
	matriz[12][17] = 2;
	matriz[14][17] = 3;
	matriz[15][17] = 3;
	matriz[16][17] = 1;
	matriz[12][18] = 2;
	matriz[14][18] = 3;
	matriz[15][18] = 3;
	matriz[16][18] = 1;
	matriz[12][19] = 2;
	matriz[13][19] = 1;
	matriz[14][19] = 1;
	matriz[15][19] = 1;
	matriz[16][19] = 1;
	matriz[17][19] = 2;
	matriz[18][19] = 2;
	matriz[3][20] = 2;
	matriz[4][20] = 2;
	matriz[6][20] = 2;
	matriz[7][20] = 2;
	matriz[12][20] = 2;
	matriz[14][20] = 2;
	matriz[16][20] = 2;
	matriz[2][21] = 2;
	matriz[5][21] = 1;
	matriz[8][21] = 2;
	matriz[12][21] = 2;
	matriz[14][21] = 2;
	matriz[16][21] = 2;
	matriz[1][22] = 2;
	matriz[3][22] = 3;
	matriz[4][22] = 3;
	matriz[5][22] = 1;
	matriz[6][22] = 3;
	matriz[7][22] = 3;
	matriz[8][22] = 1;
	matriz[12][22] = 2;
	matriz[14][22] = 2;
	matriz[16][22] = 2;
	matriz[3][23] = 3;
	matriz[4][23] = 3;
	matriz[5][23] = 1;
	matriz[6][23] = 3;
	matriz[6][23] = 3;
	matriz[7][23] = 3;
	matriz[8][23] = 1;
	matriz[12][23] = 2;
	matriz[14][23] = 2;
	matriz[16][23] = 2;
	matriz[3][24] = 1;
	matriz[4][24] = 1;
	matriz[5][24] = 1;
	matriz[6][24] = 1;
	matriz[7][24] = 1;
	matriz[8][24] = 1;
	matriz[9][24] = 1;
	matriz[10][24] = 1;
	matriz[11][24] = 1;
	matriz[12][24] = 1;
	matriz[13][24] = 1;
	matriz[14][24] = 1;
	matriz[15][24] = 1;
	matriz[16][24] = 1;
	matriz[17][24] = 1;
	matriz[18][24] = 1;
	matriz[3][25] = 3;
	matriz[4][25] = 3;
	matriz[5][25] = 1;
	matriz[6][25] = 3;
	matriz[7][25] = 3;
	matriz[12][25] = 2;
	matriz[13][25] = 1;
	matriz[14][25] = 2;
	matriz[15][25] = 1;
	matriz[17][25] = 3;
	matriz[18][25] = 3;
	matriz[3][26] = 3;
	matriz[4][26] = 3;
	matriz[5][26] = 1;
	matriz[6][26] = 3;
	matriz[7][26] = 3;
	matriz[12][26] = 2;
	matriz[13][26] = 1;
	matriz[14][26] = 2;
	matriz[15][26] = 1;
	matriz[17][26] = 3;
	matriz[18][26] = 3;
	matriz[1][27] = 2;
	matriz[2][27] = 2;
	matriz[3][27] = 1;
	matriz[4][27] = 1;
	matriz[5][27] = 1;
	matriz[6][27] = 1;
	matriz[7][27] = 1;
	matriz[8][27] = 1;
	matriz[12][27] = 2;
	matriz[13][27] = 2;
	matriz[14][27] = 2;
	matriz[15][27] = 2;
	matriz[6][28] = 1;
	matriz[7][28] = 1;
	matriz[12][28] = 1;
	matriz[13][28] = 2;
	matriz[14][28] = 1;
	matriz[15][28] = 2;
	matriz[6][29] = 2;
	matriz[12][29] = 1;
	matriz[13][29] = 1;
	matriz[14][29] = 1;
	matriz[15][29] = 1;
	matriz[16][29] = 1;
	matriz[17][29] = 1;
	matriz[18][29] = 1;
	matriz[3][30] = 1;
	matriz[6][30] = 2;
	matriz[12][30] = 1;
	matriz[13][30] = 3;
	matriz[14][30] = 3;
	matriz[15][30] = 1;
	matriz[16][30] = 1;
	matriz[17][30] = 3;
	matriz[18][30] = 3;
	matriz[3][31] = 1;
	matriz[4][31] = 1;
	matriz[5][31] = 1;
	matriz[6][31] = 1;
	matriz[7][31] = 1;
	matriz[8][31] = 1;
	matriz[9][31] = 1;
	matriz[10][31] = 2;
	matriz[11][31] = 2;
	matriz[12][31] = 1;
	matriz[13][31] = 3;
	matriz[14][31] = 3;
	matriz[15][31] = 1;
	matriz[16][31] = 1;
	matriz[17][31] = 3;
	matriz[18][31] = 3;
	matriz[3][32] = 1;
	matriz[9][32] = 1;
	matriz[12][32] = 1;
	matriz[15][32] = 2;
	matriz[16][32] = 2;
	matriz[3][33] = 1;
	matriz[6][33] = 1;
	matriz[7][33] = 2;
	matriz[8][33] = 2;
	matriz[9][33] = 1;
	matriz[12][33] = 1;
	matriz[15][33] = 2;
	matriz[16][33] = 2;
	matriz[3][34] = 1;
	matriz[4][34] = 3;
	matriz[5][34] = 3;
	matriz[6][34] = 1;
	matriz[12][34] = 1;
	matriz[15][34] = 1;
	matriz[16][34] = 1;
	matriz[3][35] = 1;
	matriz[4][35] = 3;
	matriz[5][35] = 3;
	matriz[6][35] = 1;
	matriz[10][35] = 3;
	matriz[11][35] = 3;
	matriz[12][35] = 1;
	matriz[15][35] = 1;
	matriz[16][35] = 1;
	matriz[3][36] = 1;
	matriz[4][36] = 1;
	matriz[5][36] = 1;
	matriz[6][36] = 1;
	matriz[7][36] = 1;
	matriz[8][36] = 1;
	matriz[10][36] = 3;
	matriz[11][36] = 3;
	matriz[12][36] = 1;
	matriz[13][36] = 2;
	matriz[14][36] = 2;
	matriz[15][36] = 1;
	matriz[16][36] = 1;
	matriz[17][36] = 2;
	matriz[18][36] = 2;
	matriz[9][37] = 1;
	matriz[10][37] = 1;
	matriz[11][37] = 1;
	matriz[12][37] = 1;
	matriz[4][38] = 1;
	matriz[5][38] = 1;

	/*
	for(i=0;i<11;i++) {
		for(j=0;j<20;j++) {
			matriz[i][39-j] = matriz[i][j];
			matriz[21-i][j] = matriz[i][j];
			matriz[21-i][39-j] = matriz[i][j];
		}
	}
	*/
	for(i=0;i<22;i++) {
		for(j=0;j<40;j++) {
			if(i==0 || j==0 || j==39 || i==19) {
				matriz[i][j] = 1;
			}
			else {
				//matriz[i][j] = 0;
			}
		}
	}
}

void draw_tilemap(int *matriz[])
{
	int i, j;
	for(i=0;i<20;i++) {
		for(j=0;j<40;j++) {
			putTile(matriz[i][j],j*2,i*8);
		}
	}
}