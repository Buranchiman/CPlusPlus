#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>

class NoMatchFound : public std::runtime_error
{
		public:
			explicit NoMatchFound(const std::string& msg);
};

template <typename Container>
typename Container::const_iterator	easyfind(Container &c, int target);

#include "easyfind.tpp"

#endif
