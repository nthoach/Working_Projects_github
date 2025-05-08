#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {

    std::cout << "\n------------------    ex01  -------------------"<< std::endl;

    try
    {
        // Example from the exercise
        Span sp = Span(5);
        sp.addNumbers(6);
        sp.addNumbers(3);
        sp.addNumbers(17);
        sp.addNumbers(9);
        sp.addNumbers(11);

        std::cout << "Size of largeSpan: " << sp.size() << std::endl;
        std::cout << "Numbers in largeSpan: " << sp << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl << std::endl;

        // Test with a range of numbers
        Span largeSpan(20000);
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(i);
        }
        largeSpan.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Size of largeSpan: " << largeSpan.size() << std::endl;
        //std::cout << "Numbers in largeSpan: " << largeSpan << std::endl;
        std::cout << "Shortest span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span in largeSpan: " << largeSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "------------------    ex01  -------------------"<< std::endl;

    return 0;
}