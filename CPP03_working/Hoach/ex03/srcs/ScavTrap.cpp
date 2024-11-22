/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 13:12:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 30, 20)
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
        std::cout << _name << ": ScavTrap attacks " << target << ", causing " << 
            _damage << " points of damage!" << std::endl;
        _energy--;
    }
}

void ScavTrap::guardGate(void)
{
	std::cout << _name << " enters 'GUARD_KEEPER' mode" << std::endl << std::endl;
}

int ScavTrap::getE() const
{ 
    return 50 ; 
}  // Getter for energy