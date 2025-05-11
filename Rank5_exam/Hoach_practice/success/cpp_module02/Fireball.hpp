#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class Fireball: public ASpell
{
    private:
		
    public:
		Fireball();
        ~Fireball();
		Fireball* clone() const;
};

#endif