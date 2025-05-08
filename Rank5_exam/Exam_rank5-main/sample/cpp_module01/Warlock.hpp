#pragma once

#include <iostream>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
	private:
		str _name;
		str _title;
		std::map<str, ASpell *> _SpellBook;
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
