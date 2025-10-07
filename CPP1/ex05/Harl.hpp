#ifndef Harl_HPP
# define Harl_HPP

# include <iostream>
#include <map>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	Harl(const Harl& other);
	Harl& operator=(const Harl& other);
	~Harl();

	void complain( std::string level);
};

struct Entry {
	const char* name;
	void (Harl::*f)();
};

#endif
