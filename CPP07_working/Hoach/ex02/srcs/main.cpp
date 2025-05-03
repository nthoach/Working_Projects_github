#include <iostream>
#include "Array.hpp"

int main() {

    std::cout << "\n------------------    ex02   -------------------"<< std::endl;
    try {
        // Test default constructor
        std::cout << "Testing De"<< std::endl;
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test constructor with size
        Array<int> intArray(5);
        std::cout << "intArray size: " << intArray.size() << std::endl;

        // Initialize elements
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
        }

        // Print elements
        std::cout << "intArray elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copiedArray(intArray);
        std::cout << "copiedArray elements: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // Modify copiedArray and ensure intArray is unaffected
        copiedArray[0] = 999;
        std::cout << "After modifying copiedArray[0]: " << copiedArray[0] << std::endl;
        std::cout << "intArray[0]: " << intArray[0] << std::endl;

        // Test out-of-bounds access
        std::cout << "Accessing out-of-bounds index: ";
        std::cout << intArray[10] << std::endl; // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "------------------  end of ex02   -------------------\n"<< std::endl;
    return 0;
}
