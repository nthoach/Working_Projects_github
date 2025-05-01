#include "Base.hpp"
#include <iostream>

// Function prototypes
Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    // Generate a random object
    Base* obj = generate();

    // Identify the type using a pointer
    std::cout << "Identifying using pointer: ";
    identify(obj);

    // Identify the type using a reference
    std::cout << "Identifying using reference: ";
    identify(*obj);

    // Clean up
    delete obj;

    return 0;
}