#include "calc.hpp"

using namespace std;



int main(int argc, char ** argv)
{
 
    int result = 0;
    result = G(argv[2]);
    if(result == WRONG_SYMB)
    {
    	return -1;
    }
    else
    {	
		cout << "result = " << result << endl;
		return 0;
    }
}
