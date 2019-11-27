CC=g++

all: test

test: test.o
	$(CC) -o test test.o

test.o: 
	$(CC) -c test.cpp format.h

run:
	./test

clean:
	rm -rf  *.o *.gch test