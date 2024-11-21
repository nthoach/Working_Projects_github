/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:34:25 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/15 11:26:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

Zombie::Zombie( std::string name ): _name(name) {}

Zombie::Zombie( void ) {}

Zombie::~Zombie(  )
{
	std::cout << _name << ": is dead (RIP)." << std::endl;
}

void Zombie::announce( void ) const
{
	std::cout << _name << ": BBraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name )
{
	_name = name;
}