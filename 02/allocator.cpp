#include "allocator.h"

using namespace std;

int main()
{
	LinearAllocator buffer(20);
	char* pointer = buffer.alloc(15);
	pointer = buffer.alloc(3);
	pointer = buffer.alloc(3);
	pointer = buffer.alloc(2);
	buffer.reset();
	pointer = buffer.alloc(15);
	return 0;
}