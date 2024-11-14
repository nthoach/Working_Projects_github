/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/14 16:34:54 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) 
{
	std::cout << type << " Weapon created." << std::endl;
}

Weapon::Weapon(void) 
{
	_type = "NULL";
	std::cout << " [Unset Type] Weapon created." << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << _type << " Weapon deleted." << std::endl;
}

const std::string& Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
	std::cout << "set type " << type << " to the weapon" << std::endl;
}






