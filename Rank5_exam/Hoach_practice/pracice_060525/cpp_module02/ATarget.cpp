#include "ATarget.hpp"
#include <string>

const std::string & ATarget::getType() const {return _type;}

ATarget::ATarget(std::string const& type): _type(type)
{
}
ATarget::~ATarget() 
{
}

ATarget::ATarget(ATarget const& other) {*this = other;}

ATarget& ATarget::operator=(const ATarget &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void ATarget::getHitBySpell(ASpell const& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
