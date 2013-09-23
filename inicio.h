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
	cpc_PrintGphStrXY("PULSA E PARA EMPEZAR;",5,130);
	cpc_PrintGphStrXY("PULSA X PARA SALIR;",5,142);
	cpc_PrintGphStrXY("PULSA R PARA REDEFINIR LAS TECLAS:",5,154);

	              
	if (cpc_TestKey(8)==1)
	{ 
		//Redefinir teclado
		cpc_AssignKey(0,0x0000);
		cpc_AssignKey(1,0x0000);
		cpc_AssignKey(2,0x0000);
		cpc_AssignKey(3,0x0000);
		cpc_AssignKey(4,0x0000);
		redefine_tecla(0,"ARRIBA");
		redefine_tecla(2,"ABAJO");
		redefine_tecla(1,"IZQUIERDA");
		redefine_tecla(3,"DERECHA"); 
		redefine_tecla(4,"BOMBA");             
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