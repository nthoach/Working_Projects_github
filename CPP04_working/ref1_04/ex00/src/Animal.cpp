/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:07:07 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:02:30 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal constuctor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    if (this != &animal)
        this->_type = animal._type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void Animal::makeSound(void) const
{
    std::cout << "unknow sound!" << std::endl;
}
