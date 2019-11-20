#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>

class BigInt
{
private:
	char* big_number_;
	size_t size_;
	//bool sign_;
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
		//sign_ = copied.sign_;
	}
	BigInt& operator=(const BigInt& copied)
	{
		big_number_ = (char*)realloc(big_number_, copied.size_ + 2);
		for(int i = 0; i < copied.size_; i++)
		{
			big_number_[i] = copied.big_number_[i];
		}
		size_ = copied.size_;
		//sign_ = copied.sign_;
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

	BigInt(const int& number)
	{
		int i = 0;
		int symb = 0, num_cp = number;
		big_number_ = alloc(number_size(num_cp) + 2);
		while(num_cp != 0)
		{
			symb = num_cp % 10;
			big_number_[i] = symb + '0';
			num_cp /= 10;
			i++;
		}
		size_ = i;
		// if(num_cp >= 0)
		// 	sign_ = true;
		// else
		// 	sign_ = false;

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
		// if(number >= 0)
		// 	sign_ = true;
		// else
		// 	sign_ = false;
	}
	~BigInt() = default;

	int number_size(int number);
	char* alloc(int size);
	void swap(BigInt & rhs);
	BigInt& operator+=(const BigInt& second_value);
	BigInt& operator-=(const BigInt& second_value);
	friend bool operator<(const BigInt& first_value, const BigInt& second_value);
	friend bool operator<=(const BigInt& first_value, const BigInt& second_value);
	friend bool operator>(const BigInt& first_value, const BigInt& second_value);
	friend bool operator>=(const BigInt& first_value, const BigInt& second_value);
	friend BigInt operator+(const BigInt& first_value, const BigInt& second_value);
	friend BigInt operator-(const BigInt& first_value, const BigInt& second_value);
	friend  std::ostream & operator<<(std::ostream& stream, const BigInt& number);


};


