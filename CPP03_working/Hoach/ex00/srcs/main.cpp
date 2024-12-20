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
	std::cout << std::endl << "===================================================";
	{
		std::cout << std::endl << std::endl;
		ClapTrap Clap("CLAP");
        ClapTrap Trap("TRAP");
		std::cout << std::endl;
		Clap.showStatus();
        Trap.showStatus();
		Clap.setDamage(3);
		Trap.setDamage(3);

		std::cout << std::endl;
        Clap.attack(Trap.getName());
        Trap.takeDamage(Clap.getDamage()); 
		Clap.showStatus();
        Trap.showStatus();

       	std::cout << std::endl;
        Trap.attack(Clap.getName());
        Clap.takeDamage(Trap.getDamage()); 
		Trap.showStatus();
        Clap.showStatus();

       	std::cout << std::endl;
		Clap.beRepaired(3);
		Clap.beRepaired(3);
		Clap.showStatus();
		std::cout << std::endl;
		Trap.beRepaired(3);
		Trap.beRepaired(3);
		Trap.showStatus();

        std::cout << std::endl;
		Clap.setDamage(16);
		Trap.setDamage(16);
        Trap.attack(Clap.getName());
		Clap.takeDamage(Trap.getDamage());
        Clap.showStatus();
   		Trap.showStatus();

	    std::cout << std::endl;	
        Clap.beRepaired(2);
        Trap.beRepaired(2);
  	
		std::cout << std::endl;
	    Clap.showStatus();
	    Trap.showStatus();
	}
	std::cout << std::endl << std::endl << "==============================================" << std::endl;
}