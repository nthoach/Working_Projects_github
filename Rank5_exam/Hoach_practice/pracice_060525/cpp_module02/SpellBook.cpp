#include "SpellBook.hpp"
#include <string>

SpellBook::SpellBook() {}

SpellBook::~SpellBook() 
{
	std::map<str, ASpell *>::iterator it = _spells.begin();
	while (it != _spells.end())
	{
		delete it->second;
		it++;
	}
	_spells.clear();
}


void SpellBook::learnSpell(ASpell *spell)
{
	if (spell != NULL)
	{
		std::map<str, ASpell *>::iterator it = _spells.find(spell->getName());
		if (it == _spells.end())
		{
			_spells[spell->getName()] = spell->clone();
		}
	}
}
void SpellBook::forgetSpell(str const& spellname)
{
	if (_spells.find(spellname) != _spells.end())
	{
		delete _spells[spellname];
		_spells.erase(spellname);
		//std::cout << "forgetSpell = " << spellname << std::endl;
	}
}

ASpell * SpellBook::createSpell(str const& spellname)
{
	if(_spells.find(spellname) != _spells.end())
	{
		return (_spells[spellname]->clone());
	}
	return (NULL);

}
