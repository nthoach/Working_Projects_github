#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const str &name, const str &effects): _name(name), _effects(effects)
{}

ASpell::~ASpell()
{}

str ASpell::getName() const
{
    return (this->_name);
}

str ASpell::getEffects() const
{
    return (this->_effects);
}

void ASpell::launch(const ATarget &src) const
{
    src.getHitBySpell(*this);
}

