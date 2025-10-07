#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void thinkAbout(std::string idea);
	void comesToMind();
};

#endif
