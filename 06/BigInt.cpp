#include "BigInt.h"

BigInt::BigInt() 	: big_number_(nullptr)
					, size_(0) 
{}
BigInt::BigInt(const BigInt& copied) 
{
	big_number_ = alloc(copied.size_ + 2);
	for(int i = 0; i < copied.size_; i++)
	{
		big_number_[i] = copied.big_number_[i];
	}
	size_ = copied.size_;
	sign_ = copied.sign_;
}
BigInt& BigInt::operator=(const BigInt& copied)
{
	big_number_ = (char*)realloc(big_number_, copied.size_ + 2);
	assert(big_number_);
	for(int i = 0; i < copied.size_; i++)
	{
		big_number_[i] = copied.big_number_[i];
	}
	size_ = copied.size_;
	sign_ = copied.sign_;
	return *this;
}
BigInt::BigInt(BigInt&& moved)
{
	BigInt::swap(moved);
}

BigInt& BigInt::operator=(BigInt&& moved)
{
	BigInt::swap(moved);
	return *this;
}

BigInt::BigInt(const int& number)
{
	int i = 0;
	int symb = 0, num_cp = number;
	if(number >= 0)
		sign_ = true;
	else
	{
		sign_ = false;
		num_cp = fabs(num_cp);
	}
	big_number_ = alloc(number_size(num_cp) + 2);
	while(num_cp != 0)
	{
		symb = num_cp % 10;
		big_number_[i] = symb + '0';
		num_cp /= 10;
		i++;
	}
	size_ = i;

}

BigInt::BigInt(int&& number)
{
	int i = 0;
	int symb = 0;
	if(number >= 0)
		sign_ = true;
	else
	{
		sign_ = false;
		number = fabs(number);
	}

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

int BigInt::number_size(int number)
{
	int size = 0;
	while(number)
	{
		number /= 10;
		size++;
	}
	return size;
}
char* BigInt::alloc(int size)
{
	char* memory_ = (char*) calloc(size, sizeof(char));
	assert(memory_);
	return memory_;
}

void BigInt::swap(BigInt & rhs)
{
	std::swap(big_number_, rhs.big_number_);
	std::swap(size_, rhs.size_);
	std::swap(sign_, rhs.sign_);

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

BigInt& BigInt::operator-=(const BigInt& second_value)//takes unsigned numbers in my realization(ignore sign), but the answer has sign
{
	int symb = 0, mind = 0, result_size_ = 0;
	bool null_check = false;
	int buffer_size = second_value.size_;
	result_size_ = size_;
	for(int i = 0; i < buffer_size; i++)
	{
		if((big_number_[i] < second_value.big_number_[i]))
		{
			mind = 1;
			symb = big_number_[i + 1] - '0' - 1;
			big_number_[i + 1] = ((symb + 10) % 10) + '0';
			if(big_number_[i + 1] == '9')
			{
				null_check = true;
				int j = i + 2;
				while(big_number_[j] == '0')
				{
					big_number_[j] = '9';
					j++;
				}
				big_number_[j]--;
			}
		}
		else
			mind = 0;
		symb = 	(big_number_[i] - '0') - 
				(second_value.big_number_[i] - '0') + mind * 10;
		big_number_[i] = symb + '0';
	}
	
	for(int i = buffer_size; i < size_; i++)
		{
			if(null_check == false)
				symb = big_number_[i] - '0' - mind;
			else
				symb = big_number_[i] - '0';
			big_number_[i] = (symb % 10) + '0';
			mind = symb / 10;
		}
	while(big_number_[result_size_ - 1] == '0')
		{
			result_size_--;
		}
	size_ = result_size_;	

	return *this;	
}



BigInt operator+(const BigInt& first_value, const BigInt& second_value)
{
	if((first_value.sign_ == true) && (second_value.sign_ == true))
	{
		BigInt result = first_value;
		result += second_value;
		result.sign_ = true;
		return result;	
	}
	if((first_value.sign_ == false) && (second_value.sign_ == false))
	{
		BigInt result = first_value;
		result += second_value;
		result.sign_ = false;
		return result;	
	}
	if((first_value.sign_ == false) && (second_value.sign_ == true))
	{
		if(second_value >= first_value)
		{
			BigInt result = second_value;
			result -= first_value;
			result.sign_ = true;
			return result;
		}
		else
		{
			BigInt result = first_value;
			result -= second_value;
			result.sign_ = false;
			return result;
		}

	}
	if((first_value.sign_ == true) && (second_value.sign_ == false))
	{
		if(second_value > first_value)
		{
			BigInt result = second_value;
			result -= first_value;
			result.sign_ = false;
			return result;
		}
		else
		{
			BigInt result = first_value;
			result -= second_value;
			result.sign_ = true;
			return result;
		}
	}

}

BigInt operator-(const BigInt& first_value, const BigInt& second_value)
{
	if((first_value.sign_ == true) && (second_value.sign_ == true))
	{
		if(first_value >= second_value)
		{
			BigInt result = first_value;
			result -= second_value;
			result.sign_ = true;
			return result;
		}
		else
		{
			BigInt result = second_value;
			result -= first_value;
			result.sign_ = false;
			return result;
		}	
	}
	if((first_value.sign_ == false) && (second_value.sign_ == false))
	{
		if(second_value >= first_value)
		{
			BigInt result = second_value;
			result -= first_value;
			result.sign_ = true;
			return result;
		}
		else
		{
			BigInt result = first_value;
			result -= second_value;
			result.sign_ = false;
			return result;
		}	
	}
	if((first_value.sign_ == true) && (second_value.sign_ == false))
	{
		BigInt result = first_value;
		result += second_value;
		result.sign_ = true;
		return result;	
	}
	if((first_value.sign_ == false) && (second_value.sign_ == true))
	{
		//std::cout << first_value << " " << second_value << '\n';
		BigInt result = first_value;
		result += second_value;
		result.sign_ = false;
		return result;	
	}
}

std::ostream & operator<<(std::ostream & stream, const BigInt & number)
{
		if(number.sign_ == false)
			std::cout << "-";
        for(int i = number.size_ - 1; i >= 0; i--)
        {
                std::cout << number.big_number_[i];
        }
        return stream;
}