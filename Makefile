CC=g++
CXXFLAGS=-Wall -Werror -pedantic -g
CXXLINKFLAGS=-static

BINDIR=bin
OBJDIR=obj
INCLUDEDIR=include

OBJS=main.o

STD=c++11
TARGET=ccalc

$(TARGET): all

install: all
	sudo cp bin/ccalc /usr/bin

all: clean $(OBJS)
	mkdir $(BINDIR) $(OBJDIR)
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -$(CXXFLAGS) $(OBJS) -o bin/$(TARGET) $(CXXLINKFLAGS)
	mv *.o $(OBJDIR)

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log
	if [ -f /usr/bin/ccalc ]; then sudo rm -rf /usr/bin/ccalc; fi
