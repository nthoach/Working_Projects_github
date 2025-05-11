#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"


typedef str str;


class Fwoosh: public ASpell
{
    private:
        

    public:
        Fwoosh();
        ~Fwoosh();
        Fwoosh * clone() const; 
};

#endif
