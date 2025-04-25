#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
: ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

////////////////////////////////////////////////

ASpell *Fwoosh::clone()
{
    Fwoosh *_clone = new Fwoosh;
    _clone->name = this->name;
    _clone->effects = this->effects;
    return _clone;
}
