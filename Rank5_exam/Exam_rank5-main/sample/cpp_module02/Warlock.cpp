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
    spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(str spellName)
{
    spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(str spellName, const ATarget &src)
{
    ASpell *spell = spellBook.createSpell(spellName);

    if (spell != NULL)
    {
        spell->launch(src);
        delete spell;
    }
}
