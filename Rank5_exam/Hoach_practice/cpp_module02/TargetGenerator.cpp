#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void){}

TargetGenerator::~TargetGenerator(void)
{

    while(this->_targets.begin() != this->_targets.end())
    {
        delete this->_targets.begin()->second;
        this->_targets.erase(_targets.begin());
    }
    this->_targets.clear();

}

void TargetGenerator::learnTargetType(ATarget * target)
{
    if (target)
        this->_targets[target->getType()] = target->clone();
}
void TargetGenerator::forgetTargetType(std::string const &type)
{
    if (this->_targets[type])
        delete this->_targets[type];
    this->_targets.erase(type);
    
}
ATarget* TargetGenerator::createTarget(std::string const &type)
{
    if(this->_targets[type])
        return this->_targets[type]->clone();
    return NULL;
}