zcc +cpc TileMapConf.asm -create-app -make-app -O3 -unsigned -o mapa.bin mapa.c -lcpcrslib -lndos
CPCDiskXP -File mapa.bin -AddAmsdosHeader 6000 -AddToNewDsk mapa.dsk