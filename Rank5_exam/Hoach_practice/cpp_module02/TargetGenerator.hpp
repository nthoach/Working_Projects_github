#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<std::string, ATarget *> _targets;
   
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator & operator=(TargetGenerator const &other);

    public:
        TargetGenerator(); 
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(std::string const &targetname);
        ATarget* createTarget(std::string const & targetname);
            
};

# endif
