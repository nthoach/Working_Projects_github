#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>
// # include <map>

typedef std::map<std::string, ASpell *> spell_map;
typedef spell_map::iterator spell_it;
typedef std::pair<std::string, ASpell *> spell_pair;

// typedef std::map<std::string, ATarget *> target_map;
// typedef target_map::iterator target;
// typedef std::pair<std::string, ASpell *> target_pair;

class SpellBook
{
    private:
 
        SpellBook(SpellBook& other);
        SpellBook& operator=(SpellBook& other);
        spell_map _book;

    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell* spell);
        void forgetSpell(std::string const& spellname);
        ASpell * createSpell(std::string const& spellname);
};

#endif