/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:16:08 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/28 16:05:19 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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