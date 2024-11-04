/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:06:08 by imontero          #+#    #+#             */
/*   Updated: 2023/12/09 19:00:56 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 4;
	
	Zombie	*horde = zombieHorde(N, "Pepe");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}