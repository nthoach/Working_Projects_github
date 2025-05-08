#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
    _SpellBook.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell != NULL)
    {
        std::map<str, ASpell *>::iterator it = _SpellBook.find(spell->getName());

        if (it == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(const str &spellName)
{
    std::map<str, ASpell *>::iterator it = _SpellBook.find(spellName);

    if (it != _SpellBook.end())
    {
        delete it->second;
        _SpellBook.erase(spellName);
    }
}

ASpell *SpellBook::createSpell(const str &spellName)
{
    std::map<str, ASpell *>::iterator it = _SpellBook.find(spellName);

    if (it != _SpellBook.end())
        return (it->second->clone());
    return NULL;
}
