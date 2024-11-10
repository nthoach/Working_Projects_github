/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:18:58 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:02:36 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constuctor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
		this->_type = dog._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "hovhov!" << std::endl;
}