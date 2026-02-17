#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void convert(std::string input);
};

#endif /* ScalarConverter_HPP */
