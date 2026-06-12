#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _array(other._array) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        if (this->_N < other._N)
    }
    return *this;
}

Span::~Span() {
}