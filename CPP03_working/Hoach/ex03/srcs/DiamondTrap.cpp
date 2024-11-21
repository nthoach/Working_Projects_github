/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/21 18:12:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
    _hit = FragTrap::_hit; // From FragTrap
    _energy = ScavTrap::_energy;       // From ScavTrap
    _damage = FragTrap::_damage;       // From FragTrap
    std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.ClapTrap::_name), // Copy ClapTrap::_name
      FragTrap(other),                // Call FragTrap copy constructor
      ScavTrap(other),                // Call ScavTrap copy constructor
      _name(other._name)              // Copy DiamondTrap::_name
{
    _hit = other._hit;
    _energy = other._energy;
    _damage = other._damage;

    std::cout << "DiamondTrap " << _name << " copied!" << std::endl;
}

// Copy Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) { // Avoid self-assignment
        ClapTrap::_name = other.ClapTrap::_name; // Copy ClapTrap::_name
        _name = other._name;                     // Copy DiamondTrap::_name
        _hit = other._hit;
        _energy = other._energy;
        _damage = other._damage;

        // Call base class assignment operators explicitly if needed
        FragTrap::operator=(other);
        ScavTrap::operator=(other);

        std::cout << "DiamondTrap " << _name << " assigned!" << std::endl;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed!" << std::endl;
}

// Override attack (use ScavTrap's implementation)
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

// Special function whoAmI
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
