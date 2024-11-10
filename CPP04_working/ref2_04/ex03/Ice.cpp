/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:07:51 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 13:52:19 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called through AMateria" << std::endl;
}

Ice::Ice(Ice const & copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &	Ice::operator=(Ice const & rhs)
{
	std::cout << "Ice assignation operator overloaded called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	std::cout << "Ice clone called. Allocating new Ice" << std::endl;
	AMateria *clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}

