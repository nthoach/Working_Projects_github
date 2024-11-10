/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:18:36 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:41:32 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "🐕 Dog constructor called" << std::endl;
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
	return ; 
}

Dog & Dog::operator =(Dog const &rhs)
{
	this->type = rhs.getType();
	return *this;
}

void		Dog::makeSound(void) const
{
	std::cout << "🐕 WOOOFFF WOOF" << std::endl;
}

