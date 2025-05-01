#include <iostream>
#include "Iter.hpp"

// Example function to print an element
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Example function to increment an element
template <typename T>
void incrementElement(T& element) {
    ++element;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intArraySize, incrementElement<int>);

    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    // Test with an array of strings
    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    std::size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original strArray: ";
    iter(strArray, strArraySize, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
