/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:34:25 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 14:38:37 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

Zombie::Zombie( std::string name ): _name(name)
{
	std::cout << _name << ": born." << std::endl;
}

Zombie::Zombie( void )
{
	std::cout << "[noname]: born." << std::endl;
}

Zombie::~Zombie(  )
{
	std::cout << _name << ": is dead (RIP)." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BBraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name )
{
	_name = name;
}