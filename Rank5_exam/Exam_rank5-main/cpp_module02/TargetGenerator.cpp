#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {

    for (target_It i = targets.begin(); i != targets.end(); i++) {
        delete (*i);
    }
    targets.clear();
}


////////////////////////////////////////////////////////////////


void TargetGenerator::learnTargetType(ATarget *newTarget) {

    if (newTarget)
    {
        for (target_It i = targets.begin(); i != targets.end(); i++) {
        if ((*i)->getType() == newTarget->getType()) 
            return;
        }
        targets.push_back(newTarget->clone());
    }
}

void TargetGenerator::forgetTargetType(str const &whichTarget) {

     for (target_It i = targets.begin(); i != targets.end(); i++) {
        if ((*i)->getType() == whichTarget) {
            delete (*i);
            targets.erase(i);
            return;
        }
    }
}

ATarget* TargetGenerator::createTarget(str const &whichTarget) {

    for (target_It i = targets.begin(); i != targets.end(); i++) {
        if ((*i)->getType() == whichTarget) {
            return (*i);
        }
    }
    return NULL;
}
