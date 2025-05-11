#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::loadDatabase(const std::string& dbFile)
{
    std::ifstream file(dbFile.c_str());  // C++98: use c_str()
    std::string line;

    if (!file)
    {
        std::cerr << "Error: could not open database file.\n";
        std::exit(1);
    }

    std::getline(file, line); // skip header
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, rateStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        float rate = std::atof(rateStr.c_str());  // C++98-friendly
        _db[date] = rate;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    std::istringstream iss(valueStr);
    iss >> value;
    if (iss.fail() || !iss.eof())
        return false;
    return (value >= 0.0f && value <= 1000.0f);
}

float BitcoinExchange::getRateForDate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    if (it != _db.end() && it->first == date)
        return it->second;
    if (it == _db.begin())
        return -1.0f;
    --it;
    return it->second;
}

void BitcoinExchange::evaluateFile(const std::string& inputFile) const
{
    std::ifstream file(inputFile.c_str());
    std::string line;

    if (!file) {
        std::cerr << "Error: could not open file.\n";
        return;
    }

    std::getline(file, line); // skip header
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        float value;
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << "\n";
        } else if (!isValidValue(valueStr, value)) {
            if (valueStr.empty() || value < 0)
                std::cerr << "Error: not a positive number.\n";
            else
                std::cerr << "Error: too large a number.\n";
        } else {
            float rate = getRateForDate(date);
            if (rate < 0)
                std::cerr << "Error: no rate available for date " << date << "\n";
            else
                std::cout << date << " => " << value << " = " << value * rate << "\n";
        }
    }
}
