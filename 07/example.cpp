#include <iostream> 
#include <cassert>
#include <vector>
#include <string>

template <class T>
std::string& print(std::vector<std::string>& tokens, std::string&& input, T&& val)
{
	tokens.push_back(val);
	std::string finder; 
	int counter = 0;
	for(auto token : tokens)
	{
		finder = "{" + std::to_string(counter) + "}";
		//std::cout << finder << "\n";

		input.find(finder);
		size_t pos = input.find(finder);
	    while(pos != std::string::npos) 
	    {
	        input.replace(pos, finder.size(), token);
	        pos = input.find(finder, pos);
    	}
    	counter++;
	}
	try
	{
		if(input.find("{") != std::string::npos)
			throw std::runtime_error("Invalid usage of operator{}");
	}
	catch (std::runtime_error e)
    {
        std::cout << "Runtime error: " << e.what() << "\n";
    }

	//std::cout << input << "\n";
	return input;

}

template <class T, class... Args>
std::string& print(std::vector<std::string>& tokens, std::string&& input, T&& val, Args&&... args)
{
	tokens.push_back(val); 
	return print(tokens, std::forward<std::string>(input), std::forward<Args>(args)...);
}

template <class T, class... Args>
std::string& format(std::string&& input, T&& val, Args&&... args)
{
	std::vector<std::string> tokens;
	tokens.push_back(val); 
	return print(tokens, std::forward<std::string>(input), std::forward<Args>(args)...);
}

int main()
{
	auto text = format("{1}+{1} = {0}", "two", "one");
	assert(text == "one+one = two");
	text = format("{2} and {0} eto my {1}", "mother", "family", "father");
	assert(text == "father and mother eto my family");
	text = format("{2} and {} eto my {1}", "mother", "family", "father");
	assert(text == "father and mother eto my family");

	return 0;
}