#include "BigInt.h"

int main()
{
	BigInt a = 999972;
	BigInt b = 345;
	std::cout << a << "\n\n";
	BigInt c = a + b;
	std::cout << a << "\n\n";
	if(b <= a)
	 	std::cout << c;
	return 0;
}