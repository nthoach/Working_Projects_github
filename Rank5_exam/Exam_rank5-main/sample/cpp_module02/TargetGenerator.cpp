#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
    tgtTypes.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target != NULL)
    {
        std::map<str, ATarget *>::iterator it = tgtTypes.find(target->getType());

        if (it == tgtTypes.end())
            tgtTypes[target->getType()] = target;
    }
}

void TargetGenerator::forgetTargetType(const str &target)
{
    std::map<str, ATarget *>::iterator it = tgtTypes.find(target);

    if (it != tgtTypes.end())
        tgtTypes.erase(target);
}

ATarget *TargetGenerator::createTarget(const str &target)
{
    std::map<str, ATarget *>::iterator it = tgtTypes.find(target);

    if (it != tgtTypes.end())
        return (it->second->clone());
    return NULL;
}
