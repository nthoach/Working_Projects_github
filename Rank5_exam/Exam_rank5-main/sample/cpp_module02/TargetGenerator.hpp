#pragma once

#include <iostream>
#include <map>
class ATarget;

class TargetGenerator
{
	private:
		std::map<str, ATarget *> tgtTypes;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *);
		void forgetTargetType(const str &);
		ATarget *createTarget(const str &);
};
