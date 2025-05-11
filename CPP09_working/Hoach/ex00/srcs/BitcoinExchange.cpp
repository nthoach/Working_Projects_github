#include "BitcoinExchange.hpp"
#include <fstream> //for std::ifstream --> .open(), 
#include <iostream>
#include <sstream> // for std::istringstream
#include <cstdlib> // for sscanf() in C

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

    if (line != "date,exchange_rate")
        std::cout << "check the header of \"date,exchange_rate\"" << std::endl;

    while (std::getline(file, line)) // start reading linebyline
    {
        std::istringstream ss(line); //treat string as as stream to parse
        std::string date, rateStr; // cut down line to date and rate
        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr)) //neglect line without date or rate
            continue;
        float rate = std::atof(rateStr.c_str());  // C++98-friendly
        _db[date] = rate; //automaticaly sorted by date = key in increasing order
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
    std::istringstream iss(valueStr);
    iss >> value; //read a float to value from a stringstream ss
    if (iss.fail() || !iss.eof())
        return std::cout << "Error: bad value input => " << valueStr << std::endl, false;
    if (value < 0.0f)
        return std::cout << "Error: not a positve number.\n", false;
    if (value > 1000.0f)
        return std::cout << "Error: too large a mumber\n", false;

    return true;    
}

float BitcoinExchange::getRateForDate(const std::string& date) const
{
    // Worked with sorted order of _db;
    std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
    // found exactly match
    if (it != _db.end() && it->first == date)
        return it->second;
    // date is earlier to all data
    if (it == _db.begin())
    {
        std::cout << "date is earlier than the oldest database date\n";
        return  -1.0f;
    }    
    // data not found to previous date
    --it;
    return it->second;
}

void BitcoinExchange::evaluateFile(const std::string& inputFile) const
{
    std::ifstream file(inputFile.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << inputFile << std::endl;
        return;
    }
    // std::ifstream file; file.open(inputFile.c_str());
    // if (!file.is_open())
    // {
    //     std::cerr << "failed to open file" << inputFile << std::endl;
    //     return;
    // }

    std::string line; // to read line by line

    // unsigned int i = 0;

    std::getline(file, line); // skip header
    // std::cout << i << ": ";

    if (line != "date | value")
        std::cout << "check the header of \"date | value\"" << std::endl;

    while (std::getline(file, line))
    {
        // i++;
        // std::cout << i << ": ";
        std::istringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            // std::cerr << "Error => " << line << "\n";
            continue;
        }

        // Trim whitespace before and after
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        float value;
        
        if (!isValidDate(date))
            std::cout << "Error: bad input => " << date << std::endl;
        else if (isValidValue(valueStr, value))
        {
            float rate = getRateForDate(date);
            if (rate > 0)
                std::cout << date << " => " << value << " = " << value * rate << "\n";
        }
    }
}
