#include "functions.hpp"

Base * generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	int	random = std::rand();

	if (random % 3 == 0)
		return (new A);
	else if (random % 3 == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A";
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B";
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << "No matching type" << std::endl;
	}
}
