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

	// Fill the Span with a range of iterators [begin, end).
	// Templates must be defined in the header so the compiler
	// can instantiate them for any iterator type.
	template <typename InputIt>
	void addRange(InputIt begin, InputIt end)
	{
	    typename std::iterator_traits<InputIt>::difference_type count
	        = std::distance(begin, end);

		    if (count < 0 || static_cast<unsigned long>(count) > _N - _array.size())
		        throw SpanFullException("Cannot add range: not enough space left in Span");
		    _array.insert(_array.end(), begin, end);
		}
};

#endif /* SPAN_HPP */
