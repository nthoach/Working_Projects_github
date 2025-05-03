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
    static void convert(const std::string& str);

private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    ~ScalarConverter();

    // Helper methods
    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);    
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
};

#endif // SCALARCONVERTER_HPP