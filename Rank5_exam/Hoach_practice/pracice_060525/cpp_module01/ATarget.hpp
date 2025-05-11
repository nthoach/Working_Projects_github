#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

typedef str str;

class ASpell;

class ATarget
{
    private:
        str _type;
        ATarget();

    public:        
        ATarget(ATarget& other);
        ATarget& operator=(ATarget& other);
        ATarget(str type);
        virtual ~ATarget();

        str const& getType() const;
       
        virtual ATarget * clone() const = 0; 

        void getHitBySpell(ASpell const& spell) const;
};

#endif
