#include "calc.cpp"

using namespace std;



int main(int argc, char ** argv)
{
    Calculation calc_function(argv[2]);
    int result = 0;
    result = calc_function.Calculate();
    if(calc_function.err_.flag_ == ACTIVE)
    {
    	cout << "Invalid sign '"    << calc_function.err_.symb_ << "' detected on position "
                                    << calc_function.err_.elem_numb_ << ". Can't calculate this expression" << endl;
        return -1;                                
    }
    else
    {	
		cout << "result = " << result << endl;
		return 0;
    }
}
