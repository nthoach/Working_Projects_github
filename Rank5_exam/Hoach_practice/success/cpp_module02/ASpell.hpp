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
	    ASpell(std::string name, std::string effects);
        ASpell(ASpell& other);
        ASpell& operator=(ASpell& other);
        virtual ~ASpell();
 
		std::string getName() const;
        std::string getEffects() const;
		virtual ASpell* clone() const = 0;

		// 
		void launch(ATarget const& target) const;
};

#endif