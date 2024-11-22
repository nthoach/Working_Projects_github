/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:35:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor Call" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << _type << " Wrong Meows Meow Meow" << std::endl;
    return ;
}
