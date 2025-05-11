#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;
// # include <map>

// typedef std::map<std::string, ATarget *> spell_map;
// typedef spell_map::iterator spell_it;
// typedef std::pair<std::string, ATarget *> spell_pair;

// typedef std::map<std::string, ATarget *> target_map;
// typedef target_map::iterator target;
// typedef std::pair<std::string, ATarget *> target_pair;

class ATarget
{
    private:
        ATarget();
        std::string _type;

    public:
    
        ATarget(std::string types);
        ATarget(ATarget& other);
        ATarget& operator=(ATarget& other);
        virtual ~ATarget();
        //getter
        std::string getType() const;

        virtual ATarget *clone() const = 0;

        void getHitBySpell(ASpell const& spell) const;

};

#endif