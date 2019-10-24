#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <cstring>

#define	NON_ACTIVE 0
#define	ACTIVE 1

struct Error
	{
		int flag_ = NON_ACTIVE;
		int elem_numb_;
		char symb_;
	};

class Calculation
{
private:
	int position_;
	const char * expr_;
public:
	Error err_;
	Calculation(const char * str) : position_(0), expr_(str) {};
	int Calculate();
	int GetPlus_Minus();
	int GetMult_Del();
	int GetBracket();
	int GetNumber();

}; 


