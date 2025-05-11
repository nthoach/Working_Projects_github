#pragma once

#include <iostream>
#include <map>
class ASpell;

class SpellBook
{
	private:
		std::map<str, ASpell *> _SpellBook;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *);
		void forgetSpell(const str &);
		ASpell *createSpell(const str &);
};
