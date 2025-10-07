#include "Harl.hpp"

Harl::Harl() {}

Harl::Harl(const Harl& other) { (void)other; }

Harl& Harl::operator=(const Harl& other)
{
	(void)other;
	return *this;
}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n\n";
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain( std::string level )
{
	static const Entry states[] =
	{
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == states[i].name)
		{
			(this->*states[i].f)();
			return ;
		}
	}
	std::cout<< "Harl is confused and doesnt know what to say\n";
}
