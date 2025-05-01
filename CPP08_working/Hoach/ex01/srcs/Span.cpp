#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {}

// Destructor
Span::~Span() {}

// Add a single number to the Span
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Span is already full");
    }
    _numbers.push_back(number);
}

// Find the shortest span
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
    }
    return shortest;
}

// Find the longest span
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}