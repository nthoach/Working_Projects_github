#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<str, ATarget *> _targets;
   
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator & operator=(TargetGenerator const &other);

    public:
        TargetGenerator(); 
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(str const &targetname);
        ATarget* createTarget(str const & targetname);
            
};

# endif
