#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib> // For std::strtod, std::strtol
#include <sstream>

// Helper function to replace std::to_string in C++98
template <typename T>
std::string to_string(T value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
};

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