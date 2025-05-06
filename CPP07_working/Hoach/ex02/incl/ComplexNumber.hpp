#include <iostream>

class ComplexNumber
{
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0, double i = 0);

    const double& getReal() const;
    const double& getImag() const;

    // Overload comparison operators
    bool operator<(const ComplexNumber& other) const;

    bool operator>(const ComplexNumber& other) const;
    // Overload assignment operator (default is sufficient here)
    ComplexNumber& operator=(const ComplexNumber& other);

};    
// Friend function to print the complex number
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);