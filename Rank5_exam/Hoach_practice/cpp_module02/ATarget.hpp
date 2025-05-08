#ifndef ATARGET
# define ATARGET

# include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        str _type;

    public:
        ATarget();
        ATarget & operator=(ATarget const &other);        
        ATarget(ATarget const &other);
        ATarget(str const & type);
        virtual ~ATarget();
        
        const str & getType() const;

        virtual ATarget * clone() const = 0;

        void getHitBySpell(ASpell const & spell) const;
};

#endif