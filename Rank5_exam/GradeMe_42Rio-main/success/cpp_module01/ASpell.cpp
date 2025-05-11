#include "ASpell.hpp"


ASpell::ASpell(std::string name, std::string effects): _name(name), _effects(effects)
{

}
ASpell::ASpell(ASpell& other)
{
    *this = other;
}
ASpell& ASpell::operator=(ASpell& other)
{
    if (&other != this)
    {
        _name = other._name;
        _effects = other._effects;
    }
    return(*this);
}
ASpell::~ASpell()
{
    
}
//getter
std::string ASpell::getName() const
{
    return (_name);
}
std::string ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(ATarget const& target) const
{
    target.getHitBySpell(*this);
}
