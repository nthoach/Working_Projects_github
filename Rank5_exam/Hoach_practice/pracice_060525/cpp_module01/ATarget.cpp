
#include "ATarget.hpp"

ATarget::ATarget(ATarget& other) {*this = other;}

ATarget& ATarget::operator=(ATarget& other)
{
    if (this != &other)
    {
        _type= other._type;
    }
    return *this;
}

ATarget::ATarget(str type): _type(type) {}

ATarget::~ATarget() {}

str const& ATarget::getType() const {return _type;}


void ATarget::getHitBySpell(ASpell const& spell) const
{
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}