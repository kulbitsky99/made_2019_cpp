CC=g++

all: bint unit_test

BigInt.o:
	$(CC) -c BigInt.cpp BigInt.h

main.o: 
	$(CC) -c main.cpp

BigInt_test.o: 
	$(CC) -c BigInt_test.cpp

bint: main.o BigInt.o
	$(CC) -o bint main.o BigInt.o

unit_test: BigInt_test.o BigInt.o
	$(CC) -o unit_test BigInt_test.o BigInt.o

run:
	./bint

test:
	./unit_test

clean:
	rm -rf  *.o *.gch bint unit_test