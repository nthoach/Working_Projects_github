/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 18:48:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> 
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "\n\n 1.1)_________ Sign and Execute Check - No error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Boss", 1);
		std::cout << b << std::endl;

		PresidentialPardonForm f("Conscience");
		std::cout << f << std::endl << std::endl;
		b.signForm(f);
		std::cout << std::endl;
		b.executeForm(f);
	}
	
	std::cout << "\n1.2)_________ Execute Without Sign - error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Boss", 1);
		std::cout << b << std::endl;

		PresidentialPardonForm f("Conscience");
		std::cout << f << std::endl << std::endl;
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << "\n1.3) _________ Sign and Execute but not Enough Grade - error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Head of Dept.", 6);
		std::cout << b << std::endl;

		PresidentialPardonForm f("Conscience");
		std::cout << f << std::endl << std::endl;

		b.signForm(f);
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << "\n1.4) _________Canot Sign and Exec ___________" << std::endl << std::endl;
	{
		Bureaucrat b("StaffA", 26);
		std::cout << b << std::endl;

		PresidentialPardonForm f("Conscience");
		std::cout << f << std::endl << std::endl;
		try
		{
			b.signForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}


	std::cout << "\n 2.1)_________ Sign and Execute Check - No error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Boss", 1);
		std::cout << b << std::endl;

		RobotomyRequestForm f("MakingCar");
		std::cout << f << std::endl << std::endl;
		b.signForm(f);
		std::cout << std::endl;
		b.executeForm(f);
	}
	
	std::cout << "\n2.2)_________ Execute Without Sign - error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Boss", 1);
		std::cout << b << std::endl;

		RobotomyRequestForm f("MakingCar");
		std::cout << f << std::endl << std::endl;
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << "\n2.3) _________ Sign and Execute but not Enough Grade - error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Staff", 46);
		std::cout << b << std::endl;

		RobotomyRequestForm f("MakingCar");
		std::cout << f << std::endl << std::endl;

		b.signForm(f);
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << "\n2.4) _________Canot Sign and Exec ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Worker", 73);
		std::cout << b << std::endl;

		RobotomyRequestForm f("MakingCar");
		std::cout << f << std::endl << std::endl;
		try
		{
			b.signForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}


	std::cout << "\n 3.1)_________ Sign and Execute Check - No error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Boss", 1);
		std::cout << b << std::endl;

		ShrubberyCreationForm f("TrimGarden");
		std::cout << f << std::endl << std::endl;
		b.signForm(f);
		std::cout << std::endl;
		b.executeForm(f);

		std::string command = "cat " + f.getTarget() + "_shrubbery";
		system(command.c_str());
	}
	
	std::cout << "\n3.2)_________ Execute Without Sign - error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Boss", 1);
		std::cout << b << std::endl;

		ShrubberyCreationForm f("TrimGarden");
		std::cout << f << std::endl << std::endl;
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << "\n3.3) _________ Sign and Execute but not Enough Grade - error ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Staff", 138);
		std::cout << b << std::endl;

		ShrubberyCreationForm f("TrimGarden");
		std::cout << f << std::endl << std::endl;

		b.signForm(f);
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << "\n3.4) _________Canot Sign and Exec ___________" << std::endl << std::endl;
	{
		Bureaucrat b("Worker", 146);
		std::cout << b << std::endl;

		ShrubberyCreationForm f("TrimGarden");
		std::cout << f << std::endl << std::endl;
		try
		{
			b.signForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "================================================================" << std::endl << std::endl;
}