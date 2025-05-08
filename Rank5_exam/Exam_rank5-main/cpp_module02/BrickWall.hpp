#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

using std::cout;
typedef str str;

class BrickWall : public ATarget{

    BrickWall(BrickWall const &copy);
    BrickWall &operator=(BrickWall const &copy);
public:
    BrickWall();
    ~BrickWall();

    ATarget *clone();
};

#endif