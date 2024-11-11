/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 17:56:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Weapon.hpp"
#include "../incl/HumanA.hpp"
#include "../incl/HumanB.hpp"

int	main(void)
{
	{
		std::cout << std::endl;
		Weapon club = Weapon("crude spiked club");
		std::cout << std::endl;
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club"); 
		bob.attack();
		std::cout << std::endl;
	} 
	{
		std::cout << std::endl;
		Weapon club = Weapon("crude spiked club");
		std::cout << std::endl;
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		std::cout << std::endl;
		club.setType("some other type of club");
		std::cout << std::endl;
		jim.setWeapon(club);
		jim.attack();
	}
	return (0);
}
