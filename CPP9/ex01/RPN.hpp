#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <exception>

class RPN 
{
    private:
        std::stack<int> _numbers;
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();


    void solve(std::string operation);
};

#endif /* RPN_HPP */