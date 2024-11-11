/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 16:56:40 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << name << " unarmed has been created." << std::endl;
	_weapon = NULL;
}

HumanB::~HumanB(void)
{
	std::cout << _name << " of HumanB Deleted." << std::endl;
}

void HumanB::attack(void)
{
 if (_weapon == NULL)
 	std::cout << _name << " has no weapon to attack." << std::endl;
 else
 	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
	std::cout << _name << " has armed with " << _weapon->getType() << std::endl;
}


