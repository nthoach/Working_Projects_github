#include <iostream>
#include "Array.hpp"
#include "ComplexNumber.hpp"

int main() {

    std::cout << "\n------------------    ex02   -------------------"<< std::endl;
    try
    {
        // Test default constructor
        Array<int> emptyArray;
        std::cout << "\nEmpty array size: " << emptyArray.size() << std::endl;

        // Test constructor with size
        Array<int> intArray(5);
        std::cout << "\nintArray size: " << intArray.size() << std::endl;
        // Initialize elements
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            intArray[i] = i * 10;
        }
        // Print elements
        std::cout << "intArray elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            std::cout << intArray[i] << " ";
        }
        // Test copy constructor
        Array<int> copiedArray(intArray);
        std::cout << "copiedArray elements: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i)
        {
            std::cout << copiedArray[i] << " ";
        }
         // Modify copiedArray and ensure intArray is unaffected
        copiedArray[0] = 999;
        std::cout << "\nAfter modifying copiedArray[0]: " << copiedArray[0] << std::endl;
        std::cout << "intArray[0]: " << intArray[0] << std::endl;
        // Test constructor with size of complex numbers

        Array<ComplexNumber> complexArray(10);
        std::cout << "\ncomplexArray size: " << complexArray.size() << std::endl;
        // Initialize elements
        for (unsigned int i = 0; i < complexArray.size(); ++i)
        {
            complexArray[i] = ComplexNumber(i, 2 * i);
        }
        // Print elements
            std::cout << "Complex number elements: ";
            for (unsigned int i = 0; i < complexArray.size(); ++i) {
                std::cout << complexArray[i] << " ";
            }
        std::cout << std::endl;
        // Test out-of-bounds access
        std::cout << "\nAccessing out-of-bounds index: ";
        std::cout << complexArray[11] << std::endl; // This will throw an exception
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "------------------  end of ex02   -------------------\n"<< std::endl;
    return 0;
}
