#include "calc.h"

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
    if(s[p] <= '0' || s[p] >= '9')
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

int main(int argc, char ** argv)
{
 
    int result = 0;
    result = G(argv[2]);
    cout << result << endl;
    return 0;
}
