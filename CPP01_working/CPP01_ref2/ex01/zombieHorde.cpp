/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:06:25 by imontero          #+#    #+#             */
/*   Updated: 2023/12/09 18:54:40 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	Zombie* zombieHorde(int N, std::string name)
	{
		Zombie	*horde = new Zombie[N];

		for (int i = 0; i < N; i++)
		{
			//horde[i].setName(name + std::to_string(i)); c++98 or c++11?
			horde[i].setName(name + static_cast<char>(i + 48));
		}
		return (horde);
	}