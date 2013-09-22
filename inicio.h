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
	unsigned char menu;
	cpc_SetColour(0,0x14);  // Fondo
	cpc_SetColour(0x10,0xef41f); //borde

//Valores que se ven bien --> 0, 2, 8, 10, 32, 34, 40, 42, 128, 130, 136, 138, 160, 162, 168, 170
	setColor(0,170);
	cpc_PrintGphStrXY("CALINTIAL TEAM",11,38);
	setColor(0,128);
	cpc_PrintGphStrXY("PRESENTS",15,46);
	setColor(0,138);
	cpc_PrintGphStrXY("TITLE GAME",16,68);
	setColor(0,168);
	cpc_PrintGphStrXY("R:",5,174);
	setColor(0,162);
	cpc_PrintGphStrXY("REDEFINE;",8,174);
	setColor(0,168);
	cpc_PrintGphStrXY("E:",24,174);
	setColor(0,162);
	cpc_PrintGphStrXY("EMPEZAR",27,174);


	// Redefinir tecla R
	cpc_AssignKey(8,0x4604);
	// Redefinir tecla E	
	cpc_AssignKey(9,0x4704);

	cpc_AssignKey(0,0x4708);
	cpc_AssignKey(1,0x4820);
	cpc_AssignKey(2,0x4710);
	cpc_AssignKey(3,0x4720);
	cpc_AssignKey(4,0x4580)

	menu = 1;
	while(menu)
	{	              
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
	    if (cpc_TestKey(9)==1)
	    	menu=0;	
    }

    cpc_SetColour(0,0);  // Fondo
    cpc_ClrScr();
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