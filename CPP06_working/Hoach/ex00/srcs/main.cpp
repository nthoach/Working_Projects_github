#include "ScalarConverter.hpp"

int main(int agc, char **agv) 
{
    std::cout << "\n ------------------Testing ex00 --------------------- \n" << std::endl;
    if (agc == 2)
    {
        ScalarConverter::convert(agv[1]);
    }
    ScalarConverter::convert("42");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("'a'");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("123.456");
    std::cout << "\n ------------------Done ex00 --------------------- \n" << std::endl;
    return 0;
}