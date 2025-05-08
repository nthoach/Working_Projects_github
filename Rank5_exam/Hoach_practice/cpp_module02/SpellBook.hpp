#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <map>
# include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<str, ASpell *> _spells;
   
        SpellBook(SpellBook const &other);
        SpellBook & operator=(SpellBook const &other);

    public:
        SpellBook(); 
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(str const &spellname);
        ASpell* createSpell(str const & spell);
            
};

# endif