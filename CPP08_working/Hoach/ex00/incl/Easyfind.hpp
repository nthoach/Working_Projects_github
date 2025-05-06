#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <iterator>  // For iterators
#include <exception> // For std::exception

// Function template for easyfind
template <typename T>

typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

#endif // EASYFIND_HPP
