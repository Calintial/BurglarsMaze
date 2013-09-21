typedef struct 
{
   	int sp;		//2 bytes 	01
   	unsigned char cx, cy;	//2 bytes 	coordenadas nuevas	89
}mysprite;

void putSprite(mysprite* sprite)
{
	int coord = cpc_GetScrAddress(sprite->cx,sprite->cy);
	cpc_PutSprite(sprite->sp, coord);
}



