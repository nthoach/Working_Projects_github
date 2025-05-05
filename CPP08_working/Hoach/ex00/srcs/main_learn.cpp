#include <iostream>
#include <string>
#include <vector>
#include "../incl/Easyfind_learn.hpp"

# include <algorithm> // find()
# include <iterator> // ::iterator
# include <exception> // std::runtime_error

int main()
{
    std::cout << "\n ----------------- testing ex00 ------------------" << std::endl;
    try 
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(v, 10);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
 
    return (0);
}


