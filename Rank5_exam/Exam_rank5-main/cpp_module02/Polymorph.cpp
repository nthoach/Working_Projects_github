#include "Polymorph.hpp"

Polymorph::Polymorph()
: ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

////////////////////////////////////////////////

ASpell *Polymorph::clone()
{
    Polymorph *_clone = new Polymorph;
    _clone->name = this->name;
    _clone->effects = this->effects;
    return _clone;
}
