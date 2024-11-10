/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:18:36 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 14:11:12 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "🐕 Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

/*Dog::Dog(std::string type)
{
	this->type = type;
	std::cout << "🐕 Dog constructor called with type" << std::endl;
}*/

Dog::Dog(const Dog &copy)
{
	std::cout << "🐕 Dog copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "🐕 Dog destructor called" << std::endl;
	delete this->_brain;
	return ; 
}

Dog & Dog::operator =(Dog const &rhs)
{
	this->type = rhs.getType();
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, rhs._brain->getIdea(i));
	return *this;
}

void		Dog::makeSound(void) const
{
	std::cout << "🐕 WOOOFFF WOOF" << std::endl;
}

std::string	Dog::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void		Dog::setIdea(int i, std::string const & idea)
{
	this->_brain->setIdea(i, idea);
}

