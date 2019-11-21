#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

class BigInt
{
private:
	char* big_number_;
	size_t size_;
	bool sign_;
public:
	BigInt();
	BigInt(const BigInt& copied);
	BigInt& operator=(const BigInt& copied);
	BigInt(BigInt&& moved);
	BigInt& operator=(BigInt&& moved);
	BigInt(const int& number);
	BigInt(int&& number);
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


