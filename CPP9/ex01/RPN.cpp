#include "RPN.hpp"

RPN::RPN() : _numbers() {}

RPN::RPN(const RPN& other)
{
    _numbers = other._numbers;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _numbers = other._numbers;
    return *this;
}

RPN::~RPN() {}

bool do_operations(char c, std::stack<int> &numbers)
{
    int left;
    int right;

    right = numbers.top();
    numbers.pop();
    left = numbers.top();
    numbers.pop();
    long long res;
    switch (c)
    {
        case ('+') :
        {
            res = left + right;
            break;
        }
        case ('-') :
        {
            res = left - right;
            break;
        }
        case ('*') :
        {
            res = left * right;
            break;
        }
        case ('/') :
        {
            res = left / right;
            break;
        }
        default:
            break;
    }
    if (res < INT_MIN || res > INT_MAX)
        return (false);
    else
    {
        numbers.push(static_cast<int>(res));
        return (true);
    }
}

bool RPN::solve(std::string operation)
{
    if (operation.find_first_not_of("0123456789 +-/*") != operation.npos)
        return (false);
    int size = operation.size();
    for (int i =  0; i < size; i++)
    {
        if (i % 2 == 1 && operation[i] != ' ')
            return (false);
        if (std::string("+-/*").find(operation[i]) != std::string::npos)
        {
            if (_numbers.size() < 2)
                return (false);
            else
                do_operations(operation[i], _numbers);
        }
        if ( '0' <= operation[i] && operation[i] <= '9')
            _numbers.push(operation[i] - '0');
    }
    std::cout << _numbers.top() << std::endl;
    _numbers.pop();
    return (true);
}