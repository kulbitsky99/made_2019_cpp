#include "format.h"

int main()
{
	auto text = format("{1}+{1} = {0}", "two", "one");
	assert(text == "one+one = two");
	text = format("{2} and {0} eto my {1}", "mother", "family", "father");
	assert(text == "father and mother eto my family");
	text = format("{2} and {} eto my {1}", "mother", "family", "father");
	//assert(text == "father and mother eto my family");

	return 0;
}