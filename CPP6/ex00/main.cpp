#include "ScalarConverter.hpp"

int	main(int arc, char**arv)
{
	if (arc != 2)
		return (std::cerr << "Wrong number of arguments" <<std::endl, 1);
	ScalarConverter::convert(arv[1]);
}
