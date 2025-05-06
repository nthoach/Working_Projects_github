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
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock const& other);
		Warlock& operator=(Warlock const& other);
		SpellBook _book;

	
	public:
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(std::string const& title);
		Warlock(std::string  const& name, std::string const& title);
		~Warlock();
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const& spellname);
		void launchSpell(std::string const& spellname, ATarget const& target);
};

#endif
