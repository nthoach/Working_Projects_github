/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/16 11:45:11 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"

    public:
        ClapTrap();
        ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int damage);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string _name;
        unsigned int         _hit;
        unsigned int         _energy;
        unsigned int        _damage;

ClapTrap::ClapTrap(): _name(""), _hit(0), _energy(0), _damage(0)
{
    std::cout << "Default Claptrap Constructor Called" << std::endl; 
}

ClapTrap::ClapTrap(std::string name = "", unsigned int hit = 0, unsigned int energy = 0,
    unsigned int damage = 0):_name(name), hit(0), energy(0), damage(0)
{
    std::cout << _name < ": Constructor Called" << std::endl; 
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
        _damage = other._energy;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << _name << "attacks " << target <<
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{
    
}