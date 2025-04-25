#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ATarget.hpp"

using std::cout;
typedef std::string str;
typedef std::vector<ATarget *>::iterator target_It;

class TargetGenerator {
    std::vector<ATarget *> targets;

    TargetGenerator(TargetGenerator const &copy);
    TargetGenerator &operator=(TargetGenerator const &copy);
public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget *newTarget);
    void forgetTargetType(str const &whichTarget);
    ATarget* createTarget(str const &whichTarget);
};

#endif
