
#include "Warlock.hpp"


Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const& Warlock::getName() const { return (_name);}

std::string const& Warlock::getTitle() const { return _title;}

void Warlock::setTitle(const std::string &title) {this->_title = title; }

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell *spell)
{
    _spellbook.learnSpell(spell);
}
void Warlock::forgetSpell(std::string const &spellname)
{
    _spellbook.forgetSpell(spellname);
}

void Warlock::launchSpell(std::string const &spellname, ATarget const& target)
{
    ASpell *spell= _spellbook.createSpell(spellname);

    if (spell != NULL)
    {
        spell->launch(target);
        delete spell;
    }
}