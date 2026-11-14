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

void do_operations(char c, std::stack<int> &numbers)
{
    long long left;
    long long right;

    right = static_cast<long long>(numbers.top());
    numbers.pop();
    left = static_cast<long long>(numbers.top());
    numbers.pop();
    long long res = 0;
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
            if (right == 0)
                throw(std::invalid_argument("Error cannot divide by 0"));
            res = left / right;
            break;
        }
        default:
            break;
    }
    if (res < INT_MIN || res > INT_MAX)
        throw(std::invalid_argument("Error operation overflowing int max"));
    else
    {
        numbers.push(static_cast<int>(res));
        return ;
    }
}

void RPN::solve(std::string operation)
{
    if (operation.find_first_not_of("0123456789 +-/*") != operation.npos)
        throw(std::invalid_argument("Error unvalid character in parameter"));
    int size = operation.size();
    for (int i =  0; i < size; i++)
    {
        if (i % 2 == 1 && operation[i] != ' ')
            throw(std::invalid_argument("Error incorrect number space between numbers/operators"));
        if (i == size - 1 && operation[i] == ' ')
            throw(std::invalid_argument("Error trailing space"));
        if (std::string("+-/*").find(operation[i]) != std::string::npos)
        {
            if (_numbers.size() < 2)
                throw(std::invalid_argument("Error consecutive operators"));
            else
                do_operations(operation[i], _numbers);
        }
        if ( '0' <= operation[i] && operation[i] <= '9')
             _numbers.push(operation[i] - '0');
    }
    if (_numbers.size() != 1)
        throw(std::invalid_argument("Error incorrect number of numbers left at the end of operation"));
    std::cout << _numbers.top() << std::endl;
    _numbers.pop();
    return ;
}