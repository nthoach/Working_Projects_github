#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // For std::size_t

// Function template for iter with nonconst&
template <typename T, typename F>

void iter(T* array, std::size_t length, F func)
{
    if (array == NULL)
    {
        std::cout << "No array" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

// Function template for iter with const&
template <typename T, typename F>

void iter(const T* array, std::size_t length, F func)
{clear
    if (array == NULL)
    {
        std::cout << "No array" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}


#endif // ITER_HPP