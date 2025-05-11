#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ATarget.hpp"

class Dummy : public ATarget
{
	private:
	
	public:
		Dummy();
		~Dummy();

		Dummy * clone() const;
};

#endif
