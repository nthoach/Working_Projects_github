/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:20:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"

Animal::Animal(std::string type):_type(type)
{
    std::cout << _type << " (type) of Animal Constructor Called" << std::endl;
    return ;
}

Animal::Animal(const Animal& other):_type(other._type)
{
    std::cout << _type << "(type) of Animal Copy Constructor Called" << std::endl;
    return ;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << _type << "(type) of Animal Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << _type << "(type) of Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << _type << " makes sound" << std::endl;
    return ;
}

//methods to access name and Damage points
std::string Animal::getType() const
{
    return (_type);
}
