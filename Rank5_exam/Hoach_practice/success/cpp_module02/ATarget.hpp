#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
        std::string _type;
		ATarget();

    public:
	    ATarget(std::string type);
        ATarget(ATarget& other);
        ATarget& operator=(ATarget& other);
        virtual ~ATarget();
 
		std::string getType() const;
		virtual ATarget* clone() const = 0;

	//
		void getHitBySpell(ASpell const& spell) const;
};

#endif