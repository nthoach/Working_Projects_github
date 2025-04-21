#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(str const &Type)
: type(Type){}

ATarget::~ATarget() {}

//////////////////////////////////////////////////////

str const &ATarget::getType() const  {return type;}

/////////////////////////////////////////////////////

void ATarget::getHitBySpell (ASpell const &spell) const {
    cout << type << " has been " << spell.getEffects() << "!\n";
}
