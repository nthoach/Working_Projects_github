/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:01:25 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 19:43:32 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Undefined")
{
	std::cout << "Character default constructor called with name: ";
	std::cout << this->_name;
	std::cout << " Initializing Character inventory with NULL" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character constructor called with name: ";
	std::cout << this->_name;
	std::cout << " Initializing Character inventory with NULL" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(Character const & copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			std::cout << "Deleting materia in Character inventory" << std::endl;
			delete this->_materias[i];
		}
	}
}

Character &	Character::operator=(Character const & rhs)
{
	std::cout << "Character assignation operator called" << std::endl;
	this->_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			std::cout << "Deleting materia in Character inventory" << std::endl;
			delete this->_materias[i];
		}
		this->_materias[i] = rhs._materias[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName(void) const
{
	//std::cout << "Character getName called" << std::endl;
	return (this->_name);
}

void				Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << "Character Can't equip NULL materia" << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			std::cout << "Character Equipping materia in Character inventory" << std::endl;
			this->_materias[i] = m;
			return ;
		}
	}
	std::cout << "Character equip inventory is full" << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character unequip Invalid index" << std::endl;
		return ;
	}
	if (!this->_materias[idx])
	{
		std::cout << "Character No materia in this slot" << std::endl;
		return ;
	}
	std::cout << "Character Unequipping materia in Character inventory" << std::endl;
	this->_materias[idx] = NULL;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Character Invalid index" << std::endl;
		return ;
	}
	if (!this->_materias[idx])
	{
		std::cout << "Character No materia in this slot" << std::endl;
		return ;
	}
	std::cout << "Character Using materia in Character inventory" << std::endl;
	this->_materias[idx]->use(target);
}
