#include "calc.h"

using namespace std;

/*it needs to be defined here so that functions GetE, GetT, GetP, GetN could use it*/
const char * expr = NULL;
int p = 0;


int G(const char * str)
{
    expr = str;
    p = 0;
    int val_first = GetE();
    while(expr[p] == ' ') p++;
    if(expr[p] == '\0')
        return val_first;
    else
    {
        cout << "Invalid sign '" << expr[p] << "' detected on position "
        								<< p << ". Can't calculate this expression" << endl;
        return WRONG_SYMB;
    }
}

int GetE()
{
    int val_first = GetT();
    while(expr[p] == ' ') p++;
    while(expr[p] == '+' || expr[p] == '-')
    {
        int op = expr[p];
        p++;
        while(expr[p] == ' ') p++;
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
    while(expr[p] == ' ') p++;
    while(expr[p] == '*' || expr[p] == '/')
    {
    	int op = expr[p];
        p++;
        while(expr[p] == ' ') p++;
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
    while(expr[p] == ' ') p++;
    if(expr[p] == '(')
    {
        p++;
        while(expr[p] == ' ') p++;
        int val = GetE();
        assert(expr[p] == ')');
        p++;
        while(expr[p] == ' ') p++;
        return val;
    }
    else if(expr[p] == '-')
    {
        p++;
        while(expr[p] == ' ') p++;
        return -GetN();
    }
         else return GetN();
}

int GetN()
{
    int value = 0;
    while(expr[p] == ' ') p++;
    while(expr[p] >= '0' && expr[p] <= '9')
    {
        value = value * 10 + expr[p] - '0';
        p++;
    }
    while(expr[p] == ' ') p++;
    return value;
}