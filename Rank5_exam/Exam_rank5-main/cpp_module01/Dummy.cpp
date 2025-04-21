#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

////////////////////////////////////////////////

ATarget *Dummy::clone()
{
    Dummy *_clone = new Dummy;
    _clone->type = this->type;
    return _clone;
}
