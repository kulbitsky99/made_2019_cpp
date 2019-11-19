#include "BigInt.h"

void BigInt::swap(BigInt & rhs)
{
	std::swap(big_number_, rhs.big_number_);
	std::swap(size_, rhs.size_);
}

bool operator<(const BigInt& first_value, const BigInt& second_value)
{
	if(first_value.size_ > second_value.size_)
		return false;
	if(first_value.size_ < second_value.size_)
		return true;
	int counter = first_value.size_;
	int first_comp = 0, second_comp = 0;
	while(counter >= 0)
	{
		first_comp = first_value.big_number_[counter] - '0';
		second_comp = second_value.big_number_[counter] - '0';
		if(first_comp > second_comp)
		{
			return false;
		}
		if(first_comp < second_comp)
		{
			return true;
		}
		counter--;
	}
	return false;
}

bool operator<=(const BigInt& first_value, const BigInt& second_value)
{
	if(first_value.size_ > second_value.size_)
		return false;
	if(first_value.size_ < second_value.size_)
		return true;
	int counter = first_value.size_;
	int first_comp = 0, second_comp = 0;
	while(counter >= 0)
	{
		first_comp = first_value.big_number_[counter] - '0';
		second_comp = second_value.big_number_[counter] - '0';
		if(first_comp > second_comp)
		{
			return false;
		}
		if(first_comp < second_comp)
		{
			return true;
		}
		counter--;
	}
	return true;
}

bool operator>(const BigInt& first_value, const BigInt& second_value)
{
	if(first_value.size_ > second_value.size_)
		return true;
	if(first_value.size_ < second_value.size_)
		return false;
	int counter = first_value.size_;
	int first_comp = 0, second_comp = 0;
	while(counter >= 0)
	{
		first_comp = first_value.big_number_[counter] - '0';
		second_comp = second_value.big_number_[counter] - '0';
		if(first_comp > second_comp)
		{
			return true;
		}
		if(first_comp < second_comp)
		{
			return false;
		}
		counter--;
	}
	return false;
}

bool operator>=(const BigInt& first_value, const BigInt& second_value)
{
	if(first_value.size_ > second_value.size_)
		return true;
	if(first_value.size_ < second_value.size_)
		return false;
	int counter = first_value.size_;
	int first_comp = 0, second_comp = 0;
	while(counter >= 0)
	{
		first_comp = first_value.big_number_[counter] - '0';
		second_comp = second_value.big_number_[counter] - '0';
		if(first_comp > second_comp)
		{
			return true;
		}
		if(first_comp < second_comp)
		{
			return false;
		}
		counter--;
	}
	return true;
}


BigInt& BigInt::operator+=(const BigInt& second_value)
{
	int symb = 0;
	int mind = 0;
	int result_size_ = 0;
	int buffer_size = std::min(size_, second_value.size_);
	result_size_ = std::max(size_, second_value.size_);
	for(int i = 0; i < buffer_size; i++)
	{
		symb = 	big_number_[i] - '0' + 
				second_value.big_number_[i] - '0' + mind;
		big_number_[i] = (symb % 10) + '0';
		mind = symb / 10;
	}
	if(size_ > second_value.size_)
	{
		for(int i = buffer_size; i < size_; i++)
		{
			symb = big_number_[i] - '0' + mind;
			big_number_[i] = (symb % 10) + '0';
			mind = symb / 10;
		}
		if(mind == 1)
		{
			big_number_[size_] = 1 + '0';
			result_size_++;
		}
	}
	if(size_ <= second_value.size_)
	{
		for(int i = buffer_size; i < second_value.size_; i++)
		{
			symb = 	big_number_[i] - '0' + mind;
			big_number_[i] = (symb % 10) + '0';
			mind = symb / 10;
		}
		if(mind == 1)
		{
			big_number_[second_value.size_] = 1 + '0';
			result_size_++;
		}
	}
	size_ = result_size_;

	return *this;	
}

BigInt operator+(const BigInt& first_value, const BigInt& second_value)
{
	BigInt result = first_value;
	result += second_value;
	return result;
}

std::ostream & operator<<(std::ostream & stream, const BigInt & number)
{
        for(int i = number.size_ - 1; i >= 0; i--)
        {
                std::cout << number.big_number_[i];
        }
        return stream;
}