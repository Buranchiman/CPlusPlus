#include "Harl.hpp"

int	main(int arc, char **arv)
{
	if (arc != 2)
	{
		std::cout << "Invalid number of parameters\n";
		return (0);
	}
	Harl	dummy;
	dummy.complain(arv[1]);
}
