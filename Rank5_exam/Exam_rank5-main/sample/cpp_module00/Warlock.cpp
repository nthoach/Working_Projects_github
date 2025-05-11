#include "Warlock.hpp"

const str &Warlock::getName() const
{
    return (this->_name);
}

const str &Warlock::getTitle() const
{
    return (this->_title);
}

void Warlock::setTitle(const str &title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

Warlock::Warlock(const str &name, const str &title): _name(name), _title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
}
