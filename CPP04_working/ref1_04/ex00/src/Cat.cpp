/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:13:56 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:02:32 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constuctor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat")
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
        this->_type = cat._type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "miavvv!" << std::endl;
}