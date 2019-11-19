CC=g++

all: bint unit_test

calc.o:
	$(CC) -c BigInt.cpp BigInt.h

bint: 
	$(CC) -o bint main.cpp

unit_test: 
	$(CC) -o unit_test BigInt_test.cpp

run:
	./bint

test:
	./unit_test

clean:
	rm -rf  *.o *.gch bint unit_test