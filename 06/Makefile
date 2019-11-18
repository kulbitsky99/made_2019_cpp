CC=g++

all: bint

bint: BigInt.o 
	$(CC) -o  bint BigInt.o

BigInt.o: 
	$(CC) -c BigInt.cpp BigInt.h

run:
	./bint

clean:
	rm -rf *.o *.gch bint