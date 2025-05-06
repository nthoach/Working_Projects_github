#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"
# include <map>


class TargetGenerator
{
	private:
		TargetGenerator& operator=(TargetGenerator const& other);
		TargetGenerator(TargetGenerator const& other);

		std::map<std::string, ATarget *> _targets;

	public:
		TargetGenerator();
		~TargetGenerator();
	
		void learnTargetType(ATarget *spell);
		void forgetTargetType(std::string const& type);
		ATarget * createTarget(std::string const& type);

};

#endif
