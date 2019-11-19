#include "BigInt.cpp"

int main()
{
	BigInt a = 999972;
	BigInt b = 345;
	std::cout << a << "\n";
	BigInt c = a + b;
	assert((c <= a + b) && (c >= a + b));
	std::cout << a << "\n";
	std::cout << b << "\n";
	if(b <= a)
	 	std::cout << c;
	return 0;
}