#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp"

int main() {
    try {
        // Test with a vector
        // Test with a vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
                
        std::cout << "Searching for 3 in vector: ";
        std::vector<int>::iterator vecIt = easyfind(vec, 3);
        std::cout << "Found " << *vecIt << std::endl;

        std::cout << "Searching for 6 in vector: ";
        vecIt = easyfind(vec, 6); // This will throw an exception
        std::cout << "Found " << *vecIt << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test with a list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        std::cout << "Searching for 30 in list: ";
        std::list<int>::iterator lstIt = easyfind(lst, 30);
        std::cout << "Found " << *lstIt << std::endl;

        std::cout << "Searching for 60 in list: ";
        lstIt = easyfind(lst, 60); // This will throw an exception
        std::cout << "Found " << *lstIt << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}