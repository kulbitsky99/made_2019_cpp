#include "library-parser.h"

int main()
{
	Handler handler;
	int flag = 0;
	char symb;
	std::ifstream in("input.txt");
	std::string command;
	while(!in.eof())
	{
		in >> command;
		for(int i = 0; i < command.length(); i++)
		{
			if((command[i] - '0' < 0) || (command[i] - '0' > 9))
				flag++;
		}
		if(flag == 0)
			handler.hand(command, NumberHandler);
		else
			handler.hand(command, StringHandler);
		flag = 0;
	}
	std::cout << '\n';
	in.close();
	return 0;
}