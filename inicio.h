

extern unsigned char mostrar2[];

//Valores que se ven bien --> 0, 2, 8, 10, 32, 34, 40, 42, 128, 130, 136, 138, 160, 162, 168, 170
void setColor (unsigned char fondo,unsigned char t){
	 cpc_SetInkGphStr(0,fondo);
	 cpc_SetInkGphStr(1,t);
     cpc_SetInkGphStr(2,t);
     cpc_SetInkGphStr(3,t);
}


redefine_tecla(unsigned char tecla, unsigned char texto[]){
	unsigned char t;
	cpc_PrintGphStrXY(texto,10,190);
	cpc_RedefineKey(tecla);
	cpc_PrintGphStrXY(";;;;;;;;;",10,190);		
}

void pintaInicio(void)
{
//Valores que se ven bien --> 0, 2, 8, 10, 32, 34, 40, 42, 128, 130, 136, 138, 160, 162, 168, 170
	setColor(0,170);
	cpc_PrintGphStrXY("CALINTIAL TEAM",11,38);
	setColor(0,128);
	cpc_PrintGphStrXY("PRESENTS",15,46);
	setColor(0,138);
	cpc_PrintGphStrXY("TITLE GAME",16,68);
	setColor(0,168);
	cpc_PrintGphStrXY("PRESS E TO START;",5,130);
	cpc_PrintGphStrXY("PRESS X TO EXIT;",5,142);
	cpc_PrintGphStrXY("PRESS R TO REDEFINE KEYS:",5,154);

	              
	if (cpc_TestKey(8)==1)
	{ 
		//Redefinir teclado
		cpc_AssignKey(0,0x0000);
		cpc_AssignKey(1,0x0000);
		cpc_AssignKey(2,0x0000);
		cpc_AssignKey(3,0x0000);
		cpc_AssignKey(4,0x0000);
		redefine_tecla(0,"UP");
		redefine_tecla(2,"DOWN");
		redefine_tecla(1,"LEFT");
		redefine_tecla(3,"RIGHT"); 
		redefine_tecla(4,"BOMB");             
	}
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

void printYouWin(int puntos){
	setColor(0,170);
	cpc_PrintGphStrXY("YOU;WIN",11,38);
	cpc_PrintGphStrXY("SCORE:",30,58);
    numero(puntos);
    cpc_PrintGphStrXY(mostrar2,50,58);
    cpc_PrintGphStrXY("PRESS X TO EXIT;",5,142);
	cpc_PrintGphStrXY("PRESS R TO GO BACK TO THE MAIN MENU:",5,154);
}