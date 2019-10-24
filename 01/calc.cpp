#include "calc.h"

using namespace std;

int Calculation::Calculate()
{
    int val_first = Calculation::GetPlus_Minus();
    while(expr_[position_] == ' ') position_++;
    if(expr_[position_] == '\0')
        return val_first;
    else
    {
        err_.flag_ = ACTIVE;
        err_.elem_numb_ = position_;
        err_.symb_ = expr_[position_];
        return val_first;
    }
}

int Calculation::GetPlus_Minus()
{
    int val_first = Calculation::GetMult_Del();
    while(expr_[position_] == ' ') position_++;
    while(expr_[position_] == '+' || expr_[position_] == '-')
    {
        int op = expr_[position_];
        position_++;
        while(expr_[position_] == ' ') position_++;
        int val_second = Calculation::GetMult_Del();
        if(op == '+')
            val_first += val_second;
        else
            val_first -= val_second;
    }
    return val_first;
}

int Calculation::GetMult_Del()
{
    int val_first = Calculation::GetBracket();
    while(expr_[position_] == ' ') position_++;
    while(expr_[position_] == '*' || expr_[position_] == '/')
    {
        int op = expr_[position_];
        position_++;
        while(expr_[position_] == ' ') position_++;
        int val_second = Calculation::GetBracket();
        if(op == '*')
            val_first *= val_second;
        else
            val_first /= val_second;
    }
    return val_first;
}

int Calculation::GetBracket()
{
    while(expr_[position_] == ' ') position_++;
    if(expr_[position_] == '(')
    {
        position_++;
        while(expr_[position_] == ' ') position_++;
        int val = Calculation::GetPlus_Minus();
        assert(expr_[position_] == ')');
        position_++;
        while(expr_[position_] == ' ') position_++;
        return val;
    }
    else if(expr_[position_] == '-')
    {
        position_++;
        while(expr_[position_] == ' ') position_++;
        return -Calculation::GetNumber();
    }
         else return Calculation::GetNumber();
}

int Calculation::GetNumber()
{
    int value = 0;
    while(expr_[position_] == ' ') position_++;
    while(expr_[position_] >= '0' && expr_[position_] <= '9')
    {
        value = value * 10 + expr_[position_] - '0';
        position_++;
    }
    while(expr_[position_] == ' ') position_++;
    return value;
}