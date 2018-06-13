#!/bin/sh

RED='\033[0;31m'
NC='\033[0m'

if [ -f /usr/lib/libmath.so ]; then
	echo "[${RED}LOG${NC}] Deleting libmath library from /usr/lib."
	sudo rm -rf /usr/lib/libmath.so
else
	echo "[${RED}LOG${NC}] libmath shared library doesn't exist in lib directory."
fi

if [ -f /usr/lib/libmath.so ]; then
	echo "[${RED}LOG${NC}] Deleting liblog library from /usr/lib."
	sudo rm -rf /usr/lib/liblog.so
else
	echo "[${RED}LOG${NC}] liblpg shared library doesn't exist in lib directory."
fi

if [ -f /usr/bin/ccalc ]; then
	echo "[${RED}LOG${NC}] Deleting ccalc binary from /usr/bin."
	sudo rm -rf /usr/bin/ccalc
else
	echo "[${RED}LOG${NC}] ccalc binary doesn't exist in /usr/bin."
fi

if [ -d bin ]; then
	echo "[${RED}LOG${NC}] Deleting bin directory."
	rm -rf bin
else
	echo "[${RED}LOG${NC}] bin directory doesn't exist."
fi

echo "[${RED}LOG${NC}] Creating bin directory."
mkdir bin

echo "[${RED}LOG${NC}] Compiling frontend."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -c calc/main.cpp

echo "[${RED}LOG${NC}] Compiling libmath library."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -c -fPIC libmath/libmath.cpp

echo "[${RED}LOG${NC}] Linking libmath into shared library."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -shared -o bin/libmath.so libmath.o

echo "[${RED}LOG${NC}] Compiling liblog library."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -c -fPIC liblog/liblog.cpp

echo "[${RED}LOG${NC}] Linking liblog into shared library."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -shared -o bin/liblog.so liblog.o

echo "[${RED}LOG${NC}] Linking frontend with library into applet."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -o bin/ccalc main.o -lmath -llog

echo "[${RED}LOG${NC}] Statically linking binary for portability."
g++ -Ilibmath -Iliblog -Lbin -Wall -pedantic -g -o bin/ccalc_s main.o libmath.o liblog.o -lstdc++

echo "[${RED}LOG${NC}] Moving object files."
if [ -d obj ]; then
	echo "[${RED}LOG${NC}] obj directory already exists."
	rm -rf obj
else
	echo "[${RED}LOG${NC}] obj directory doesn't exist."
fi

mkdir obj
mv *.o obj

echo "[${RED}LOG${NC}] Done."
