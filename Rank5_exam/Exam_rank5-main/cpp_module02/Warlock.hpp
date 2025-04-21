#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "SpellBook.hpp"

using std::cout;
typedef std::string str;

class Warlock {
    str name;
    str title;
    SpellBook spellBook;

    Warlock(Warlock const &copy);
    Warlock &operator=(Warlock const &copy);
public:
    Warlock(str const &Name, str const &Title);
    ~Warlock();

    str const &getName() const;
    str const &getTitle() const;
    void setTitle(str const &Title);

    void introduce() const;
    void learnSpell(ASpell *newSpell);
    void forgetSpell(str const &whichSpell);
    void launchSpell(str const &whichSpell, ATarget &target);
};

#endif
