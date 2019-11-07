#include "library-parser.h"

void MyNumberHandler(const std::string& data)
{
	std::cout << "Received number = " << data << "\n";
}

void MyStringHandler(const std::string& data)
{
	std::cout << "Received string: " << data << "\n";
}

void StartHandler()
{
	std::cout << "Ready to parse tokens." << '\n';
} 

void EndHandler()
{
	std::cout << "Parsing completed." << '\n';
}

int main()
{
	Handler handler;
	handler.regist(	MyNumberHandler, MyStringHandler,
					StartHandler, EndHandler);
	handler.parse();
	return 0;
}