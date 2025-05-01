#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/Intern.hpp"
#include <unistd.h>

int	main(void)
{
	Bureaucrat b("Overseer", 1);

	std::cout << std::endl << std::endl << "\n\n 1.1)_________ Intern make schrubbery form ___________" << std::endl << std::endl;
	{
		Intern	i;

		AForm	*form;
		std::cout << std::endl;

		form = i.makeForm("shrubbery creation", "Forest");
		std::cout << *form << std::endl;

		b.signForm(*form);
		std::cout << std::endl;

		b.executeForm(*form);
		std::cout << std::endl;

		delete form;
	}
	sleep(1);
	std::cout << std::endl << std::endl << "\n 1.2)_________ Intern make presidential pardon ___________" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		form = i.makeForm("presidential pardon", "Zap");
		std::cout << std::endl;

		b.signForm(*form);
		std::cout << std::endl;

		b.executeForm(*form);
		std::cout << std::endl;

		delete form;
	}
	sleep(1);
	std::cout << std::endl << std::endl << "\n 1.3)_________Intern make robotomy request ___________" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		form = i.makeForm("robotomy request", "Bender");
		std::cout << std::endl;

		b.signForm(*form);
		std::cout << std::endl;

		b.executeForm(*form);
		std::cout << std::endl;

		delete form;
	}
	sleep(1);
	std::cout << std::endl << std::endl << "1.4)_________Intern make dance sentence form - not existed ___________" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		try
		{
			form = i.makeForm("dance sentence", "Spider");
			std::cout << std::endl;

			b.signForm(*form);
			std::cout << std::endl;

			b.executeForm(*form);
			std::cout << std::endl;

			delete form;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

	}
	std::cout << std::endl << std::endl << "-------------------End----------------" << std::endl << std::endl;
}