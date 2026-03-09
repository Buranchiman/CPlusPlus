#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : std::out_of_range(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : std::out_of_range(msg) {}

AForm::FormNotSignedException::FormNotSignedException(const std::string& msg) : std::runtime_error(msg) {}

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(75), _execGrade(75), _target("home") {}

AForm::AForm(const std::string name, bool isSigned, int signGrade, int execGrade, std::string target) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade), _target(target)
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

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade), _target(other._target) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
	{
		_isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	}
	else
		throw GradeTooLowException(bureaucrat.getName() + " couldnt sign " + _name + " because their grade is too low");
}

const std::string	AForm::getName() const { return(_name); }
bool	AForm::getSigned() const { return(_isSigned) ;}
int	AForm::getSignGrade() const { return(_signGrade) ;}
int	AForm::getExecGrade() const { return(_execGrade) ;}
std::string	AForm::getTarget() const { return(_target) ;}

std::ostream& operator<<(std::ostream &stream, const AForm& AForm)
{
	stream << AForm.getName() << ", AForm grade " << AForm.getSignGrade() << ", exec grade " << AForm.getExecGrade()  << (AForm.getSigned() == false ? " isnt signed" : "is signed") << std::endl;
	return (stream);
}

void	AForm::verifyAndRun(Bureaucrat const & executor) const
{
	if (_execGrade < executor.getGrade())
		throw AForm::GradeTooLowException(executor.getName() + " couldnt execute " + _name + " because their grade is too low");
	else if (!_isSigned)
		throw AForm::FormNotSignedException(executor.getName() + " couldnt execute " + _name + " because it isnt signed");
	std::cout << executor.getName() << " executed " << _name << std::endl;
	execute(executor);
}
