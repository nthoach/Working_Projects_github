#include <iostream>
#include "Whatever.hpp"

int main() {
    int a = 2;
    int b = 3;

    // Test swap with integers
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // Test min and max with integers
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    // Test swap with strings
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;

    // Test min and max with strings
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}