#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

typedef std::string str;

class ASpell;

class ATarget
{
	private:
		str _type;
		ATarget();
	
	public:
		ATarget(str  const& type);
		ATarget(ATarget const& other);
		ATarget& operator=(ATarget const& other);

		virtual ~ATarget();
		const str& getType() const;
	

		virtual ATarget* clone() const = 0;

		void getHitBySpell(ASpell const& spell) const;

};

#endif
