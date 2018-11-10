CC=g++
CXXFLAGS=-Wall -Werror -pedantic -O2
CXXLDFLAGS=-static
STD=c++17

OBJS=main.o

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj
SRCDIR=src

TARGET=ccalc

all: $(TARGET)

$(TARGET): clean $(OBJS)
	mkdir $(BINDIR) $(OBJDIR)
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) $(OBJS) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)
	mv *.o $(OBJDIR)

main.o: $(SRCDIR)/main.cpp
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf *.log $(BINDIR) $(OBJDIR)
