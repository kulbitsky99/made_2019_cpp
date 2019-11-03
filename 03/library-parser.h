#include <iostream>
#include <fstream>
#include <string>

class Handler
{
public:
	using Handlers = void (*)(const std::string& data);
	void hand(const std::string& data, Handlers callback) 
	{
		callback(data);
	}
};

void NumberHandler(const std::string& data)
{
	std::cout << "Received number = " << data << "\n";
}

void StringHandler(const std::string& data)
{
	std::cout << "Received string: " << data << "\n";
}
