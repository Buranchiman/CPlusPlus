#include "Span.hpp"

Span::SpanFullException::SpanFullException(const std::string& msg) : std::runtime_error(msg) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _array(other._array) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        for (unsigned int i = 0; i < _N; i++)
            _array.push_back(other._array[i]);
        if (this->_N < other._N)
            throw (SpanFullException("Size of other Span too big to be copied with = \n"));
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(const int number)
{
    if (_array.size() >= _N)
        throw (SpanFullException("Cannot add number span is already full\n"));
    else
        _array.push_back(number);
}

unsigned int Span::longestSpan()
{
    std::vector<unsigned int> copy(_array);

    std::sort(copy.begin(), copy.end());

    return (copy.back() - copy[0]);
}
