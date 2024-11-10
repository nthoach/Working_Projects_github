/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:01:07 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:15:55 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Undefined type")
{
	std::cout << "🧬 Animal default constructor called" << std::endl;
	return;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "🧬 Animal constructor called with type: " << this->type << std::endl;
	return;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "🧬 Animal copy constructor called" << std::endl;
	*this = copy;
	return;
}

Animal::~Animal(void)
{
	std::cout << "🧬 Animal destructor called" << std::endl;
	return;
}

Animal & Animal::operator =(Animal const &rhs)
{
	this->type = rhs.getType();
	return *this;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void  		Animal::setType(std::string type)
{
	this->type = type;
}

void		Animal::makeSound(void) const
{
	std::cout << "🧬📣 Undefined sound " << std::endl;
}
