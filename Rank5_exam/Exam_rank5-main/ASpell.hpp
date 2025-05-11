#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

typedef std::string str;

class ATarget;

class ASpell
{
	private:
		str _name;
		str _effects;
		ASpell();
	
	public:
		ASpell(str  const& name, str const& effects);
		ASpell(ASpell const& other);
		ASpell& operator=(ASpell const& other);
		virtual ~ASpell();

		const str& getName() const;
		const str& getEffects() const;

		virtual ASpell* clone() const = 0;

		void launch(ATarget const& target) const;

};

#endif
