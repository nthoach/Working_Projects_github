#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {
    loadExchangeRates();
}

void BitcoinExchange::loadExchangeRates() {
    std::ifstream file("exchange_rates.csv"); // Assume you have a CSV file with rates
    if (!file.is_open()) {
        throw std::runtime_error("Could not open exchange rates file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double rate;

        if (std::getline(ss, date, ',') && ss >> rate) {
            exchangeRates[date] = rate;
        }
    }
}

double BitcoinExchange::getValue(const std::string &date, double amount) const {
    std::map<std::string, double>::const_iterator  it = exchangeRates.find(date);
    if (it == exchangeRates.end()) {
        throw std::invalid_argument("Date not found in exchange rates.");
    }
    return it->second * amount;
}