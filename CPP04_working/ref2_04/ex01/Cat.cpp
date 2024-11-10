/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:11:59 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 13:13:03 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "🐈 Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

/*Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << "🐈 Cat constructor called with type" << std::endl;
}*/

Cat::Cat(const Cat &copy)
{
	std::cout << "🐈 Cat copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "🐈 Cat destructor called" << std::endl;
	delete this->_brain;
	return ; 
}

//deep copy
Cat & Cat::operator =(Cat const &rhs)
{
	this->type = rhs.getType();
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, rhs._brain->getIdea(i));
	return *this;
}

void		Cat::makeSound(void) const
{
	std::cout << "🐈 MeooooOOooWWWWWWW" << std::endl;
}

std::string	Cat::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void		Cat::setIdea(int i, std::string const & idea)
{
	this->_brain->setIdea(i, idea);
}
