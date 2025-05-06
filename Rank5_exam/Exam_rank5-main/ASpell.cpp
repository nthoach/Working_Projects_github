#include "ASpell.hpp"
#include <string>

const std::string & ASpell::getName() const {return _name;}

const std::string & ASpell::getEffects() const {return _effects;}


ASpell::ASpell(std::string const& name, std::string const& effect): _name(name), _effects(effect)
{
}

ASpell::~ASpell() 
{
}

ASpell:: ASpell(ASpell const& other) { *this = other;}

ASpell& ASpell::operator=(ASpell const& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return (*this);
}

void ASpell::launch(ATarget const& targ) const
{
	targ.getHitBySpell(*this);
}
