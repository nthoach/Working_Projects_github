#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

using std::cout;
typedef str str;

class Fireball : public ASpell{

    Fireball(Fireball const &copy);
    Fireball &operator=(Fireball const &copy);
public:
    Fireball();
    ~Fireball();

    ASpell *clone();
};

#endif