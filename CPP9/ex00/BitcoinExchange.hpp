#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private :
    std::map<std::string, float> _data;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void fillData(const std::string input[]);
};

#endif /* BitcoinExchange_HPP */