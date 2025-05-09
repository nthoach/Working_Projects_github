#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;

}
Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
	spell_it it = book.begin();
	while (it != book.end())
	{
		delete it->second;
		it++;
	}
	book.clear();
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
void Warlock::learnSpell(ASpell* ptr)
{
	spell_it it = book.find(ptr->getName());
	if (it == book.end())
		book[ptr->getName()] = ptr->clone();
}

void Warlock::forgetSpell(str const& name)
{
	spell_it it = book.find(name);
	if (it != book.end())
	{
		delete it->second;
		book.erase(it);
	}
}


void Warlock::launchSpell(str const& name, ATarget& target)
{
	spell_it it = book.find(name);
	if (it != book.end())
		it->second->launch(target);
}
