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

static bool parseChar(const std::string& input, char& out)
{
	std::istringstream ss(input);
	if (!(ss >> out)) return false;
	ss >> std::ws;
	return ss.eof();
}

static bool parseInt(const std::string& input, int& out)
{
	std::istringstream ss(input);
	if (!(ss >> out)) return false;
	ss >> std::ws;
	return ss.eof();
}

static bool parseFloat(const std::string& input, float& out)
{
	std::istringstream ss(input);
	if (!(ss >> out)) return false;
	ss >> std::ws;
	return ss.eof();
}

static bool parseDouble(const std::string& input, double& out)
{
	std::istringstream ss(input);
	if (!(ss >> out)) return false;
	ss >> std::ws;
	return ss.eof();
}

static std::string toStringInt(int v)
{
	std::ostringstream oss;
	oss << v;
	return oss.str();
}

static std::string toStringFloat(float v)
{
	std::ostringstream oss;
	oss << v;
	return oss.str();
}

static std::string toStringDouble(double v)
{
	std::ostringstream oss;
	oss << v;
	return oss.str();
}

void	ScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	dd;
	bool okC = parseChar(input, c);
	bool okI = parseInt(input, i);
	bool okF = parseFloat(input, f);
	bool okD = parseDouble(input, dd);

	std::cout << "char: "   << (okC ? std::string(1, c) : "impossible") << "\n";
	std::cout << "int: "    << (okI ? toStringInt(i)     : "impossible") << "\n";
	std::cout << "float: "  << (okF ? toStringFloat(f)   : "impossible") << "\n";
	std::cout << "double: " << (okD ? toStringDouble(dd)  : "impossible") << "\n";
	// std::cout << "char: " << c << std::endl;
	// if ((std::stringstream(input) >> c))
	// 	std::cout << c << std::endl;
	// else
	// 	std::cout << c << std::endl;
	// if ((std::stringstream(input) >> i))
	// 	std::cout << "int: " << c << std::endl;
}
