#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <exception>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class AForm;

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
	void signAForm(AForm& AForm);
	void executeForm(AForm const & form) const;
};

std::ostream& operator<< (std::ostream &stream, const Bureaucrat& bureaucrat);

#endif
