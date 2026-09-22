#ifndef Span_HPP
#define Span_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span
{
    private:
        const unsigned int _N;
        std::vector<unsigned int> _array;
    public:
    class SpanFullException : public std::runtime_error
	{
		public:
			explicit SpanFullException(const std::string& msg);
	};
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

    void addNumber(const int number);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif /* Span_HPP */
