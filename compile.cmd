@echo off

IF NOT EXIST bin\ goto BIN_NOT_EXIST
IF EXIST bin\ goto BIN_EXIST

:COMPILE
echo [LOG] Compiling frontend.
g++ -Iinclude -Wall -pedantic -g -c src/main.cpp

echo [LOG] Compiling libmath library.
g++ -Iinclude -Wall -pedantic -g -c src/libmath.cpp

echo [LOG] Compiling liblog library.
g++ -Iinclude -Wall -pedantic -g -c src/liblog.cpp

echo [LOG] Linking.
g++ -Iinclude -Wall -pedantic -g -o bin/ccalc.exe main.o libmath.o liblog.o -static

IF NOT EXIST obj\ goto OBJ_NOT_EXIST
IF EXIST obj\ goto OBJ_EXIST

:MOVE_OBJECTS
move /Y *.o obj

echo.

pause
goto EXIT

:BIN_EXIST
del /S /Q bin
goto BIN_NOT_EXIST

echo.

:BIN_NOT_EXIST
mkdir bin
goto COMPILE

:OBJ_EXIST
del /S /Q obj
goto OBJ_NOT_EXIST

:OBJ_NOT_EXIST
mkdir obj
goto MOVE_OBJECTS

:EXIT
