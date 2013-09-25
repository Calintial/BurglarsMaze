

extern unsigned char mostrar2[];

//Valores que se ven bien --> 0, 2, 8, 10, 32, 34, 40, 42, 128, 130, 136, 138, 160, 162, 168, 170
void setColor (unsigned char fondo,unsigned char t){
	 cpc_SetInkGphStr(0,fondo);
	 cpc_SetInkGphStr(1,t);
     cpc_SetInkGphStr(2,t);
     cpc_SetInkGphStr(3,t);
}



void pintaInicio(int puntos,int estado)
{
//Valores que se ven bien --> 0, 2, 8, 10, 32, 34, 40, 42, 128, 130, 136, 138, 160, 162, 168, 170
	
	char* texto1;
	char* texto2;
	char* texto3;

	setColor(0,128);

	if(estado == 1)
	{
		numero(puntos);
		texto1 = "YOU,WIN";
		texto2 = "SCORE:";
		texto3 = mostrar2;		
	}
	else if (estado == 2)
	{
		texto1 = "YOU;LOSE";
		texto2 = ";";
		texto3 = ";";	
	}
	else
	{
		texto1 = "CALINTIAL;TEAM";
		texto2 = "PRESENTS";
		texto3 = "TITLE;GAME";		
	}

	cpc_PrintGphStrXY(texto1,11,38);
	cpc_PrintGphStrXY(texto2,15,46);
	cpc_PrintGphStrXY(texto3,16,68);	
	cpc_PrintGphStrXY("PRESS;E;TO;START;",5,130);
	cpc_PrintGphStrXY("PRESS;X;TO;EXIT;",5,142);
}

void pause(void) {
      #asm
      ld b,7
      .pause_loop
      halt
      halt
      halt
      djnz pause_loop
      #endasm
}

void numero(unsigned char a){
    unsigned char b;
    b=a/10;

	mostrar2[0]=b+48;
	mostrar2[1]=a-b*10+48;
	mostrar2[2]=0;

	return mostrar2;
}

void printPuntos(int puntos){
        cpc_PrintGphStrXY("SCORE:",30,8);
        numero(puntos);
        cpc_PrintGphStrXY(mostrar2,50,8);
}
