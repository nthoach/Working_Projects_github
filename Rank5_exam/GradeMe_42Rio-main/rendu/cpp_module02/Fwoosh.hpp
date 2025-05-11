#ifndef FWOOSH
# define FWOOSH

# include <iostream>
# include <string>
// # include <map>

// typedef std::map<std::string, ASpell *> spell_map;
// typedef spell_map::iterator spell_it;
// typedef std::pair<std::string, ASpell *> spell_pair;

// typedef std::map<std::string, ATarget *> target_map;
// typedef target_map::iterator target;
// typedef std::pair<std::string, ASpell *> target_pair;

# include "ASpell.hpp"

class Fwoosh: public ASpell
{
    private:

    public:
        Fwoosh();
        ~Fwoosh();
        virtual ASpell* clone() const;
};

#endif