#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
    T* _data;              // Pointer to the array data
    unsigned int _size;    // Size of the array

public:
    // Default constructor: Creates an empty array
    Array() : _data(NULL), _size(0) {}

    // Constructor with size parameter: Creates an array of n elements
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : _data(NULL), _size(0) {*this = other; }

    // Destructor
    ~Array() { delete[] _data;}

    // Assignment operator
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data; // Free existing memory
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
            {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Subscript operator for accessing elements
    T& operator[](unsigned int index)
    {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Subscript operator for accessing elements (const version)
    const T& operator[](unsigned int index) const
    {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Size function: Returns the number of elements in the array
    unsigned int size() const
    {
        return _size;
    }
};



#endif // ARRAY_HPP