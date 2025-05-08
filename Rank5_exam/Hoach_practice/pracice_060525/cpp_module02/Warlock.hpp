#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>
# include "SpellBook.hpp"

class Warlock
{
	private:
		str _name;
		str _title;
		Warlock();
		Warlock(Warlock const& other);
		Warlock& operator=(Warlock const& other);
		SpellBook _book;

	
	public:
		const str& getName() const;
		const str& getTitle() const;
		void setTitle(str const& title);
		Warlock(str  const& name, str const& title);
		~Warlock();
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(str const& spellname);
		void launchSpell(str const& spellname, ATarget const& target);
};

#endif
