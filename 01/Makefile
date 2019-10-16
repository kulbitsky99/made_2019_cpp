CC=g++

all: my_prog unit_test

my_prog: calc.o 
	$(CC) -o my_prog calc.o

calc.o: calc.cpp
	$(CC) -c calc.cpp calc.hpp calc.h

unit_test: test_calc.o
	$(CC) -o unit_test test_calc.o

test_calc.o: test_calc.cpp
	$(CC) -c test_calc.cpp calc.hpp calc.h		

run:
	./my_prog calc "2 + 2 --2*4 |8+2 "

test:
	./unit_test

clean:
	rm -rf *.o *.gch
