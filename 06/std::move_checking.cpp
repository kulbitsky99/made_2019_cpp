#include <iostream>

void test(int &&)
{
	std::cout << "rvalue\n";
}

int main()
{
	int x = 5;
	test(std::move(x));
	std::cout << x << '\n';
	return 0;
}