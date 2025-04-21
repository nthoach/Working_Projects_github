#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(str const &Name, str const &Effects)
: name(Name), effects(Effects){}

ASpell::~ASpell() {}

//////////////////////////////////////////////////////

str const &ASpell::getName() const  {return name;}
str const &ASpell::getEffects() const {return effects;}

/////////////////////////////////////////////////////

void ASpell::launch(ATarget const &target) const {
    target.getHitBySpell(*this);
}