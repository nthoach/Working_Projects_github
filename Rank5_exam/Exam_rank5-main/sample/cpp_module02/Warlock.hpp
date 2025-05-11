#pragma once

#include <iostream>
#include <map>
#include "SpellBook.hpp"

class ASpell;
class ATarget;

class Warlock
{
	private:
		str _name;
		str _title;
		SpellBook spellBook;
	public:
	    Warlock(const str &name, const str &title);
	    ~Warlock();
		const str &getName() const;
		const str &getTitle() const;
		void setTitle(const str &title);
		void introduce() const;

		void learnSpell(ASpell *);
		void forgetSpell(str);
		void launchSpell(str, const ATarget &);
};
