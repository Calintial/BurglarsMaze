echo off
IF "%1"=="" GOTO Continue
IF "%2"=="" GOTO Continue

exomizer.exe raw %1 -o t.out
exoopt.exe t.out %2
del t.out

GOTO End

:Continue


echo Syntax:  exo filein fileout


:End