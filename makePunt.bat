zcc +cpc TileMapConf.asm -create-app -make-app -O3 -unsigned -o punt.bin puntuacion.c -lcpcrslib -lndos
CPCDiskXP -File punt.bin -AddAmsdosHeader 6000 -AddToNewDsk punt.dsk