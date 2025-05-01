#include "ScalarConverter.hpp"

bool ScalarConverter::isCharLiteral(const std::string& literal)
{
    return literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isIntLiteral(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';
}

bool ScalarConverter::isFloatLiteral(const std::string& literal) {
    return literal.back() == 'f' && literal.find('.') != std::string::npos;
}

bool ScalarConverter::isDoubleLiteral(const std::string& literal) {
    return literal.find('.') != std::string::npos && literal.back() != 'f';
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        // Handle char literal
        if (isCharLiteral(literal)) {
            char c = literal[1]; // Extract the character
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
            return;
        }

        // Handle int literal
        if (isIntLiteral(literal)) {
            long intValue = std::strtol(literal.c_str(), nullptr, 10);
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

        // Handle float literal
        if (isFloatLiteral(literal)) {
            float f = std::strtof(literal.c_str(), nullptr);
            std::cout << "char: " << (f >= 32 && f <= 126 ? "'" + std::string(1, static_cast<char>(f)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() ? std::to_string(static_cast<int>(f)) : "impossible") << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            return;
        }

        // Handle double literal
        if (isDoubleLiteral(literal)) {
            double d = std::strtod(literal.c_str(), nullptr);
            std::cout << "char: " << (d >= 32 && d <= 126 ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() ? std::to_string(static_cast<int>(d)) : "impossible") << std::endl;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        // Handle special cases (nan, inf, etc.)
        if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
            return;
        }

        throw std::invalid_argument("Invalid literal");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
