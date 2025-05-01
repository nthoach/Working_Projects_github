#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    double getValue(const std::string &date, double amount) const;

private:
    std::map<std::string, double> exchangeRates; // Date to Bitcoin value mapping
    void loadExchangeRates();
};

#endif // BITCOINEXCHANGE_HPP