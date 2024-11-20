/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 20:02:40 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _damage(0)
{
    std::cout << _name << ": Constructor Called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other):_name(other._name),_hit(other._hit), _energy(other._energy), 
    _damage(other._damage)
{
    std::cout << _name << ": Copy Constructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    std::cout << _name << ": Destructor Called" << std::endl;
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

std::string ClapTrap::getName(void)
{
    return (_name);
}
void    CLapTrap::setDamage(const int damage)
{
    std::cout << _name << ": set damage = ", damage << std::endl;
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

bool ClapTrap::showStatus(void)
{
    std::cout << _name << "'s statistics:" << std::endl;
    std::cout << _hit << " (hit points)" << std::endl;
    std::cout << _energy << " (energy points)" << std::endl;
    std::cout << _damage << "(attack damage)" << std::endl;
    return 1;
}