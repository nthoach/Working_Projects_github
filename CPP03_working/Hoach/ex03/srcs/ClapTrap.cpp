/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 12:03:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, int hit, int energy, int damage):
        _name(name), _hit(hit), _energy(energy), _damage(damage)
{
    std::cout << _name << ": ClapTrap Constructor Called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other):_name(other._name),_hit(other._hit), _energy(other._energy), 
    _damage(other._damage)
{
    std::cout << _name << ": ClapTrap Copy Constructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << _name << ": ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hit = other._hit;
        _energy = other._energy;
        _damage = other._damage;
    }
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << _name << ": ClapTrap Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (actable())
    {
        std::cout << _name << " attacks " << target << ", causing " << 
            _damage << " points of damage!" << std::endl;
        _energy--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout << _name << ": take the damage from attack" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (actable())
    {
        std::cout << _name << ": is repaired" << std::endl;
        _hit += amount;
        _energy--;
    }
}

//methods to access name and Damage points
std::string ClapTrap::getName() const
{
    return (_name);
}

int ClapTrap::getDamage() const
{
    return (_damage);
}

void ClapTrap::setDamage(int damage)
{
    std::cout << _name << ": set damage = " << damage << std::endl;
    _damage = damage;
}


bool ClapTrap::actable(void)
{
    if (_hit <= 0)
        return std::cout << _name << ": has no hit point to act" << std::endl, 0;
    else if (_energy <= 0)
        return std::cout << _name << ": has no energy to act" << std::endl, 0;
    else
        return 1;
}

void ClapTrap::showStatus(void)
{
    std::cout << _name << "'s statistics:" << std::endl;
    std::cout << _hit << " (hit points)" << std::endl;
    std::cout << _energy << " (energy points)" << std::endl;
    std::cout << _damage << "(attack damage)" << std::endl;
}