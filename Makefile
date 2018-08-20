CC=g++
CXXFLAGS=-Iinclude -Llib -std=c++11 -Wall -pedantic -g
CXXLINKFLAGS=-leverything -static

PRODUCT=ccalc

install: all
	sudo cp bin/ccalc /usr/bin

all: clean main.o
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) -s obj/main.o -o bin/$(PRODUCT) $(CXXLINKFLAGS)
	$(CC) $(CXXFLAGS) obj/main.o -o bin/$(PRODUCT)_debug $(CXXLINKFLAGS)

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp

clean:
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	if [ -f /usr/bin/ccalc ]; then sudo rm -rf /usr/bin/ccalc; fi
