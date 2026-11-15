#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool loadDatabase(const std::string& filename);
	bool processInput(const std::string& filename) const;

private:
	std::map<std::string, double> _data;

	bool getRate(const std::string& date, double& rate) const;

	static std::string trim(const std::string& str);
	static bool isValidDate(const std::string& date);
	static bool parseNumber(const std::string& str, double& out);
};

#endif
