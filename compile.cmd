@echo off

IF NOT EXIST bin\ goto BIN_NOT_EXIST
IF EXIST bin\ goto BIN_EXIST

:COMPILE
echo [LOG] Compiling frontend.
g++ -Ilibmath -Lbin -Wall -pedantic -g -c calc/main.cpp

echo [LOG] Compiling libmath library.
g++ -Ilibmath -Lbin -Wall -pedantic -g -c -fPIC libmath/libmath.cpp

echo [LOG] Linking libmath into shared library.
g++ -Ilibmath -Lbin -Wall -pedantic -g -shared -o bin/libmath.dll libmath.o

echo [LOG] Linking frontend with library into applet.
g++ -Ilibmath -Lbin -Wall -pedantic -g -o bin/calc.exe main.o -lmath

echo [LOG] Making PE binary for portability.
g++ -Ilibmath -Lbin -Wall -pedantic -g -o bin/calc_pe.exe main.o libmath.o -static

del /Q *.o

echo.

pause
exit

:BIN_EXIST
del /S /Q bin
goto BIN_NOT_EXIST

echo.

:BIN_NOT_EXIST
mkdir bin
goto COMPILE