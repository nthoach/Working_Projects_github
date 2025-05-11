#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <string>
//
# include <map>
# include "ATarget.hpp"
# include "ATarget.hpp"

typedef std::string str;
typedef std::map<str, ATarget*> target_map;
typedef target_map::iterator target_it;

class TargetGenerator
{
    private:
        TargetGenerator(TargetGenerator& other);
        TargetGenerator& operator=(TargetGenerator& other);
//
		target_map book;

    public:
		TargetGenerator();
        ~TargetGenerator();
		//
		void learnTargetType(ATarget* ptr);
		void forgetTargetType(str const& name);
		ATarget* createTarget(str const& name);

};

#endif