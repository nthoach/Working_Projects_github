#include "Warlock.hpp"

Warlock::Warlock(str name, str title): _name(name), _title(title) 
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
        ++it;
    }
    _book.clear();
}

str const& Warlock::getName() const {return _name;}
str const& Warlock::getTitle() const{return _title;}

void Warlock::setTitle(str const& title){ _title = title;}

void Warlock::introduce() const
{
    std::cout << _name << " I am " << _name << ", " << _title << "!" << std::endl; 
}

void Warlock::learnSpell(ASpell * spell_ptr)
{
    if (spell_ptr)
    {
        str name = spell_ptr->getName();
        forgetSpell(name);
        _book[name] = spell_ptr->clone();
    }
}
void Warlock::forgetSpell(str const& name)
{
    spell_it it = _book.find(name);
    if (it != _book.end())
    {
        delete it->second;
        _book.erase(it);
    }
}

void Warlock::launchSpell(str const& name,  ATarget const& target)
{
    spell_it it = _book.find(name);
    if (it != _book.end())
        it->second->launch(target);
}