#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint> // For uintptr_t
#include "Data.hpp"

class Serializer {
public:
    // Converts a pointer to an unsigned integer
    static uintptr_t serialize(Data* ptr);

    // Converts an unsigned integer back to a pointer
    static Data* deserialize(uintptr_t raw);

private:
    // Prevent instantiation of the class
    Serializer();
    ~Serializer();
};

#endif // SERIALIZER_HPP