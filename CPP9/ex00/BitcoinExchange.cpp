#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    _data = other._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void fillData(const std::string input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::string key;
        key = input[i].substr(0 , input[i].find(',')); 
        input[i].find(',');
        input[i].
    }
}