IF NOT EXIST tm.dsk cpcxfs -nd cpcrs.dsk

zcc +cpc -m -create-app -make-app -O3 -unsigned -o uno.bin code.c -lcpcrslib -lndos -zorg=16384
echo cpcxfs cpcrs.dsk -f -p cpcrs.cpc
copy uno.bin e:\Raul\WinAPE

