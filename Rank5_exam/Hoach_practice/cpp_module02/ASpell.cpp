#include "ASpell.hpp"

ASpell::ASpell() {}


ASpell::ASpell(str const & name, str const & effects):_name(name), _effects(effects) {}

ASpell::ASpell(ASpell const &other): _name(other._name), _effects(other._effects) {}

ASpell & ASpell::operator=(ASpell const &other)
{
    if (this != &other)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return (*this);
}

ASpell::~ASpell() {}


str const& ASpell::getName() const {return (_name);}

str const& ASpell::getEffects() const { return (_effects);}

void ASpell::launch(const ATarget & target) const { target.getHitBySpell(*this);}

