#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
    target_it it = _book.begin();
    while (it != _book.end())
    {
        delete it->second;
        it++;
    }
    _book.clear();
}

//
void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target)
    {
        forgetTargetType(target->getType());
        _book[target->getType()]= target->clone();
    }

}
void TargetGenerator::forgetTargetType(std::string const& name)
{
    target_it it = _book.find(name);
    if (it != _book.end())
    {
        delete it->second;
        _book.erase(it);
    }    
}

ATarget * TargetGenerator::createTarget(std::string const& name)
{
    target_it it = _book.find(name);
    if (it != _book.end())
        return(it->second->clone());
    return (NULL);
}
