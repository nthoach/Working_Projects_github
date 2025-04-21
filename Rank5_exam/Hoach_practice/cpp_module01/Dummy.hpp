#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"

class Dummy: public ATarget
{
    private:

    public:
        
        Dummy();
        ~Dummy();

        Dummy * clone() const;

};

#endif