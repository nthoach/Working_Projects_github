#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <map>
# include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell *> _spells;
   
        SpellBook(SpellBook const &other);
        SpellBook & operator=(SpellBook const &other);

    public:
        SpellBook(); 
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &spellname);
        ASpell* createSpell(std::string const & spell);
            
};

# endif