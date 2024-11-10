/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:18:58 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:17 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constuctor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), _brain(new Brain(*(dog._brain)))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->_type = dog._type;
		*(this->_brain) = *(dog._brain);
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "hovhov!" << std::endl;
}

void Dog::printIdeas() const
{
    this->_brain->printIdeas();
}