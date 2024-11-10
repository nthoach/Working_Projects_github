/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:13:56 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:32:38 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat constuctor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), _brain(new Brain(*(cat._brain)))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        this->_type = cat._type;
        *(this->_brain) = *(cat._brain);
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "miavvv!" << std::endl;
}

void Cat::printIdeas() const
{
    this->_brain->printIdeas();
}