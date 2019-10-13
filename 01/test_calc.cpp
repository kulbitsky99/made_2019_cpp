#include "calc.h"
char * tests[5] = {
	"2+2*4--5",
	"3/5--2",
	"-3+5/2+2",
	"(2+3)*2",
	"0  +   --2     *5/2"
};

int results[5] = {15, 2, 1, 10, 5};

int G(const char * str)
{
    s = str;
    p = 0;
    int val_first = GetE();
    while(s[p] == ' ') p++;
    if(s[p] == '\0')
        return val_first;
    else
    {
        cout << "I was here!" << endl;
        printf("ERROR, INVALID SIGN: %c\n", s[p]);
        cout << p << endl;
        exit(-1);
    }
}

int GetE()
{
    int val_first = GetT();
    while(s[p] == ' ') p++;
    while(s[p] == '+' || s[p] == '-')
    {
        int op = s[p];
        p++;
        while(s[p] == ' ') p++;
        int val_second = GetT();
        if(op == '+')
            val_first += val_second;
        else
            val_first -= val_second;
    }
    return val_first;
}

int GetT()
{
    int val_first = GetP();
    while(s[p] == ' ') p++;
    while(s[p] == '*' || s[p] == '/')
    {
    	int op = s[p];
        p++;
        while(s[p] == ' ') p++;
        int val_second = GetP();
        if(op == '*')
            val_first *= val_second;
        else
            val_first /= val_second;
    }
    return val_first;
}

int GetP()
{
    while(s[p] == ' ') p++;
    if(s[p] == '(')
    {
        p++;
        while(s[p] == ' ') p++;
        int val = GetE();
        assert(s[p] == ')');
        p++;
        while(s[p] == ' ') p++;
        return val;
    }
    else if(s[p] == '-')
    {
        p++;
        while(s[p] == ' ') p++;
        return -GetN();
    }
         else return GetN();
}

int GetN()
{
    int val = 0;
    while(s[p] == ' ') p++;
    if(s[p] < '0' || s[p] > '9')
    {
        printf("ERROR, INVALID SIGN: %c\n", s[p]);
        cout << p << endl;
        exit(-1);
    }
    while(s[p] >= '0' && s[p] <= '9')
    {
        val = val * 10 + s[p] - '0';
        p++;
    }
    while(s[p] == ' ') p++;
    return val;
}

void check_calc(bool expr, int test_num)
{
        if(expr == true)
                cout << "Unit-test " << test_num << "passed successfully" << endl;
        else
                cout << "Unit-test" << test_num << "failed" << endl;

}


int main()
{	

for(int i = 0; i < 5; i++)
{
	check_calc(G(tests[i]) == results[i], i);
}

return 0;

}
