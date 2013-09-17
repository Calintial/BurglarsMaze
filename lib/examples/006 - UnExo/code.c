#include "cpcrslib.h"
extern unsigned char binary_data[];
#asm
._binary_data
   BINARY "tonteria.exp"
#endasm

main(){
	cpc_SetModo(1);
	// UnExo disables interrupts while processing file.
	cpc_UnExo(binary_data,0xc000);

	while (1) {}
}
