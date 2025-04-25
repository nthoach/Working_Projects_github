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