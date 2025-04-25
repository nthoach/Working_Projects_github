#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

using std::cout;
typedef std::string str;

class Fwoosh : public ASpell{

    Fwoosh(Fwoosh const &copy);
    Fwoosh &operator=(Fwoosh const &copy);
public:
    Fwoosh();
    ~Fwoosh();

    ASpell *clone();
};

#endif