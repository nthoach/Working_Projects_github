/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:14:05 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 19:43:47 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
	std::cout << "AMateria default constructor called with type: ";
	std::cout << this->_type << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called with type: ";
	std::cout << this->_type << std::endl;
}

AMateria::AMateria(AMateria const & copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &	AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	//std::cout << "AMateria getType called" << std::endl;
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots 🤷 at ";
	std::cout << target.getName() << " *" << std::endl;
}
