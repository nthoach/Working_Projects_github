/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:01:07 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 14:24:58 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void): type("Undefined type")
{
	std::cout << "🧬 AAnimal default constructor called" << std::endl;
	return;
}

AAnimal::AAnimal(std::string type): type(type)
{
	std::cout << "🧬 AAnimal constructor called with type: " << this->type << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "🧬 AAnimal copy constructor called" << std::endl;
	*this = copy;
	return;
}

AAnimal::~AAnimal(void)
{
	std::cout << "🧬 AAnimal destructor called" << std::endl;
	return;
}

AAnimal & AAnimal::operator =(AAnimal const &rhs)
{
	this->type = rhs.getType();
	return *this;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

void  		AAnimal::setType(std::string type)
{
	this->type = type;
}

void		AAnimal::makeSound(void) const
{
	std::cout << "🧬📣 Undefined sound " << std::endl;
}

std::string	AAnimal::getIdea(int i) const
{
	(void)i;
	return "🧬📝 Undefined idea";
}
