#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : std::out_of_range(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : std::out_of_range(msg) {}

Form::Form() : _name("default"), _isSigned(false), _signGrade(75), _execGrade(75) {}

Form::Form(const std::string name, bool isSigned, int signGrade, int execGrade) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException("Invalid signGrade");
	else if (signGrade > 150)
		throw GradeTooLowException("Invalid signGrade");
	else if (execGrade < 1)
		throw GradeTooHighException("Invalid execGrade");
	else if (execGrade > 150)
		throw GradeTooLowException("Invalid execGrade");
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		this->_signGrade = other._signGrade;
		this->_execGrade = other._execGrade;
	}
	return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
	{
		_isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	}
	else
		throw GradeTooLowException(bureaucrat.getName() + " couldnt sign " + _name + " because their grade is too low");
}

const std::string	Form::getName() const { return(_name); }
bool	Form::getSigned() const { return(_isSigned) ;}
int	Form::getSignGrade() const { return(_signGrade) ;}
int	Form::getExecGrade() const { return(_execGrade) ;}

std::ostream& operator<<(std::ostream &stream, const Form& form)
{
	stream << form.getName() << ", form grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade()  << (form.getSigned() == false ? " isnt signed" : "is signed") << std::endl;
	return (stream);
}
