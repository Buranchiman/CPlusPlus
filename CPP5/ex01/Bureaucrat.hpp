#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <exception>
#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string	getName() const;
	int	getGrade() const;
	void	promote();
	void	demote();
};

std::ostream& operator<< (std::ostream &stream, const Bureaucrat& bureaucrat);

#endif
