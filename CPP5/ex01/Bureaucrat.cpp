#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Average Joe"), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1 || grade > 150)
		throw std::invalid_argument("Unvalid grade for bureaucrat");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :  _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::promote()
{
	if (_grade == 1)
		throw std::out_of_range("Cannot promote bureaucrat is already highest rank");
	_grade--;
}

void	Bureaucrat::demote()
{
	if (_grade == 150)
		throw std::out_of_range("Cannot demote bureaucrat is already lowest rank");
	_grade++;
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (stream);
}

void	Bureaucrat::signForm(Form form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException &excep)
	{
		std::cerr << excep.what() << std::endl;
	}
}
