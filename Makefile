CC=g++
CXXFLAGS=-Iinclude -Llib -std=c++11 -Wall -pedantic -g

install: all
	sudo cp bin/ccalc /usr/bin

all: main.o test.o
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) -s obj/main.o -o bin/ccalc -leverything -static
	$(CC) $(CXXFLAGS) -s obj/test.o -o bin/test -leverything -static
	$(CC) $(CXXFLAGS) obj/main.o -o bin/ccalc_debug -leverything -static
	$(CC) $(CXXFLAGS) obj/test.o -o bin/test_debug -leverything -static

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp

test.o: src/test.cpp
	$(CC) $(CXXFLAGS) -c src/test.cpp

clean:
	rm -rf bin obj
	if [ -f /usr/bin/ccalc ]; then sudo rm -rf /usr/bin/ccalc; fi
