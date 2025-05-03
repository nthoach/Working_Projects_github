#include <iostream>
#include "ComplexNumber.hpp"


ComplexNumber::ComplexNumber(double r, double i) : real(r), imag(i) {}

// Overload comparison operators
bool ComplexNumber::operator<(const ComplexNumber& other) const
{
    return (real * real + imag * imag) < (other.real * other.real + other.imag * other.imag);
}

bool ComplexNumber::operator>(const ComplexNumber& other) const 
{
    return (real * real + imag * imag) > (other.real * other.real + other.imag * other.imag);
}

// Overload assignment operator (default is sufficient here)
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other)
{
    if (this != &other)
    {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

// Friend function to print the complex number
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c)
{
        os << c.real << " + " << c.imag << "i";
        return os;
}
