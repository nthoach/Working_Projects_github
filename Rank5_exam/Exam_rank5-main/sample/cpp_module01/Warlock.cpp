#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const str &name, const str &title): _name(name), _title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
}
const str &Warlock::getName() const
{
    return (this->_name);
}

const str &Warlock::getTitle() const
{
    return (this->_title);
}

void Warlock::setTitle(const str &title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell != NULL)
    {
        std::map<str, ASpell *>::iterator it = _SpellBook.find(spell->getName());
        if (it == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(str spellName)
{
    std::map<str, ASpell *>::iterator it = _SpellBook.find(spellName);

    if (it != _SpellBook.end())
    {
        delete it->second;
        _SpellBook.erase(spellName);
    }
}

void Warlock::launchSpell(str spellName, const ATarget &src)
{
    std::map<str, ASpell *>::iterator it = _SpellBook.find(spellName);

    if (it != _SpellBook.end())
        it->second->launch(src);
}
