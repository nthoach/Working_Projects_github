/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 19:51:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;
		ClapTrap Clapper("CLAP");
        ClapTrap Trapper("TRAP");
		std::cout << std::endl;
		Clapper.showStatus();
        Trapper.showStatus();

		std::cout << std::endl;
        Clapper.attack("TRAP");
        Trapper.takeDamage(3); 
		Clapper.showStatus();
        Trapper.showStatus();

       	std::cout << std::endl;
        Trapper.attack("CLAP");
        Clapper.takeDamage(3); 
		Trapper.showStatus();
        Clapper.showStatus();

       	std::cout << std::endl;
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.showStatus();

        std::cout << std::endl;
        Trapper.attack("CLAP");
		Clapper.takeDamage(16);
        Trapper.showStatus();
   		Clapper.showStatus();

	    std::cout << std::endl;	
        Clapper.beRepaired(1);
        Trapper.beRepaired(1);
  		Clapper.showStatus();

		std::cout << std::endl;
	    Trapper.showStatus();
	    Clapper.showStatus();
	}
	std::cout << std::endl << std::endl << "O================================================================O" << std::endl;
}