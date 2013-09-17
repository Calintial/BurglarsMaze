#include "cpcrslib.h"

extern unsigned char sp_8x8[];
extern unsigned char sp_16x16[];
extern unsigned char tile_8x8[];
extern unsigned char buffer[];

#asm
._sp_8x8
defb $88,$70,$11,$E0		//MASCARA,SPRITE,MASCARA,SPRITE... La máscara se dibuja con tinta 3 en modo 1.
defb $11,$E0,$88,$70		//MASK, SPRITE, MASK, SPRITE...	 Mask is drawn using hightest ink number
defb $00,$96,$00,$96
defb $00,$F0,$00,$F0
defb $00,$F7,$00,$FE
defb $00,$C7,$00,$3E
defb $00,$F3,$00,$FC
defb $88,$70,$11,$E0

._sp_16x16
defb $88,$70,$11,$E0,$88,$70,$11,$E0	//MASCARA,SPRITE,MASCARA,SPRITE...
defb $11,$E0,$88,$70,$11,$E0,$88,$70	//MASK, SPRITE, MASK, SPRITE...
defb $00,$96,$00,$96,$00,$96,$00,$96
defb $00,$F0,$00,$F0,$00,$F0,$00,$F0
defb $00,$F7,$00,$FE,$00,$F7,$00,$FE
defb $00,$C7,$00,$3E,$00,$C7,$00,$3E
defb $00,$F3,$00,$FC,$00,$F3,$00,$FC
defb $88,$70,$11,$E0,$88,$70,$11,$E0
defb $88,$70,$11,$E0,$88,$70,$11,$E0
defb $11,$E0,$88,$70,$11,$E0,$88,$70
defb $00,$96,$00,$96,$00,$96,$00,$96
defb $00,$F0,$00,$F0,$00,$F0,$00,$F0
defb $00,$F7,$00,$FE,$00,$F7,$00,$FE
defb $00,$C7,$00,$3E,$00,$C7,$00,$3E
defb $00,$F3,$00,$FC,$00,$F3,$00,$FC
defb $88,$70,$11,$E0,$88,$70,$11,$E0
._tile_8x8
defb $07,$0E		//Sin máscara
defb $2D,$C3		//Unmasked
defb $0F,$2D
defb $0F,$2D
defb $0F,$0F
defb $0F,$2D
defb $0F,$0F
defb $07,$0E
._buffer defs 64
#endasm

main(){
	
	cpc_SetMode(1); //rutina hardware, se restaura la situación anterior al terminar la ejecución del programa
	cpc_SetColour(17,11);  //Ídem de lo mismo
	
	
	
	// Dibujar un sprite de 2x8 bytes en las coordenadas 10,90 de la pantalla
	// Put a 2x8 bytes sprite in specified coordenates
	cpc_PutTile2x8(tile_8x8,10,90);
	
	// Dibujar un sprite con máscara de dimensiones 2x8 bytes en la posición de pantalla indicada (&C00B)
	// Put a 2x8 bytes masked sprite into the specified screen adress
	cpc_PutMaskSp2x8(sp_8x8,0xc00b);
	
	// Lo mismo pero con un sprite de 4x16 bytes
	// Same but using a 4x16 bytes sprite
	// cpc_PutMaskSp4x16(sprite data,screen adress);
	cpc_PutMaskSp4x16(sp_16x16,0xc190);
	
	// Dibuja un sprite en modo 0 teniendo en cuenta que el color 0 es transparente. Se especifican las 
	// dimensiones altoxancho. 
	// This routine is for using in mode 0 due to it uses ink 0 as transparent.
	//cpc_PutSpTr(sprite data,height,widh,screen adress);
	cpc_PutSpTr(tile_8x8,8,2,0xc19b);
	// imprime un sprite de las dimensiones indicadas en la pantalla
	// Put a sprite of specified dimensions into screen.
	cpc_PutSp(tile_8x8,8,2,0xc19b);
	
	// Captura de la pantalla el area indicada y la guarda en memoria.
	// Captures a screen box of the specified dimensions and stores it onto memory
	cpc_GetSp(buffer,8,8,0xc054);
	// En este ejemplo, imprime en &C190 el area capturada .
	// In this example, prints the captured area in &c190
	cpc_PutSp(buffer,8,8,0xc190);
	while (1){}
	
	
}

