#include "TargetGenerator.hpp"
#include <string>

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() 
{
	std::map<str, ATarget *>::iterator it = _targets.begin();
	while (it != _targets.end())
	{
		delete it->second;
		it++;
	}
	_targets.clear();
}


void TargetGenerator::learnTargetType(ATarget *target)
{
	// if (target != NULL)
	// {
	// 	forgetTargetType(target->getType());
	// 	if(_targets.find(target->getType()) == _targets.end())
	// 	{
	// 		_targets[target->getType()] = target->clone();
	// 		//std::cout << "clone =" << _targets[target->getType()] << std::endl;
	// 	}
	// }
	if (target)
	{
		str name = target->getType();
		forgetTargetType(name);
		_targets[name] = target->clone();
	}
}
void TargetGenerator::forgetTargetType(str const& type)
{
	if (_targets.find(type) != _targets.end())
	{
		delete _targets[type];
		_targets.erase(type);
	}
}

ATarget * TargetGenerator::createTarget(str const& type)
{
	if(_targets.find(type) != _targets.end())
	{
		return (_targets[type]->clone());
	}
	return (NULL);
}
