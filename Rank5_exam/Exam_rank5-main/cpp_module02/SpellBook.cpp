#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {

    for (spell_It i = spellBook.begin(); i != spellBook.end(); i++) {
        delete (*i);
    }
    spellBook.clear();
}


////////////////////////////////////////////////////////////////


void SpellBook::learnSpell(ASpell *newSpell) {

    if (newSpell)
    {
        for (spell_It i = spellBook.begin(); i != spellBook.end(); i++) {
        if ((*i)->getName() == newSpell->getName()) 
            return;
        }
        spellBook.push_back(newSpell->clone());
    }
}

void SpellBook::forgetSpell(str const &whichSpell) {

     for (spell_It i = spellBook.begin(); i != spellBook.end(); i++) {
        if ((*i)->getName() == whichSpell) {
            delete (*i);
            spellBook.erase(i);
            return;
        }
    }
}

ASpell* SpellBook::createSpell(str const &whichSpell) {

    for (spell_It i = spellBook.begin(); i != spellBook.end(); i++) {
        if ((*i)->getName() == whichSpell) {
            return (*i);
        }
    }
    return NULL;
}
