#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		for (std::string::size_type j = 0; j < arg.length(); j++)
		{
			arg[j] = std::toupper(static_cast<unsigned char>(arg[j]));
		}
		std::cout << arg;
	}
	std::cout << std::endl;
	return 0;
}
