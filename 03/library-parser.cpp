#include "library-parser.h"

void MyNumberHandler(const int& number)
{
	std::cout << "Received number = " << number << "\n\n";
}

void MyStringHandler(const std::string& data)
{
	std::cout << "Received string: " << data << "\n\n";
}

void StartHandler()
{
	std::cout << "Ready to parse tokens." << "\n\n";
} 

void EndHandler()
{
	std::cout << "Parsing completed." << "\n\n";
}

int main()
{
	Handler handler;
	handler.regist(	MyNumberHandler, MyStringHandler,
					StartHandler, EndHandler);
	handler.parse();
	return 0;
}