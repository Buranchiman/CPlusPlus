#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

void	ScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	dd;
	char	*end;

	if (input.length() == 1 && ( '9' < *(input.c_str()) || *(input.c_str()) < '0'))
	{
		c = *(input.c_str());
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		dd = static_cast<double>(c);
	}
	else
	{
		dd = strtod(input.c_str(), &end);
		if (*end != '\0' && (*end ==  'f' && *(end + 1) != '\0'))
		{
			std::cerr << "Invalid input not convertible" << std::endl;
			return ;
		}
		if ( std::isnan(dd) || dd < 0 || dd > 127)
			c = 1;
		else if ( dd < 32 || dd > 126)
			c = 0;
		else
			c = static_cast<char>(dd);
		i = static_cast<int>(dd);
		f = static_cast<float>(dd);
	}
	std::cout << "char: ";
	if (c < 32)
		std::cout << (c == 0 ? "Non displayable" : "impossible") << std::endl;
	else
		std:: cout << c << std::endl;
	std::cout << "int: ";
	if (std::isnan(dd) || dd < std::numeric_limits<int>::min() || dd > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << dd << std::endl;
}
