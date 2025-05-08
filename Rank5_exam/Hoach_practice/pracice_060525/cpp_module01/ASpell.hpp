#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

typedef str str;

class ATarget; 

class ASpell
{
    private:
        str _name;
        str _effects;
        ASpell();

    public:        
        ASpell(ASpell& other);
        ASpell& operator=(ASpell& other);
        ASpell(str name, str effects);
        virtual ~ASpell();

        str const& getName() const;
        str const& getEffects() const;

        virtual ASpell * clone() const = 0; 

        void launch(ATarget const& target) const;
};

#endif
