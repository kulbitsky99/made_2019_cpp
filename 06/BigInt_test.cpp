#include "BigInt.h"

int main()
{
	BigInt a = 101;
	BigInt b = 2;
	std::cout << a << "\n";
	BigInt c = a - b;
	assert((c <= a - b) && (c >= a - b));
	std::cout << a << "\n";
	std::cout << b << "\n";
	if(b <= a)
	 	std::cout << c;
	b = 200045;
	c = a - b;
	std::cout << c; 
	return 0;
}