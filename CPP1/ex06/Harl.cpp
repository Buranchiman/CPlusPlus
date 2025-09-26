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
	std::map<std::string, void (Harl::*)()> functions;

	functions["debug"] = &Harl::debug;
	functions["info"] = &Harl::info;
	functions["warning"] = &Harl::warning;
	functions["error"] = &Harl::error;

	std::map<std::string, void (Harl::*)()>::iterator it = functions.find(level);
	Harl dummy;
	if (it != functions.end())
		(dummy.*(it->second))();
}
