#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

using std::cout;
typedef str str;

class Polymorph : public ASpell{

    Polymorph(Polymorph const &copy);
    Polymorph &operator=(Polymorph const &copy);
public:
    Polymorph();
    ~Polymorph();

    ASpell *clone();
};

#endif