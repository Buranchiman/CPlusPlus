#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

// Removes spaces, tabs and '\r' (Windows line endings) at both ends.
std::string BitcoinExchange::trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\r");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t\r");
	return str.substr(start, end - start + 1);
}

// Checks "YYYY-MM-DD": shape first, then that the day exists in that month.
bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (month == 2 && leap)
		return day <= 29;
	return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::parseNumber(const std::string& str, double& out)
{
	size_t i = 0;
	bool hasDigit = false;
	bool hasDot = false;

	if (i < str.length() && (str[i] == '-' || str[i] == '+'))
		i++;
	for (; i < str.length(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])))
			hasDigit = true;
		else if (str[i] == '.' && !hasDot)
			hasDot = true;
		else
			return false;
	}
	if (!hasDigit)
		return false;
	out = std::strtod(str.c_str(), NULL);
	return true;
}

// Exact date if present, otherwise the closest LOWER date.
bool BitcoinExchange::getRate(const std::string& date, double& rate) const
{
	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
	{
		rate = it->second;
		return true;
	}
	if (it == _data.begin())
		return false;   // date is earlier than everything in the database
	--it;
	rate = it->second;
	return true;
}

/* ------------------------------------------------------------------ */
/*  Database (data.csv)                                               */
/* ------------------------------------------------------------------ */

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open database." << std::endl;
		return false;
	}

	std::string line;
	if (!std::getline(file, line) || trim(line) != "date,exchange_rate")
	{
		std::cout << "Error: invalid database header." << std::endl;
		return false;
	}

	int lineNumber = 1;
	while (std::getline(file, line))
	{
		lineNumber++;
		line = trim(line);
		if (line.empty())
			continue;

		size_t comma = line.find(',');
		double rate = 0;
		if (comma == std::string::npos
			|| !isValidDate(line.substr(0, comma))
			|| !parseNumber(line.substr(comma + 1), rate)
			|| rate < 0)
		{
			std::cout << "Error: invalid database line " << lineNumber << "." << std::endl;
			return false;
		}
		_data[line.substr(0, comma)] = rate;
	}

	if (_data.empty())
	{
		std::cout << "Error: database is empty." << std::endl;
		return false;
	}
	return true;
}

/* ------------------------------------------------------------------ */
/*  Input file (argv[1])                                              */
/* ------------------------------------------------------------------ */

bool BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return false;
	}

	std::cout.precision(10);   // avoid "6e+07" for big results

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line))
	{
		std::string clean = trim(line);

		if (firstLine)
		{
			firstLine = false;
			if (clean == "date | value")
				continue;
		}
		if (clean.empty())
			continue;

		size_t sep = clean.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << clean << std::endl;
			continue;
		}

		std::string date = trim(clean.substr(0, sep));
		std::string valueStr = trim(clean.substr(sep + 1));
		double value = 0;
		double rate = 0;

	if (!isValidDate(date) || !parseNumber(valueStr, value))
		std::cout << "Error: bad input => " << clean << std::endl;
	else if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else if (!getRate(date, rate))
		std::cout << "Error: no data for date => " << date << std::endl;
	else
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	return true;
}
