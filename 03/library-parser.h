#include <iostream>
#include <fstream>
#include <string>


using Number_handlers = void (*)(const int& number);
using String_handlers = void (*)(const std::string& data);
using Default_handlers = void (*)();

bool isdigit(const char& symb)
{
	if((symb - '0' < 0) || (symb - '0' > 9))
		return false;
	else
		return true;
}

class Handler
{
private:
	bool flag_;
	std::string command_;
	Number_handlers NumberHandler_;
	String_handlers StringHandler_;
	Default_handlers StartHandler_;
	Default_handlers EndHandler_;

public:
	void regist(Number_handlers NumberHandler, String_handlers StringHandler,
				Default_handlers StartHandler, Default_handlers EndHandler)
	{
		NumberHandler_ = NumberHandler;
		StringHandler_ = StringHandler;
		StartHandler_ = StartHandler;
		EndHandler_ = EndHandler;
	}

	void number_hand(const int& number, Number_handlers callback) 
	{
		std::cout << number << " is ready to be handled" << "\n";
		callback(number);
	}

	void string_hand(const std::string& data, String_handlers callback) 
	{
		std::cout << data << " is ready to be handled" << "\n";
		callback(data);
	}

	void default_hand(Default_handlers callback)
	{
		std::cout << "Default callback is ready to be called" << "\n";
		callback();
	}

	void parse()
	{
		default_hand(StartHandler_);
		std::ifstream in("input.txt");
		int number = 0;
		while(!in.eof())
		{
			flag_ = true;
			in >> command_;
			for(int i = 0; i < command_.length(); i++)
			{
				if(isdigit(command_[i]) == false)
					flag_ = false;
			}
			if(flag_ == true)
			{
				number = atoi(command_.c_str());
				number_hand(number, NumberHandler_);
			}
			else
				string_hand(command_, StringHandler_);
		}
		in.close();
		default_hand(EndHandler_);
	}
};


