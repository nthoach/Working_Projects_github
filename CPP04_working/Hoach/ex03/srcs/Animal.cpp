/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/23 14:28:46 by honguyen         ###   ########.fr       */
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

std::string	Animal::getIdea(int i) const
{
	(void) i;

    std::cout << "No idea for animal" << std::endl;

    return NULL;
}

void		Animal::setIdea(int i, std::string const & idea)
{
	(void) i;
    (void) idea;

    std::cout << "No idea for animal" << std::endl;
    return ;
}
