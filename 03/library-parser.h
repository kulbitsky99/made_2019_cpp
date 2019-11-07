#include <iostream>
#include <fstream>
#include <string>

using Handlers = void (*)(const std::string& data);
using Default_handlers = void (*)();

class Handler
{
private:
	int flag_;
	std::string command_;
	Handlers NumberHandler_;
	Handlers StringHandler_;
	Default_handlers StartHandler_;
	Default_handlers EndHandler_;

public:
	void regist(Handlers NumberHandler, Handlers StringHandler,
				Default_handlers StartHandler, Default_handlers EndHandler)
	{
		NumberHandler_ = NumberHandler;
		StringHandler_ = StringHandler;
		StartHandler_ = StartHandler;
		EndHandler_ = EndHandler;
	}

	void hand(const std::string& data, Handlers callback) 
	{
		callback(data);
	}

	void default_hand(Default_handlers callback)
	{
		callback();
	}

	void parse()
	{
		default_hand(StartHandler_);
		std::ifstream in("input.txt");
		while(!in.eof())
		{
			flag_ = 0;
			in >> command_;
			for(int i = 0; i < command_.length(); i++)
			{
				if((command_[i] - '0' < 0) || (command_[i] - '0' > 9))
					flag_++;
			}
			if(flag_ == 0)
				hand(command_, NumberHandler_);
			else
				hand(command_, StringHandler_);
		}
		in.close();
		default_hand(EndHandler_);
	}
};

