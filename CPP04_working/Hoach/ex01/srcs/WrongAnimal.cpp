/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:20:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type):_type(type)
{
    std::cout << _type << " (type) of WrongAnimal Constructor Called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other):_type(other._type)
{
    std::cout << _type << "(type) of WrongAnimal Copy Constructor Called" << std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << _type << "(type) of WrongAnimal Copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << _type << "(type) of WrongAnimal Destructor Called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << _type << " makes wronganimal's sound" << std::endl;
    return ;
}

//methods to access name and Damage points
std::string WrongAnimal::getType() const
{
    return (_type);
}
