CC=g++

all: my_prog unit_test

my_prog: 
	$(CC) -o my_prog main.cpp

calc.o: calc.cpp calc.h
	$(CC) -c calc.cpp calc.h

unit_test: 
	$(CC) -o unit_test test_calc.cpp

run:
	./my_prog calc "(5+4--2)"

test:
	./unit_test

clean:
	rm -rf  *.o *.gch my_prog unit_test
