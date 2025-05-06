#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"
# include "ATarget.hpp"
# include <map>
// # include <map>

// typedef std::map<std::string, ATarget *> target_map;
// typedef target_map::iterator spell_it;
// typedef std::pair<std::string, ATarget *> spell_pair;

typedef std::map<std::string, ATarget *> target_map;
typedef target_map::iterator target_it;
typedef std::pair<std::string, ATarget *> target_pair;

class TargetGenerator
{
    private:
 
        TargetGenerator(TargetGenerator& other);
        TargetGenerator& operator=(TargetGenerator& other);
        target_map _book;

    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget* target);
        void forgetTargetType(std::string const& name);
        ATarget * createTarget(std::string const& name);
};

#endif