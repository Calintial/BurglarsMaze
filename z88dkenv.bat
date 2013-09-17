@echo off
rem *********************************
rem ** z88dk environment variables **
rem *********************************
rem
rem **************************************************
rem ** You can call this file from the command line **
rem ** before running the compiler executables; or  **
rem ** from inside another .bat file using the CALL **
rem ** statement.                                   **
rem **************************************************

IF NOT "%Z88DK_ENV_id295441%"=="" GOTO exit_without_settings
SET Z80_OZFILES=C:\PROGRA~1\Z88DK\lib\
SET ZCCCFG=C:\PROGRA~1\Z88DK\lib\config\
SET PATH=C:\PROGRA~1\Z88DK\bin;%PATH%
SET Z88DK_ENV_id295441=true
GOTO the_end

:exit_without_settings
rem echo Nothing to set :-)
:the_end
