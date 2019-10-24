#include <iostream>

class LinearAllocator
{
private:
	int maxSize_ = 0;
	char* offset_ = nullptr;
	char* memory_ = nullptr;
public:
	LinearAllocator() = default;
    LinearAllocator(int maxSize) : maxSize_(maxSize) {
    	memory_ = (char*) malloc(maxSize * sizeof(char));
    	offset_ = memory_;
    	std::cout << "Buffer of size " << maxSize << " created. Ready to be used." << '\n';
    	std::cout << '\n';
    };
    ~LinearAllocator() {
    	free(memory_);
    	std::cout << "Buffer of size " << maxSize_ << " deleted." << '\n';
    	std::cout << '\n';
    }

    char* GetMemory();
    char* GetOffset();
    char* alloc(int size);
    void reset();
};

char* LinearAllocator::GetMemory()
{
	return memory_;
}

char* LinearAllocator::GetOffset()
{
	return offset_;
}

char* LinearAllocator::alloc(int size)
{

	if((offset_ - memory_) + size <= maxSize_)
	{
		offset_ += size;
		if((offset_ - memory_) < maxSize_)
		{
			std::cout << "Offset is currently on " << offset_ - memory_ << " position." << '\n';
			std::cout << "Available data is from " << (offset_ - size) - memory_ << " to " << (offset_ - 1) - memory_ << " position." << '\n';
			std::cout << '\n';
		}
		else
		{
			std::cout << "Available data is from " << (offset_ - size) - memory_ << " to " << (offset_ - 1) - memory_ << " position." << '\n';
			std::cout << "Free space is over. If you want more space, please, reset the buffer and use memory again." << '\n';
			std::cout << '\n';		
		}
		return offset_ - size;
	}
	else
	{
		std::cout <<"There are only " << maxSize_ - (offset_ - memory_) << " bytes left. Please, try one more time." << '\n';
		std::cout << '\n';
		return nullptr;
	}


}

void LinearAllocator::reset()
{
	offset_ = memory_;
	std::cout << "Successful reset" << '\n';
	std::cout << "Offset is currently on " << offset_ - memory_ << " position." << '\n';	
	std::cout << '\n';
}