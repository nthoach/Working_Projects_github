#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm> // For std::min_element, std::max_element, std::sort
#include <exception> // For std::exception
#include <iterator>  // For iterators
#include <iostream>  // For debugging (optional)

class Span {
private:
    unsigned int _maxSize;       // Maximum number of elements
    std::vector<int> _numbers;  // Container to store the numbers

public:
    // Constructor
    Span(unsigned int N);

    // Destructor
    ~Span();

    // Add a single number to the Span
    void addNumber(int number);

    // Add a range of numbers to the Span
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end)
    {
        if (std::distance(begin, end) + _numbers.size() > _maxSize)
        {
            throw std::runtime_error("Adding range exceeds Span capacity");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    // Find the shortest span
    int shortestSpan() const;

    // Find the longest span
    int longestSpan() const;

    // Get the current size of the Span (optional for debugging)
    unsigned int size() const { return _numbers.size(); }
};

#endif // SPAN_HPP