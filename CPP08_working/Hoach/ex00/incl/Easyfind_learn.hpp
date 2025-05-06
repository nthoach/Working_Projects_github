#ifndef EASYFIND_LEARN_HPP
# define EASYFIND_LEARN_HPP

# include <algorithm> // find()
# include <iterator> // ::iterator
# include <exception> // std::runtime_error

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
};

#endif 