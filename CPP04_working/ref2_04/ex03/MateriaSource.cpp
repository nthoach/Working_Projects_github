/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:29:12 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 19:34:33 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called. Filling materias array with NULL" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called and freeing materias" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
			this->_materias[i] = NULL;
	}
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "MateriaSource assignation operator overloaded called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (rhs._materias[i])
			this->_materias[i] = rhs._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "learnMateria called in MateriaSource. materia is NULL" << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			std::cout << "MateriaSource learnMateria called. ";
			std::cout << "Learnt: " << this->_materias[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Can't learn more materias" << std::endl;
	delete materia;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			std::cout << "MateriaSource createMateria called. ";
			std::cout << "Created: " << this->_materias[i]->getType() << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	std::cout << "MateriaSource createMateria called. ";
	std::cout << "Materia not found" << std::endl;
	return (NULL);
}
