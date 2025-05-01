
#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator it = _spells.begin();
    while (it != _spells.end())
    {
        delete it->second; //delete ASpell
        it++;
    }
    _spells.clear();
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
    if (spell)
    {
        _spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
        // std::map<std::string, ASpell *>::iterator it = _spells.find(spell->getName());
        // if (it == _spells.end())
        // {
        //     _spells[spell->getName()] = spell->clone();
        // }
    }
}
void Warlock::forgetSpell(std::string const &spellname)
{
    std::map<std::string, ASpell *>::iterator it = _spells.find(spellname);
    if (it != _spells.end())
    {
        delete it->second; //delete ASpell
        _spells.erase(it); //remove key value pair
    }
}

void Warlock::launchSpell(std::string const &spellname, ATarget const& target)
{
    ASpell *spell = _spells[spellname];
    if (spell)
    {
        spell->launch(target);
    }
    // std::map<std::string, ASpell *>::iterator it = _spells.find(spellname);
    // if (it != _spells.end())
    // {
    //     it->second->launch(target);
    // }
}