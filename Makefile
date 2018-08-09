CC=g++
CXXFLAGS=-Wall -pedantic -g

INCLUDES=-Iinclude

install: main.o liblog.o libmath.o
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	mkdir bin obj
	mv *.o obj
	$(CC) $(INCLUDES) $(CXXFLAGS) obj/main.o obj/liblog.o obj/libmath.o -o bin/ccalc
	sudo cp bin/ccalc /usr/bin

all: main.o liblog.o libmath.o
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	mkdir bin obj
	mv *.o obj
	$(CC) $(INCLUDES) $(CXXFLAGS) obj/main.o obj/liblog.o obj/libmath.o -o bin/ccalc
	
main.o: src/main.cpp
	$(CC) $(INCLUDES) $(CXXFLAGS) -c src/main.cpp

liblog.o: src/liblog.cpp
	$(CC) $(INCLUDES) $(CXXFLAGS) -c src/liblog.cpp

libmath.o: src/libmath.cpp
	$(CC) $(INCLUDES) $(CXXFLAGS) -c src/libmath.cpp

clean:
	sudo rm -rf bin obj
	if [ -f /usr/bin/ccalc ]; then sudo rm -rf /usr/bin/ccalc; fi
