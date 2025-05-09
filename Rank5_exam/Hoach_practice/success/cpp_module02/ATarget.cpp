#include "ATarget.hpp"

ATarget::ATarget(std::string type): _type(type)
{
}

ATarget::ATarget(ATarget& other)
{
	other = *this;
}

ATarget& ATarget::operator=(ATarget& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

ATarget::~ATarget()
{
}

//getter
std::string ATarget::getType() const
{
    return (_type);
}

//
void ATarget::getHitBySpell(ASpell const& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}



