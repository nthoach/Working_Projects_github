/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 13:14:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    _hit = FragTrap::getH();      // Accessing the value from FragTrap
    _energy = ScavTrap::getE(); // Accessing the value from ScavTrap
    _damage = FragTrap::getD(); // Accessing the value from FragTrap

    std::cout << _name << ": DiamondTrap constructed" << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << _name << ": DiamondTrap copied" << std::endl;
}

// Copy Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        // FragTrap::operator=(other);
        // ScavTrap::operator=(other);
        _name = other._name;
        // Call base class assignment operators explicitly if needed
        std::cout << _name << ": DiamondTrap assigned" << std::endl;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout <<_name << "DiamondTrap destructed!" << std::endl;
}

// Override attack (use ScavTrap's implementation)
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

// Special function whoAmI
void DiamondTrap::whoAmI() {
    std::cout << _name << ": DiamondTrap " << std::endl;
    std::cout << ClapTrap::_name<< ": ClapTrap name"  << std::endl;
}

void DiamondTrap::showStatus(void)
{
    std::cout << _name << "'s statistics:" << std::endl;
    std::cout << _hit << " (hit points)" << std::endl;
    std::cout << _energy << " (energy points)" << std::endl;
    std::cout << _damage << "(attack damage)" << std::endl;
}