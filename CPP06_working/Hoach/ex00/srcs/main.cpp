#include "ScalarConverter.hpp"

int main(int agc, char **agv) 
{
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

    return 0;
}