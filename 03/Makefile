CC=g++

all: lib

lib: library-parser.o 
	$(CC) -o  lib library-parser.o

library-parser.o: 
	$(CC) -c library-parser.cpp library-parser.h

run:
	./lib

clean:
	rm -rf *.o *.gch lib
