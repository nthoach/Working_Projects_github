#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"
# include <map>

class ATarget;

class SpellBook
{
	private:

		SpellBook& operator=(SpellBook const& other);
		SpellBook(SpellBook const& other);
		std::map<str, ASpell *> _spells;

	public:
		SpellBook();
		~SpellBook();
	
		void learnSpell(ASpell *spell);
		void forgetSpell(str const& spellname);
		ASpell * createSpell(str const& spellname);

};

#endif
