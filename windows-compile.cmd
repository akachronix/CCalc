@echo off

IF NOT EXIST bin\ goto BIN_NOT_EXIST
IF EXIST bin\ goto BIN_EXIST

:COMPILE
echo [LOG] Compiling frontend.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -c calc/main.cpp

echo [LOG] Compiling libmath library.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -c -fPIC libmath/libmath.cpp

echo [LOG] Linking libmath into shared library.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -shared -o bin/libmath.dll libmath.o

echo [LOG] Compiling liblog library.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -c -fPIC liblog/liblog.cpp

echo [LOG] Linking liblog into shared library.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -shared -o bin/liblog.dll liblog.o

echo [LOG] Linking frontend with library into applet.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -o bin/calc.exe main.o -lmath -llog -lstdc++

echo [LOG] Making PE binary for portability.
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -o bin/calc_pe.exe main.o libmath.o liblog.o -static

IF NOT EXIST obj\ goto OBJ_NOT_EXIST
IF EXIST obj\ goto OBJ_EXIST

:MOVE_OBJECTS
move /Y *.o obj

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

:OBJ_EXIST
del /S /Q obj
goto OBJ_NOT_EXIST

:OBJ_NOT_EXIST
mkdir obj
goto MOVE_OBJECTS