
#include "Warlock.hpp"


Warlock::Warlock(str const &name, str const &title): _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

str const& Warlock::getName() const { return (_name);}

str const& Warlock::getTitle() const { return _title;}

void Warlock::setTitle(const str &title) {this->_title = title; }

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell *spell)
{
    _spellbook.learnSpell(spell);
}
void Warlock::forgetSpell(str const &spellname)
{
    _spellbook.forgetSpell(spellname);
}

void Warlock::launchSpell(str const &spellname, ATarget const& target)
{
    ASpell *spell= _spellbook.createSpell(spellname);

    if (spell != NULL)
    {
        spell->launch(target);
        delete spell;
    }
}