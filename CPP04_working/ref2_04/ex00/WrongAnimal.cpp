/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:21:10 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:49:35 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("Undefined wrong type")
{
	std::cout << "🦠 WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "🦠 WrongAnimal constructor called with type: " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "🦠 WrongAnimal copy constructor called" << std::endl;
	*this = copy;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "🦠 WrongAnimal destructor called" << std::endl;
	return ; 
}

WrongAnimal & WrongAnimal::operator =(WrongAnimal const &rhs)
{
	this->type = rhs.getType();
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void  		WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "🦠📣 Undefined wrong sound " << std::endl;
}
