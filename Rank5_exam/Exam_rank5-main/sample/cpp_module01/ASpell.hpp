#pragma once

#include <iostream>
class ATarget;

class ASpell
{
	protected:
		str _name;
		str _effects;
	public:
		ASpell(const str &name, const str &title);
		virtual ~ASpell();
		str getName() const;
		str getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &src) const;
};
