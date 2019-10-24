#include "calc.cpp"

using namespace std;

const char * tests[5] = {
	"2+2*4--5",
	"3/5--2",
	"-3+5/2+2",
	"(2+3)*2",
	"0  +   --2     *5/ 2"
};

int results[5] = {15, 2, 1, 10, 5};


void check_calc(bool expr, int test_num)
{
        if(expr == true)
            cout << "Unit-test " << test_num << " passed successfully" << endl;
        else
        {
            cout << "Unit-test" << test_num << " failed" << endl; 
        }


}


int main()
{	


for(int i = 0; i < 5; i++)
{
    Calculation calc_function(tests[i]);
	check_calc(calc_function.Calculate() == results[i], i);
}

return 0;

}
