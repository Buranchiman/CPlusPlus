#include "Span.hpp"

Span::SpanFullException::SpanFullException(const std::string& msg)
    : std::runtime_error(msg) {}

Span::NoSpanException::NoSpanException(const std::string& msg)
    : std::runtime_error(msg) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _array(other._array) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
	    _N = other._N;
	    _array = other._array;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(const int number)
{
	if (_array.size() >= _N)
	    throw SpanFullException("Cannot add number: Span is already full");
	_array.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_array.size() < 2)
	    throw NoSpanException("Cannot find a span: need at least 2 numbers");

	std::vector<int> copy(_array);
	std::sort(copy.begin(), copy.end());

	// Once sorted, the smallest gap is always between two neighbours.
	// Use long so that e.g. INT_MAX - INT_MIN does not overflow.
	unsigned int shortest = static_cast<unsigned int>(
	    static_cast<long>(copy[1]) - static_cast<long>(copy[0]));
	for (std::vector<int>::size_type i = 2; i < copy.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(
		    static_cast<long>(copy[i]) - static_cast<long>(copy[i - 1]));
		if (diff < shortest)
		    shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_array.size() < 2)
        throw NoSpanException("Cannot find a span: need at least 2 numbers");

    int min = *std::min_element(_array.begin(), _array.end());
    int max = *std::max_element(_array.begin(), _array.end());
    return static_cast<unsigned int>(static_cast<long>(max) - static_cast<long>(min));
}

unsigned int Span::size() const
{
    return _array.size();
}

unsigned int Span::capacity() const
{
    return _N;
}
