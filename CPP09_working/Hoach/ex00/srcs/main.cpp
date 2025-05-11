#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    std::cout << "\n------------------    ex00   -------------------"<< std::endl;

    if (argc != 2)
    {
        std::cerr << "Usage error ./btc input.txt \n";
        return 1;
    }

    const std::string inputFile = argv[1];
    const std::string dbFile = "data.csv"; // adjust if your DB file has a different name

    BitcoinExchange exchange(dbFile);
    exchange.evaluateFile(inputFile);

    std::cout << "------------------ end of ex00 -------------------\n"<< std::endl;
    return 0;
}
