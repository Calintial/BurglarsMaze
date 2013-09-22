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
	matriz[1][6] = 3;
	matriz[2][5] = 3;
	matriz[2][6] = 3;






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