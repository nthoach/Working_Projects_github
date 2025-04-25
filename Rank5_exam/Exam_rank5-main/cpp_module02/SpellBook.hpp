#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"

using std::cout;
typedef std::string str;
typedef std::vector<ASpell *>::iterator spell_It;

class SpellBook {
    std::vector<ASpell *> spellBook;

    SpellBook(SpellBook const &copy);
    SpellBook &operator=(SpellBook const &copy);
public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *newSpell);
    void forgetSpell(str const &whichSpell);
    ASpell* createSpell(str const &whichSpell);
};

#endif
