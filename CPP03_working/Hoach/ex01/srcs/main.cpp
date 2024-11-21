/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/21 17:23:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "O================================================================O";
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
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
std::cout << std::endl << std::endl;
		ScavTrap Scav("Scav");
        ScavTrap Trap("TRAP");
		std::cout << std::endl;
		Scav.showStatus();
        Trap.showStatus();
		Scav.setDamage(30);
		Trap.setDamage(110);

		std::cout << std::endl;
        Scav.attack(Trap.getName());
        Trap.takeDamage(Scav.getDamage()); 
		Scav.showStatus();
        Trap.showStatus();

       	std::cout << std::endl;
        Trap.attack(Scav.getName());
        Scav.takeDamage(Trap.getDamage()); 
		Trap.showStatus();
        Scav.showStatus();
		Scav.attack(Trap.getName());
		Trap.attack(Scav.getName());
		Trap.showStatus();
        Scav.showStatus();
	}
	std::cout << std::endl << std::endl << "O================================================================O" << std::endl;
}