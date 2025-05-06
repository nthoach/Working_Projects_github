#ifndef FIREBALL_HPP
# define FIREBALL_HPP

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

class Fireball: public ASpell
{
    private:

    public:
        Fireball();
        ~Fireball();
        virtual ASpell* clone() const;
};

#endif