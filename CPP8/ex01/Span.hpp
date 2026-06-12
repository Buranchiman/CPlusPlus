#ifndef Span_HPP
#define Span_HPP

#include <vector>
#include <algorithm>

class Span
{
    private:
        const unsigned int _N;
        std::vector<unsigned int> _array; 
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


};

#endif /* Span_HPP */