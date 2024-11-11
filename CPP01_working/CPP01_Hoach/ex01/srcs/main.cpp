/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 16:51:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"
#include <cstdlib> 

int	main(int ac, char **av)
{
	Zombie *zs;

	if (ac != 3 || atoi(av[1]) <= 0)
	{
		std::cout << "Enter Number and Name of Zombie ???" << std::endl;
		return (1);
	}
	else
		zs = zombieHorde(atoi(av[1]), av[2]);
	std::cout << "Zombie horde created." << std::endl;
	for (int i = 0; i < atoi(av[1]); i++)
	{
		zs[i].announce();
	}
	delete[] zs;
	std::cout << "Zombie horde dead." << std::endl;
	return (0);
}
