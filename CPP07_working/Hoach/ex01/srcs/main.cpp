#include <iostream>
#include "Iter.hpp"
#include "ComplexNumber.hpp"

// Example function to print an element
template <typename T>

void printElement(const T& element)
{
    std::cout << element << " ";
}

// Example function to increment an element
template <typename T>
void incrementElement(T& element)
{
    ++element;
}

int main()
{
    std::cout << "\n------------------    ex01   -------------------"<< std::endl;
    std::cout << "Test with an array of integers:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intArraySize, incrementElement<int>);

    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    std::cout << "\nTest with an array of strings:" << std::endl;
    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    std::size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original strArray: ";
    iter(strArray, strArraySize, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "\nTest with an array of complex numbers" << std::endl;
    ComplexNumber ComplexArray[] = {ComplexNumber(1.0012, 2), ComplexNumber(1., 0.), ComplexNumber(3.0, 4.0)};
    std::size_t ComplexArraySize = sizeof(ComplexArray) / sizeof(ComplexArray[0]);

    std::cout << "Original Complex Array: ";
    iter(ComplexArray, ComplexArraySize, printElement<ComplexNumber>);
    std::cout << std::endl;

    std::cout << "------------------  end of ex01   -------------------\n\n"<< std::endl;
    return 0;
}
