#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	spell_it it = book.begin();
	while (it != book.end())
	{
		delete it->second;
		it++;
	}
	book.clear();
}



void SpellBook::learnSpell(ASpell* ptr)
{
	spell_it it = book.find(ptr->getName());
	if (it == book.end())
	{
		book[ptr->getName()] = ptr->clone();
	}
}
void SpellBook::forgetSpell(str const& name)
{
	spell_it it = book.find(name);
	if (it != book.end())
	{
		delete it->second;
		book.erase(it);
	}
}
ASpell*  SpellBook::createSpell(str const& name)
{
	spell_it it = book.find(name);
	if (it != book.end())
	{
		return (it->second->clone());
	}
	return NULL;
}
