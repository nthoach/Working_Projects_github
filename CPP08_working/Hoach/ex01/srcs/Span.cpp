#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {}

// Destructor
Span::~Span() {}

//
Span::Span(Span const& other) { *this = other;}

Span& Span::operator=(Span const& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}


// Add a single number to the Span
void Span::addNumbers(int number)
{
    if (_numbers.size() >= _maxSize)
    {
        throw std::runtime_error("Span is already full");
    }
    _numbers.push_back(number);
}

// Find the shortest span
int Span::shortestSpan() const
{
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

int Span::getNumber(unsigned int index) const
{
    if (index >= _numbers.size())
    {
        throw std::out_of_range("Index out of range");
    }
    return _numbers[index];
}

//
unsigned int Span::size() const {return _numbers.size();}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    for (unsigned int i = 0; i < span.size(); i++)
        os << span.getNumber(i) << " ";
    return os;
}