#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {

    std::cout << "\n------------------    ex01  -------------------"<< std::endl;

    try {
        // Example from the exercise
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Test with a range of numbers
        Span largeSpan(10000);
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(i);
        }
        largeSpan.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span in largeSpan: " << largeSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "------------------    ex01  -------------------"<< std::endl;

    return 0;
}