#include "SpellBook.hpp"
#include <string>

SpellBook::SpellBook() {}

SpellBook::~SpellBook() 
{
	std::map<std::string, ASpell *>::iterator it = _spells.begin();
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
		if(_spells.find(spell->getName()) == _spells.end())
		{
			_spells[spell->getName()] = spell->clone();
			//std::cout << "clone =" << _spells[spell->getName()] << std::endl;
		}
	}
}
void SpellBook::forgetSpell(std::string const& spellname)
{
	if (_spells.find(spellname) != _spells.end())
	{
		delete _spells[spellname];
		_spells.erase(spellname);
		//std::cout << "forgetSpell = " << spellname << std::endl;
	}
}

ASpell * SpellBook::createSpell(std::string const& spellname)
{
	if(_spells.find(spellname) != _spells.end())
	{
		return (_spells[spellname]->clone());
	}
	return (NULL);

}
