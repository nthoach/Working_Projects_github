/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:34:25 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 14:35:15 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horder = new Zombie[N];
	for (int i = 0; i < N, i++)
		(horder + i)(name + static_cast<char>(i + 48));
	return (horder);
}
