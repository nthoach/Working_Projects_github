#include "AForm.hpp"
#include <map>

class Intern
{
	private:
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

	public: 
		//Orthodox Canonical Intern
		Intern();
		~Intern();

		AForm *makeForm(std::string const& formName, std::string const& target) const;
		
		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

