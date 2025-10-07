#include "Harl.hpp"

void actual_complaint(int num)
{
	Harl dummy;
	switch (num)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]\n";
			dummy.complain("DEBUG");
			break;
		}
		case 1:
		{
			std::cout << "[ INFO ]\n";
			dummy.complain("INFO");
			break;
		}
		case 2:
		{
			std::cout << "[ WARNING ]\n";
			dummy.complain("WARNING");
			break;
		}
		case 3:
		{
			std::cout << "[ ERROR ]\n";
			dummy.complain("ERROR");
			break;
		}
	}
}

int	main(int arc, char **arv)
{
	if (arc != 2)
	{
		std::cout << "Invalid number of parameters\n";
		return (0);
	}
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int num = -1;
	for (int i = 0; i < 4; i ++)
	{
		if (arv[1] == levels[i])
			num = i;
	}
	if (num != -1)
	{
		while (num < 4)
		{
			actual_complaint(num);
			num++;
		}
	}
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (0);
	}
	actual_complaint(num);
	return (0);
}
