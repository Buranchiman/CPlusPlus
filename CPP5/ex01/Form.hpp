#ifndef Form_HPP
#define Form_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	int					_signGrade;
	int					_execGrade;
public:
	class GradeTooHighException : std::out_of_range
	{
		explicit GradeTooHighException(const std::string& msg);
	};
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();


};

#endif /* Form_HPP */
