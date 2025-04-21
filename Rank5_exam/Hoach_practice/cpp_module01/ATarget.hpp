#ifndef ATARGET
# define ATARGET

# include <iostream>
# include <string>

class ASpell;

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget & operator=(ATarget const &other);        
        ATarget(ATarget const &other);
        ATarget(std::string const & type);
        virtual ~ATarget();
        
        const std::string & getType() const;

        virtual ATarget * clone() const = 0;

        void getHitBySpell(ASpell const & spell) const;
};

#endif