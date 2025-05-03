#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string& str)
{
    // 'C'
    return str.size() == 3 && str[0] == '\'' && str[2] == '\'';
    // Case: C (single printable char, not a digit)
    // if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
    // return true;
}

bool ScalarConverter::isInt(const std::string& str) {
    char* end;
    std::strtol(str.c_str(), &end, 10);
    return *end == '\0';
}

bool ScalarConverter::isFloat(const std::string& str) {
    return str.back() == 'f' && str.find('.') != std::string::npos;
}

bool ScalarConverter::isDouble(const std::string& str) {
    return str.find('.') != std::string::npos && str.back() != 'f';
}

void ScalarConverter::convert(const std::string& str) {
    try {
        // Handle char str
        if (isChar(str)) {
            std::cout << "input is a char" << std::endl;
            char c = str[1]; // Extract the character
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
            return;
        }

        // Handle int str
        if (isInt(str)) {
            std::cout << "input is an integer" << std::endl;
            long intValue = std::strtol(str.c_str(), nullptr, 10);
            if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max()) {
                throw std::out_of_range("int out of range");
            }
            int i = static_cast<int>(intValue);
            std::cout << "char: " << (i >= 32 && i <= 126 ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
            return;
        }

        // Handle float str
        if (isFloat(str)) {
            std::cout << "input is a float" << std::endl;
            float f = std::strtof(str.c_str(), nullptr);
            if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max()) {
                throw std::out_of_range("Float out of range");
            }
            std::cout << "char: " << (f >= 32 && f <= 126 ? "'" + std::string(1, static_cast<char>(f)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() ? std::to_string(static_cast<int>(f)) : "impossible") << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            return;
        }

        // Handle double str
        if (isDouble(str)) {
            std::cout << "input is a double" << std::endl;
            double d = std::strtod(str.c_str(), nullptr);
            if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max()) {
                throw std::out_of_range("double out of range");
            }
            std::cout << "char: " << (d >= 32 && d <= 126 ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() ? std::to_string(static_cast<int>(d)) : "impossible") << std::endl;
            std::cout << "float: " << (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max() ? std::to_string(static_cast<float>(d)) + "f" : "impossible") << std::endl;
           // std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        // Handle special cases (nan, inf, etc.)
        if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff") {
            std::cout << "input is a special number" << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << str << std::endl;
            std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
            return;
        }

        throw std::invalid_argument("Invalid str");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
