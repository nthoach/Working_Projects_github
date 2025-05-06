#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
// # include <map>

// typedef std::map<std::string, ASpell *> spell_map;
// typedef spell_map::iterator spell_it;
// typedef std::pair<std::string, ASpell *> spell_pair;

// typedef std::map<std::string, ATarget *> target_map;
// typedef target_map::iterator target;
// typedef std::pair<std::string, ASpell *> target_pair;

# include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        ASpell();
        std::string _name;
        std::string _effects;

    public:
    
        ASpell(std::string name, std::string effects);
        ASpell(ASpell& other);
        ASpell& operator=(ASpell& other);
        virtual ~ASpell();
        //getter
        std::string getName() const;
        std::string getEffects() const;

        virtual ASpell *clone() const = 0;

        void launch(ATarget const& target) const;

};

#endif