#include "Warlock.hpp"

Warlock::Warlock(str const &Name, str const &Title)
: name(Name), title(Title) {
    cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
    cout << name << ": My job here is done!\n";
}


////////////////////////////////////////////////////////////////

str const &Warlock::getName() const  {return name;}
str const &Warlock::getTitle() const {return title;}
void Warlock::setTitle(str const &Title) {title = Title;}

////////////////////////////////////////////////////////////////

void Warlock::introduce() const {
    cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell *newSpell) {
    spellBook.learnSpell(newSpell);
}

void Warlock::forgetSpell(str const &whichSpell) {
    spellBook.forgetSpell(whichSpell);
}

void Warlock::launchSpell(str const &whichSpell, ATarget &target) {
    ASpell *spell = spellBook.createSpell(whichSpell);
    if (spell)
        spell->launch(target);
}
