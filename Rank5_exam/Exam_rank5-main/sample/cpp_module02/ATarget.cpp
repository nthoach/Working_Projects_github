#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const str &type): _type(type)
{}

ATarget::~ATarget()
{}

const str &ATarget::getType() const
{
    return (this->_type);
}

void ATarget::getHitBySpell(const ASpell &src) const
{
    std::cout << this->_type << " has been " << src.getEffects() << "!" << std::endl;
}

