#include "ASpell.hpp"

ASpell::ASpell(ASpell& other) {*this = other;}

ASpell& ASpell::operator=(ASpell& other)
{
    if (this != &other)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return *this;
}

ASpell::ASpell(str name, str effects): _name(name), _effects(effects) {}

ASpell::~ASpell() {}

str const& ASpell::getName() const {return _name;}
str const& ASpell::getEffects() const {return _effects;}

void ASpell::launch(ATarget const& target) const
{
    target.getHitBySpell(*this);
}