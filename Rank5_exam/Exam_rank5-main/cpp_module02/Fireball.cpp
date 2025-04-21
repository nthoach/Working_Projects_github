#include "Fireball.hpp"

Fireball::Fireball()
: ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

////////////////////////////////////////////////

ASpell *Fireball::clone()
{
    Fireball *_clone = new Fireball;
    _clone->name = this->name;
    _clone->effects = this->effects;
    return _clone;
}
