
#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(): _type("notype") {}


ATarget::ATarget(std::string const & type):_type(type) {}

ATarget::ATarget(ATarget const &other): _type(other._type) {}

ATarget & ATarget::operator=(ATarget const &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

std::string const& ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(const ASpell  & spell) const
{
    std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}