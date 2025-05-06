#include "Dummy.hpp"
#include <string>

Dummy::Dummy(): ATarget("Target Practice Dummy") {}
Dummy::~Dummy() {};

ATarget * Dummy::clone() const
{
	return (new Dummy());
}