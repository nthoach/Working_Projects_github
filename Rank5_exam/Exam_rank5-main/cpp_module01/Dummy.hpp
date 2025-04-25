#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

using std::cout;
typedef std::string str;

class Dummy : public ATarget{

    Dummy(Dummy const &copy);
    Dummy &operator=(Dummy const &copy);
public:
    Dummy();
    ~Dummy();

    ATarget *clone();
};

#endif