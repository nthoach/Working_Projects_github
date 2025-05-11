#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
    spell_it it = _book.begin();
    while (it != _book.end())
    {
        delete it->second;
        it++;
    }
    _book.clear();
}

//getter
std::string Warlock::getName() const
{
    return (_name);
}
std::string Warlock::getTitle() const
{
    return (_title);
}
void Warlock::setTitle(std::string const& title)
{
    _title = title;
}
void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


//
void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
    {
        forgetSpell(spell->getName());
        _book[spell->getName()]= spell->clone();
    }

}
void Warlock::forgetSpell(std::string spellname)
{
    spell_it it = _book.find(spellname);
    if (it != _book.end())
    {
        delete it->second;
        _book.erase(it);
    }    
}
void Warlock::launchSpell(std::string spellname, ATarget& target)
{
    spell_it it = _book.find(spellname);
    if (it != _book.end())
        it->second->launch(target);
}
