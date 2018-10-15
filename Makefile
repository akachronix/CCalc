CC=g++
CXXFLAGS=-Iinclude -Llib -std=c++11 -Wall -pedantic -g
CXXLINKFLAGS=-static

OBJS=main.o

TARGET=ccalc

$(TARGET): all

install: all
	sudo cp bin/ccalc /usr/bin

all: clean $(OBJS)
	mkdir bin obj
	$(CC) $(CXXFLAGS) -s $(OBJS) -o bin/$(TARGET) $(CXXLINKFLAGS)
	mv *.o obj

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm -rf bin obj *.log
	if [ -f /usr/bin/ccalc ]; then sudo rm -rf /usr/bin/ccalc; fi
