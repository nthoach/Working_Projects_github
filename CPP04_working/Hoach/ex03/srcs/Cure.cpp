/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 09:20:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog Constructor Call" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), _brain(new Brain(*(other._brain))) 
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        *(_brain) = *(other._brain); 
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << _type << " Barks Woof Woof" << std::endl;
    return ;
}

std::string	Dog::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void		Dog::setIdea(int i, std::string const & idea)
{
	this->_brain->setIdea(i, idea);
}