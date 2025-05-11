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

		std::map<str, ATarget *> _targets;

	public:
		TargetGenerator();
		~TargetGenerator();
	
		void learnTargetType(ATarget *spell);
		void forgetTargetType(str const& type);
		ATarget * createTarget(str const& type);

};

#endif
