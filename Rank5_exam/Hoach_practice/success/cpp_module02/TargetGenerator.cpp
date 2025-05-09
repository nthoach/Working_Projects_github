#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	target_it it = book.begin();
	while (it != book.end())
	{
		delete it->second;
		it++;
	}
	book.clear();
}


void TargetGenerator::learnTargetType(ATarget* ptr)
{
	target_it it = book.find(ptr->getType());
	if (it == book.end())
	{
		book[ptr->getType()] = ptr->clone();
	}
}
void TargetGenerator::forgetTargetType(str const& name)
{
	target_it it = book.find(name);
	if (it != book.end())
	{
		delete it->second;
		book.erase(it);
	}
}
ATarget*  TargetGenerator::createTarget(str const& name)
{
	target_it it = book.find(name);
	if (it != book.end())
	{
		return (it->second->clone());
	}
	return NULL;
}
