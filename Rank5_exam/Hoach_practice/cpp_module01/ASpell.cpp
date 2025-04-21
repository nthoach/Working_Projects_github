#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(): _name("noname"), _effects("noeffects") {}


ASpell::ASpell(std::string const & name, std::string const & effects):_name(name), _effects(effects)
{
}

ASpell::ASpell(ASpell const &other): _name(other._name), _effects(other._effects)
{
}
ASpell & ASpell::operator=(ASpell const &other)
{
    if (this != &other)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return (*this);
}

std::string const& ASpell::getName() const
{
    return (_name);
}

std::string const& ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(const ATarget & target) const
{
    target.getHitBySpell(*this);
}