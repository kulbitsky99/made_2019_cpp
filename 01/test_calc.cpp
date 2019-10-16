#include "calc.hpp"

using namespace std;

const char * tests[5] = {
	"2+2*4--5",
	"3/5--2",
	"-3+5/2+2",
	"(2+3)*2",
	"0  +   --2     *5/2"
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
    //cout << G(tests[i]) << endl;
	check_calc(G(tests[i]) == results[i], i);
}

return 0;

}
