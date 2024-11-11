/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << name << " armed with " << weapon.getType() << " created." << std::endl;
}

HumanA::HumanA(Weapon &weapon): _weapon(weapon)
{
	_name = "NONAME";
	std::cout << " [NONAME] armed with " << weapon.getType() << " created." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << _name << " of HumanA Deleted." << std::endl;
}

void HumanA::attack(void)
{
 std::cout << _name << " attacks with his " << _weapon.getType() << std::endl; 
}

