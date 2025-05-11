#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _db;

        // helpers
        void loadDatabase(const std::string& dbFile);
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr, float& value) const;
        float getRateForDate(const std::string& date) const;
        //
        BitcoinExchange();

    public:
        BitcoinExchange(const std::string& dbFile);
        BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void evaluateFile(const std::string& inputFile) const;
};

#endif // BITCOINEXCHANGE_HPP
