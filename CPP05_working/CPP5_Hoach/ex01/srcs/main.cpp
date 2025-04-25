<<<<<<< HEAD
/* ************************************************************************** */
=======
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 16:12:49 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:54:46 by nthoach           #+#    #+#             */
/*   Updated: 2025/04/25 05:39:03 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"

int	main(void)
{
	std::cout << "1) ================================================================" << std::endl << std::endl;
	{
<<<<<<< HEAD
		Bureaucrat p1("Boss", 1);
		std::cout << p1 << std::endl;
		Form f1("Money_Transfer", 2, 10);
		std::cout << f1 << std::endl;
		p1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	std::cout << std::endl << "2)  ================================================================" << std::endl << std::endl;
	{
		Bureaucrat p2("Head_Dept", 2);
		std::cout << p2 << std::endl;

		Form f2("Promotion", 2, 5);
		std::cout << f2 << std::endl;
		p2.signForm(f2);
		std::cout << f2 << std::endl;
	}
	std::cout << std::endl << "3) ================================================================" << std::endl << std::endl;
	{
		Bureaucrat p3("Worker", 149);
		std::cout << p3 << std::endl;

		Form f3("Buy", 3, 50);
		std::cout << f3 << std::endl;
		p3.signForm(f3);
		std::cout << f3 << std::endl;
	}
	std::cout << std::endl << "4) ================================================================" << std::endl << std::endl;
	{
		try
		{
			Form f("Working_confirm", 1234, 150);
			std::cout << f << std::endl;
			std::cout << std::endl << " > " << f << std::endl << std::endl;
		}
		catch (std::exception &e) 
=======
		Bureaucrat b("Gravy", 1);
		std::cout << b << std::endl;

		Form f("Artillery only", 2, 1);
		std::cout << f << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl << " > " << f << std::endl << std::endl;
	}
	std::cout << std::endl << "2 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Timmy", 2);
		std::cout << b << std::endl;

		Form f("Megacampaign", 2, 1);
		std::cout << f << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl << " > " << f << std::endl << std::endl;
	}
	std::cout << std::endl << "3 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Baby", 3);
		std::cout << b << std::endl;

		Form f("Ck3 A to Z", 2, 1);
		std::cout << f << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl << " > " << f << std::endl << std::endl;
	}
	std::cout << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		try
		{
			Form f("All achievements", 1234, 1);
			std::cout << std::endl << " > " << f << std::endl << std::endl;
		}
		catch (std::exception &e)
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

	}
<<<<<<< HEAD
	std::cout << std::endl << "5) ================================================================" << std::endl << std::endl;
	{
		Form f1("BeingAssigned", 2, 1);
=======
	std::cout << std::endl << "5 O================================================================O" << std::endl << std::endl;
	{
		Form f1("A", 2, 1);
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
		std::cout << f1 << std::endl;

		try
		{
<<<<<<< HEAD
			Form f2("Assigned", 4, 3);
=======
			Form f2("Z", 4, 3);
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
			f2 = f1;
			std::cout << std::endl << " > " << f2 << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
<<<<<<< HEAD
	std::cout << std::endl << "6) ================================================================" << std::endl << std::endl;
	{
		Form f1("Copied", 2, 1);
=======
	std::cout << std::endl << "6 O================================================================O" << std::endl << std::endl;
	{
		Form f1("Tank only", 2, 1);
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
		std::cout << f1 << std::endl;

		try
		{
			Form f2(f1);
			std::cout << std::endl << " > " << f2 << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
<<<<<<< HEAD
	std::cout << std::endl << "================================================================" << std::endl << std::endl;
=======
	std::cout << std::endl << "E O================================================================O" << std::endl << std::endl;
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
}