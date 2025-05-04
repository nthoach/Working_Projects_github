#include "ScalarConverter.hpp"

int main(int agc, char **agv) 
{
    std::cout << "\n ------------------Testing ex00 --------------------- \n" << std::endl;
    if (agc == 2)
    {
        std::cout << "\ninput = 0 ------" << std::endl;
        ScalarConverter::convert(agv[1]);
    }
    std::cout << "\ninput = 42 -----" << std::endl;
    ScalarConverter::convert("42");
    std::cout << "\ninput = 4.2f -----" << std::endl;
    ScalarConverter::convert("4.2f");
    std::cout << "\ninput = nan -----" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "\ninput = 'a' -----" << std::endl;
    ScalarConverter::convert("'a'");
    std::cout << "\ninput = -inff -----" << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << "\ninput = 123.456 -----" << std::endl;
    ScalarConverter::convert("123.456");
    std::cout << "\n ------------------Done ex00 --------------------- \n" << std::endl;
    return 0;
}