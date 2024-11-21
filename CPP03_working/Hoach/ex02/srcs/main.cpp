/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/21 17:54:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
		FragTrap Frag("Frag");
        FragTrap Trap("TRAP");
		std::cout << std::endl;
		Frag.showStatus();
        Trap.showStatus();
		Frag.setDamage(30);
		Trap.setDamage(110);

		std::cout << std::endl;
        Frag.attack(Trap.getName());
        Trap.takeDamage(Frag.getDamage()); 
		Frag.showStatus();
        Trap.showStatus();

       	std::cout << std::endl;
        Trap.attack(Frag.getName());
        Frag.takeDamage(Trap.getDamage()); 
		Trap.showStatus();
        Frag.showStatus();
		Frag.attack(Trap.getName());
		Trap.attack(Frag.getName());
		Trap.showStatus();
        Frag.showStatus();
return 0;
}