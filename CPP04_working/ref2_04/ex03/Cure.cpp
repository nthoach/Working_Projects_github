/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:15:35 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 13:52:29 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called through AMateria" << std::endl;
}

Cure::Cure(Cure const & copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &	Cure::operator=(Cure const & rhs)
{
	std::cout << "Cure assignation operator overloaded called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	std::cout << "Cure clone called. Allocating new Cure" << std::endl;
	AMateria *clone = new Cure(*this);
	return (clone);
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals ";
	std::cout << target.getName() << "'s wounds *" << std::endl;
}

