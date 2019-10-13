CC=g++

all: my_prog

my_prog: calc.o 
	$(CC) -o my_prog calc.o

calc.o: calc.cpp
	$(CC) -c calc.cpp calc.h

run: my_prog
	./my_prog calc "2 + 2 --2*4 /8+2 "

test:
	$(CC) -c test_calc.cpp calc.h
	$(CC) -o test test_calc.o
	./test



clean:
	rm -rf *.o *.gch my_prog test
