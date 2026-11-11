#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iterator>

class Span
{
	private:
	    unsigned int        _N;
	    std::vector<int>    _array;

	public:
		class SpanFullException : public std::runtime_error
		{
		    public:
		        explicit SpanFullException(const std::string& msg);
		};

		class NoSpanException : public std::runtime_error
		{
		    public:
		        explicit NoSpanException(const std::string& msg);
		};

		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void            addNumber(const int number);
		unsigned int    shortestSpan() const;
		unsigned int    longestSpan() const;

		unsigned int    size() const;
		unsigned int    capacity() const;

		void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
};

#endif /* SPAN_HPP */
