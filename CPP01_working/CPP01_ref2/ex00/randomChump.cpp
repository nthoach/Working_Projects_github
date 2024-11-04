/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:47:37 by imontero          #+#    #+#             */
/*   Updated: 2023/12/09 18:00:22 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 	instanciate a Zombie object with the name 
passed as parameter and calls announce method. */
void	randomChump(std::string name)
{
	Zombie	inst = Zombie(name);
	inst.announce();
}
