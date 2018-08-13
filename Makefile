CC=g++
CXXFLAGS=-Wall -Iinclude -pedantic -g

install: main.o test.o liblog.o libmath.o
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) -s obj/main.o obj/liblog.o obj/libmath.o -o bin/ccalc -static
	$(CC) $(CXXFLAGS) -s obj/test.o obj/libmath.o -o bin/test -static
	$(CC) $(CXXFLAGS) obj/main.o obj/liblog.o obj/libmath.o -o bin/ccalc_debug -static
	$(CC) $(CXXFLAGS) obj/test.o obj/libmath.o -o bin/test_debug -static
	sudo cp bin/ccalc /usr/bin

all: main.o test.o liblog.o libmath.o
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d bin ]; then rm -rf bin; fi
	mkdir bin obj
	mv *.o obj
	$(CC) $(CXXFLAGS) -s obj/main.o obj/liblog.o obj/libmath.o -o bin/ccalc -static
	$(CC) $(CXXFLAGS) -s obj/test.o obj/libmath.o -o bin/test -static
	$(CC) $(CXXFLAGS) obj/main.o obj/liblog.o obj/libmath.o -o bin/ccalc_debug -static
	$(CC) $(CXXFLAGS) obj/test.o obj/libmath.o -o bin/test_debug -static

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp

test.o: src/test.cpp
	$(CC) $(CXXFLAGS) -c src/test.cpp

liblog.o: src/liblog.cpp
	$(CC) $(CXXFLAGS) -c src/liblog.cpp

libmath.o: src/libmath.cpp
	$(CC) $(CXXFLAGS) -c src/libmath.cpp

clean:
	rm -rf bin obj
	if [ -f /usr/bin/ccalc ]; then sudo rm -rf /usr/bin/ccalc; fi
