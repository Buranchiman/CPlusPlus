#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

// std::stack is a "container adaptor": it wraps another container
// (std::deque by default) and only exposes push/pop/top/size/empty.
// That wrapped container is stored in a PROTECTED member called `c`,
// so a derived class can reach it and expose its iterators.
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		// Borrow the iterator types of the underlying container
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
