#include <chrono>
#include <iostream>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};

int main()
{
    int n = 10000, s = 0;
    int * A = new int [10000 * 10000];
    using matrix = int (*)[10000];//двумерный массив с 3 столбцами
    matrix M = (matrix) A;
    for(int i = 0; i < 10; i++)
    {
    Timer t;
    s = 0;
    for(int count_cals = 0; count_cals < 10000; count_cals++)
        for(int count_rows = 0; count_rows < 10000; count_rows++)
    {
        s += M[count_rows][count_cals];
    }
    }

    delete [] A;
    return s;
}