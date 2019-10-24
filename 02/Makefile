CC=g++

all: test

test: allocator.o 
	$(CC) -o  test allocator.o

allocator.o: 
	$(CC) -c allocator.cpp allocator.h

run:
	./test

clean:
	rm -rf *.o *.gch test
