/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 09:17:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/FragTrap.hpp"

FragTrap::FragTrap(std::string name, int hit, int energy, int damage): ClapTrap(name, hit, energy, damage)
{    
    std::cout << name << ": FragTrap Constructor Called" << std::endl; 
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
    std::cout << ": FragTrap Copy Constructor Called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other )
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << " FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << _name << ": FragTrap Destructor Called" << std::endl;
}

void FragTrap::hiFivesGuys(void)
{
	std::cout << _name << ": hi guys! Let's HIFIVES" << std::endl << std::endl;
}