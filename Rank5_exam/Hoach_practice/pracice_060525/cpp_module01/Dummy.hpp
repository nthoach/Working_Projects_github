#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"


typedef str str;


class Dummy: public ATarget
{
    private:
        

    public:
        Dummy();
        ~Dummy();
        Dummy * clone() const; 
};

#endif
