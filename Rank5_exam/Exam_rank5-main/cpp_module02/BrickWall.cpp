#include "BrickWall.hpp"

BrickWall::BrickWall()
: ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

////////////////////////////////////////////////

ATarget *BrickWall::clone()
{
    BrickWall *_clone = new BrickWall;
    _clone->type = this->type;
    return _clone;
}
