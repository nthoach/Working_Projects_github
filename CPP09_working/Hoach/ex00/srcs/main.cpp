#include <iostream>
#include "BitcoinExchange.hpp"

int main() {
    BitcoinExchange exchange;

    // Example usage
    std::string date = "2023-10-01";
    double amount = 100.0;

    try {
        double value = exchange.getValue(date, amount);
        std::cout << "Value for " << amount << " BTC on " << date << " is: " << value << " USD" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
