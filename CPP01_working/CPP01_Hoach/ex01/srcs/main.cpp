/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 14:36:18 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie *zhorde;

	if (ac != 3 || atoi(av[1]) <= 0)
	{
		std::cout << "\033[1;31mPlease provide the number and name of the zombie, respectively.\033[0m" << std::endl;
		return (1);
	}
	else
		zhorde = zombieHorde(atoi(av[1]), av[2]);
	std::cout << "\033[1;36mZombie horde created\033[0m" << std::endl;
	for (int i = 0; i < atoi(av[1]); i++)
	{
		zhorde[i].announce();
	}
	delete[] zhorde;
	std::cout << "\033[1;31mZombie horde dead\033[0m" << std::endl;
	return (0);
}
