#include "Harl.hpp"

void actual_complaint(int num)
{
	Harl dummy;
	switch (num)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]\n";
			dummy.complain("debug");
		}
		case 1:
		{
			std::cout << "[ INFO ]\n";
			dummy.complain("warning");
		}
		case 2:
		{
			std::cout << "[ WARNING ]\n";
			dummy.complain("warning");
		}
		case 3:
		{
			std::cout << "[ ERROR ]\n";
			dummy.complain("error");
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
	std::map<std::string, int>levels;
	levels["DEBUG"] = 0;
	levels["INFO"] = 1;
	levels["WARNING"] = 2;
	levels["ERROR"] = 3;
	std::map<std::string, int>::iterator it = levels.find(arv[1]);
	int num;
	if (it != levels.end())
		num = it->second;
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (0);
	}
	actual_complaint(num);
	return (0);
}
