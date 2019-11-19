#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>

int number_size(int number)
{
	int size = 0;
	while(number)
	{
		number /= 10;
		size++;
	}
	return size;
}
char* alloc(int size)
{
	char* memory_ = (char*) calloc(size, sizeof(char));
	assert(memory_);
	return memory_;
}

class BigInt
{
private:
	char* big_number_;
	size_t size_;
public:
	BigInt() 	: big_number_(nullptr)
				, size_(0) 
	{}
	/*explicit*/ BigInt(const BigInt& copied) 
	{
		big_number_ = alloc(copied.size_ + 2);
		for(int i = 0; i < copied.size_; i++)
		{
			big_number_[i] = copied.big_number_[i];
		}
		size_ = copied.size_;
	}
	BigInt& operator=(const BigInt& copied)
	{
		for(int i = 0; i < copied.size_; i++)
		{
			big_number_[i] = copied.big_number_[i];
		}
		size_ = copied.size_;
		return *this;
	}
	/*explicit*/BigInt(BigInt&& moved)
	{
		BigInt::swap(moved);
	}

	BigInt& operator=(BigInt&& moved)
	{
		BigInt::swap(moved);
		return *this;
	}

	BigInt(int&& number)
	{
		int i = 0;
		int symb = 0;
		big_number_ = alloc(number_size(number) + 2);
		while(number != 0)
		{
			symb = number % 10;
			big_number_[i] = symb + '0';
			number /= 10;
			i++;
		}
		size_ = i;
	}
	~BigInt() = default;

	void swap(BigInt & rhs);
	BigInt& operator+=(const BigInt& second_value);
	friend bool operator<(const BigInt& first_value, const BigInt& second_value);
	friend bool operator<=(const BigInt& first_value, const BigInt& second_value);
	friend bool operator>(const BigInt& first_value, const BigInt& second_value);
	friend bool operator>=(const BigInt& first_value, const BigInt& second_value);
	friend BigInt operator+(const BigInt& first_value, const BigInt& second_value);
	friend  std::ostream & operator<<(std::ostream& stream, const BigInt& number);


};


