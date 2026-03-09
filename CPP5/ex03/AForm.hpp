#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	int					_signGrade;
	int					_execGrade;
	std::string			_target;
protected:
	virtual void execute(Bureaucrat const & executor) const = 0;
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
	class FormNotSignedException : public std::runtime_error
	{
		public:
			explicit FormNotSignedException(const std::string& msg);
	};
	AForm();
	AForm(const std::string name, bool isSigned, int signGrade, int execGrade, std::string target);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	void				beSigned(Bureaucrat& bureaucrat);
	const std::string	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	std::string			getTarget() const ;
	void				verifyAndRun(Bureaucrat const & executor) const;
};

std::ostream& operator<< (std::ostream &stream, const AForm& AForm);

#endif
