#pragma once

#include <iostream>
class ASpell;

class ATarget
{
	protected:
		str _type;
	public:
		ATarget(const str &type);
		virtual ~ATarget();
		const str &getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &src) const;
};
