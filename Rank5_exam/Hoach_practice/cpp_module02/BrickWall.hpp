#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall: public ATarget
{
    private:

    public:
        
        BrickWall();
        ~BrickWall();

        BrickWall * clone() const;

};

#endif