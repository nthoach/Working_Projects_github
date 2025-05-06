
#include <iostream>
#include "Whatever.hpp"
#include "ComplexNumber.hpp"

int main()
{
    std::cout << "\n\n------------------    ex00   -------------------"<< std::endl;
    std::cout << "Test with integers:" << std::endl;
    
    int a = 2;
    int b = 3;

    // Test swap with integers
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

    // Test min and max with integers
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    // Test swap with strings
    std::cout << "\nTest with strings:" << std::endl;

    std::string c = "String test 1";
    std::string d = "String test 2";

    std::cout << "Before Swap c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After Swap c = " << c << ", d = " << d << std::endl;

    // Test min and max with strings
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    // Test with complex numbers
    std::cout << "\nTest with complex numbers:" << std::endl;
    ComplexNumber e(1, 2);
    ComplexNumber f(-3, 4);

    std::cout << "Before Swap e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After Swap e = " << e << ", f = " << f << std::endl;
    // Test min and max with complex numbers
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    std::cout << "------------------end of ex00-------------------\n"<< std::endl;
    return 0;
}