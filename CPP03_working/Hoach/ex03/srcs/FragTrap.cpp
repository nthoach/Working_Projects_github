/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 13:13:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
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

void FragTrap::hiFiveGuys(void)
{
	std::cout << _name << " uses 'HI_FIVE' on GUYS" << std::endl << std::endl;
}

int FragTrap::getH() const
{ return (100); } // Getter for hit points

int FragTrap::getD() const
{ return (20);  } // Getter for damage