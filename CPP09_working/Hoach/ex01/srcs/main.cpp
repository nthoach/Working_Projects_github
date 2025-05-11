#include "RPN.hpp"
#include <iostream>


int main(int argc, char **argv)
{
    std::cout << "\n------------------    ex01   -------------------"<< std::endl;

    if (argc != 2)
    {
        std::cerr << "Error\n";
        return 1;
    }

    RPN calculator;

    try
    {
        int result = calculator.evaluate(argv[1]);
        std::cout << argv[1] << " = " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "------------------ end of ex01 -------------------\n"<< std::endl;
    return 0;
}
