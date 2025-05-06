#include "Warlock.hpp"

Warlock::Warlock(str name, str title): _name(name), _title(title) 
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

str const& Warlock::getName() const {return _name;}
str const& Warlock::getTitle() const{return _title;}

void Warlock::setTitle(str const& title){ _title = title;}

void Warlock::introduce() const
{
    std::cout << _name << " I am " << _name << ", " << _title << "!" << std::endl; 
}