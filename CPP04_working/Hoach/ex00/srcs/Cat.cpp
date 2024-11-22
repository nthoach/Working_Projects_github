/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 09:20:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat Constructor Call" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << _type << " Meows Meow Meow" << std::endl;
    return ;
}
