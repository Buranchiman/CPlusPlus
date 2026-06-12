#include "easyfind.hpp"
#include <algorithm>

NoMatchFound::NoMatchFound(const std::string& msg) : std::runtime_error(msg) {}

template <typename Container>
typename Container::const_iterator	easyfind(Container &c, int target)
{
	typename Container::const_iterator it = c.begin();
	typename Container::const_iterator ite = c.end();
	typename Container::const_iterator tmp;

	tmp = std::find(it, ite, target);
	if (tmp == ite)
		throw NoMatchFound("No match found in this container !");
	else
		return (tmp);
}
