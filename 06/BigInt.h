#include <iostream>
#include <fstream>
#include <string>


int min(const int first_param,const int second_param)
{
    return first_param > second_param ? second_param : first_param;
}

int max(const int first_param,const int second_param)
{
    return first_param > second_param ? first_param : second_param;
}


class BigInt
{
private:
	char* big_number_;
	size_t size_;
public:
	BigInt() 	: big_number_(nullptr)
				, size_(0) 
	{
		big_number_ = (char*) calloc(100, sizeof(char));
	}
	/*explicit*/ BigInt(const BigInt& copied) 
	{
		big_number_ = (char*) calloc(100, sizeof(char));
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
	/*explicit*/BigInt(BigInt&& moved) 	: big_number_(std::move(moved.big_number_))
										, size_(std::move(moved.size_))
	{}

	BigInt& operator=(BigInt&& moved)
	{
		big_number_ = std::move(moved.big_number_);
		size_ = std::move(moved.size_);
		return *this;
	}

	BigInt(int&& number)
	{
		int i = 0;
		int symb = 0;
		big_number_ = (char*) calloc(100, sizeof(char));
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
	// {
	// 	size_ = 0;
	// 	free(big_number_);
	// }
	BigInt& operator+=(const BigInt& second_value);
	friend bool operator<(const BigInt& first_value, const BigInt& second_value);
	friend bool operator<=(const BigInt& first_value, const BigInt& second_value);
	friend bool operator>(const BigInt& first_value, const BigInt& second_value);
	friend bool operator>=(const BigInt& first_value, const BigInt& second_value);
	friend BigInt operator+(const BigInt& first_value, const BigInt& second_value);
	friend  std::ostream & operator<<(std::ostream& stream, const BigInt& number);


};

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
		std::cout << first_comp << " " << second_comp << "\n";
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
		std::cout << first_comp << " " << second_comp << "\n";
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
		std::cout << first_comp << " " << second_comp << "\n";
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
		std::cout << first_comp << " " << second_comp << "\n";
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
	int buffer_size = min(size_, second_value.size_);
	result_size_ = max(size_, second_value.size_);
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

BigInt operator+(const BigInt& first_value, const BigInt& second_value)//?
{
	// std::cout << first_value << "\n";
	BigInt result = first_value;
	// std::cout << first_value << "\n";
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
