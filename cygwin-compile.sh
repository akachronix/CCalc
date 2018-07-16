#!/bin/sh

if [ -f /usr/lib/libmath.dll ]; then
	echo "[LOG] Deleting libmath library from /usr/lib."
	rm -rf /usr/lib/libmath.dll
else
	echo "[LOG] libmath shared library doesn't exist in lib directory."
fi

if [ -f /usr/lib/libmath.dll ]; then
	echo "[LOG] Deleting liblog library from /usr/lib."
	rm -rf /usr/lib/liblog.dll
else
	echo "[LOG] liblog shared library doesn't exist in lib directory."
fi

if [ -f /usr/bin/ccalc ]; then
	echo "[LOG] Deleting ccalc binary from /usr/bin."
	rm -rf /usr/bin/ccalc
else
	echo "[LOG] ccalc binary doesn't exist in /usr/bin."
fi

if [ -d bin ]; then
	echo "[LOG] Deleting bin directory."
	rm -rf bin
else
	echo "[LOG] bin directory doesn't exist."
fi

echo "[LOG] Creating bin directory."
mkdir bin

echo "[LOG] Compiling frontend."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -c calc/main.cpp

echo "[LOG] Compiling libmath library."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -c -fPIC libmath/libmath.cpp

echo "[LOG] Linking libmath into shared library."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -shared -o bin/libmath.dll libmath.o

echo "[LOG] Compiling liblog library."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -c -fPIC liblog/liblog.cpp

echo "[LOG] Linking liblog into shared library."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -shared -o bin/liblog.dll liblog.o

echo "[LOG] Linking frontend with library into applet."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -o bin/ccalc main.o -lmath -llog

echo "[LOG] Statically linking binary for portability."
g++ -I./libmath -I./liblog -L./bin -Wall -pedantic -g -o bin/ccalc_s main.o libmath.o liblog.o -static

echo "[LOG] Moving object files."
if [ -d obj ]; then
	echo "[LOG] obj directory already exists."
	rm -rf obj
else
	echo "[LOG] obj directory doesn't exist."
fi

mkdir obj
mv *.o obj

echo "[LOG] Copying cygwin1.dll."
cp /bin/cygwin1.dll bin

echo "[LOG] Copying cyggcc_s-seh-1.dll."
cp /bin/cyggcc_s-seh-1.dll bin

echo "[LOG] Copying cygstdc++-6.dll."
cp /bin/cygstdc++-6.dll bin

echo "[LOG] Done."
