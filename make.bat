zcc +cpc TileMapConf.asm -create-app -make-app -O3 -unsigned -o hello.bin helloWorld.c -lcpcrslib -lndos
CPCDiskXP -File hello.bin -AddAmsdosHeader 6000 -AddToNewDsk hello.dsk