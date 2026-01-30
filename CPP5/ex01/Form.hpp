#ifndef Form_HPP
#define Form_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	int					_signGrade;
	int					_execGrade;
public:
	class GradeTooHighException : public std::out_of_range
	{
		public:
			explicit GradeTooHighException(const std::string& msg);
	};
	class GradeTooLowException : public std::out_of_range
	{
		public:
			explicit GradeTooLowException(const std::string& msg);
	};
	Form();
	Form(const std::string name, bool isSigned, int signGrade, int execGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	void	beSigned(Bureaucrat bureaucrat);
};

#endif
