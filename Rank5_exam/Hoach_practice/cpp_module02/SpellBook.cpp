
#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::map<str, ASpell *>::iterator it = _spells.begin();
    while (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
        it++;
    }
}


void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
    {
        std::map<str, ASpell *>::iterator it = _spells.find(spell->getName());
        if (it == _spells.end())
        {
            _spells[spell->getName()] = spell->clone();
        }
    }
}
void SpellBook::forgetSpell(str const &spellname)
{
    std::map<str, ASpell *>::iterator it = _spells.find(spellname);
    if (it != _spells.end())
    {
        delete it->second; //delete ASpell
        _spells.erase(it); //remove key value pair
    }
}

ASpell* SpellBook::createSpell(str const & spell)
{
    std::map<str, ASpell *>::iterator it = _spells.find(spell);
    if (it != _spells.end())
    {
        return it->second->clone();
    }
    else 
        return NULL;
}