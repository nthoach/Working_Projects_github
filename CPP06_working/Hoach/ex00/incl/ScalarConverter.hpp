#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib> // For std::strtod, std::strtol

class ScalarConverter {
public:
    // Static method to perform the conversion
    static void convert(const std::string& literal);

private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    ~ScalarConverter();

    // Helper methods
    static bool isCharLiteral(const std::string& literal);
    static bool isFloatLiteral(const std::string& literal);
    static bool isDoubleLiteral(const std::string& literal);
    static bool isIntLiteral(const std::string& literal);
};

#endif // SCALARCONVERTER_HPP