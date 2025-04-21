#include "Warlock.hpp"

Warlock::Warlock(str const &Name, str const &Title)
: name(Name), title(Title) {
    cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {

    for (spell_It i = spells.begin(); i != spells.end(); i++) {
        delete (*i);
    }
    spells.clear();
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

    for (spell_It i = spells.begin(); i != spells.end(); i++) {
        if ((*i)->getName() == newSpell->getName()) 
            return;
    }
    spells.push_back(newSpell->clone());
}

void Warlock::forgetSpell(str const &whichSpell) {

     for (spell_It i = spells.begin(); i != spells.end(); i++) {
        if ((*i)->getName() == whichSpell) {
            delete (*i);
            spells.erase(i);
            return;
        }
    }
}

void Warlock::launchSpell(str const &whichSpell, ATarget &target) {

    for (spell_It i = spells.begin(); i != spells.end(); i++) {
        if ((*i)->getName() == whichSpell) {
            (*i)->launch(target);
            return;
        }
    }
}