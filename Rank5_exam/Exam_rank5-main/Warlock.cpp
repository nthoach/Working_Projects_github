#include "Warlock.hpp"
#include <string>

std::string const& Warlock::getName() const {return _name;}

std::string const& Warlock::getTitle() const {return _title;}

void Warlock::setTitle(std::string const& title) { this->_title = title;}

Warlock::Warlock(std::string const& name, std::string const& title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() 
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" <<std::endl;

}


void Warlock::learnSpell(ASpell *spell)
{
	_book.learnSpell(spell);
}
void Warlock::forgetSpell(std::string const& spellname)
{
	_book.forgetSpell(spellname);
}
void Warlock::launchSpell(std::string const& spellname, ATarget const& target)
{
	ASpell *spell = _book.createSpell(spellname);
	spell->launch(target);
	delete spell;
}
