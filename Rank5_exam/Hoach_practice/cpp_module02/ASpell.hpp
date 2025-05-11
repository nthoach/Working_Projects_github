#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        str _name;
        str _effects;

    public:
        ASpell();
        ASpell(str const & name, str const & effects);        
        ASpell(ASpell const &other);
        ASpell & operator=(ASpell const &other);
        virtual ~ASpell();

        const str & getName() const;
        const str & getEffects() const;
        virtual ASpell * clone() const = 0;
        void launch(const ATarget & target) const;
    };

#endif