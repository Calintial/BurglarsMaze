zcc +cpc -create-app -make-app -O3 -unsigned -o main.bin main.c -lcpcrslib -lndos
CPCDiskXP -File main.bin -AddAmsdosHeader 6000 -AddToNewDsk calintial.dsk