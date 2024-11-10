/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:29:51 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:41:43 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "🦄 WrongCat constructor called" << std::endl;
}

/*WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout << "🦄 WrongCat constructor called with type" << std::endl;
}*/

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "🦄 WrongCat copy constructor called" << std::endl;
	*this = copy;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "🦄 WrongCat destructor called" << std::endl;
	return ; 
}

WrongCat & WrongCat::operator =(WrongCat const &rhs)
{
	this->type = rhs.getType();
	return *this;
}

void		WrongCat::makeSound(void) const
{
	std::cout << "🦄📣 GronFF  GRONFffFFF" << std::endl;
}

