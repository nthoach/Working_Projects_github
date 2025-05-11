#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
    spell_it it = _book.begin();
    while (it != _book.end())
    {
        delete it->second;
        it++;
    }
    _book.clear();
}

//
void SpellBook::learnSpell(ASpell* spell)
{
    if (spell)
    {
        forgetSpell(spell->getName());
        _book[spell->getName()]= spell->clone();
    }

}
void SpellBook::forgetSpell(std::string const& spellname)
{
    spell_it it = _book.find(spellname);
    if (it != _book.end())
    {
        delete it->second;
        _book.erase(it);
    }    
}

ASpell * SpellBook::createSpell(std::string const& spellname)
{
    spell_it it = _book.find(spellname);
    if (it != _book.end())
        return(it->second->clone());
    return (NULL);
}
