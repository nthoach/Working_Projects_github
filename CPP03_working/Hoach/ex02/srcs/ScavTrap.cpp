/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/21 17:11:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name, int hit, int energy, int damage): ClapTrap(name, hit, energy, damage)
{    
    std::cout << name << ": ScavTrap Constructor Called" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
    std::cout << ": ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other )
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << " ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << _name << ": ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (actable())
    {
        std::cout << _name << " attacks " << target << ", causing " << 
            _damage << " points of damage!" << std::endl;
        _energy--;
    }
}

void ScavTrap::guardGate(void)
{
	std::cout << _name << " enters 'GUARD_KEEPER' mode" << std::endl << std::endl;
}