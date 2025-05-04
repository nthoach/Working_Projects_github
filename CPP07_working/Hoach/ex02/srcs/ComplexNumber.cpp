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

//getters
const double& ComplexNumber::getReal() const
{
    return (this->real);
}

const double& ComplexNumber::getImag() const
{
    return (this->imag);
}

//function to print the complex number
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c)
{
        os << c.getReal() << " + " << c.getImag() << "i";
        return os;
}
