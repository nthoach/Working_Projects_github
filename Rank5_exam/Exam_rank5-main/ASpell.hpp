#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
		ASpell();
	
	public:
		ASpell(std::string  const& name, std::string const& effects);
		ASpell(ASpell const& other);
		ASpell& operator=(ASpell const& other);
		virtual ~ASpell();

		const std::string& getName() const;
		const std::string& getEffects() const;

		virtual ASpell* clone() const = 0;

		void launch(ATarget const& target) const;

};

#endif
