#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <string>
//
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

typedef std::string str;
typedef std::map<str, ASpell*> spell_map;
typedef spell_map::iterator spell_it;

class SpellBook
{
    private:
        SpellBook(SpellBook& other);
        SpellBook& operator=(SpellBook& other);
//
		spell_map book;

    public:
		SpellBook();
        ~SpellBook();
		//
		void learnSpell(ASpell* ptr);
		void forgetSpell(str const& name);
		ASpell* createSpell(str const& name);

};

#endif