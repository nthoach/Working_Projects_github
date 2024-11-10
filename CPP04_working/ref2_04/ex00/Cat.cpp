/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:11:59 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:41:28 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "🐈 Cat constructor called" << std::endl;
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
	return ; 
}

Cat & Cat::operator =(Cat const &rhs)
{
	this->type = rhs.getType();
	return *this;
}

void		Cat::makeSound(void) const
{
	std::cout << "🐈 MeooooOOooWWWWWWW" << std::endl;
}
