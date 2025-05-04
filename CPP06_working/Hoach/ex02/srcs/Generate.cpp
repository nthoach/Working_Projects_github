#include "Base.hpp"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

Base* generate() {
    std::srand(std::time(NULL)); // Seed the random number generator
    int random = std::rand() % 4;   // Generate a random number between 0 and 2

    if (random == 0)
    {
        return new A();
    }
    else if (random == 1)
    {
        return new B();
    }
    else if (random == 2)
    {
        return new C();
    }
    else
    {
        return new Base();
    }
}