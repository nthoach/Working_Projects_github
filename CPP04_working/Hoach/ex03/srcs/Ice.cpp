/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:03:20 by nthoach           #+#    #+#             */
/*   Updated: 2024/11/25 21:43:22 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const &other): AMateria(other) {}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);

	return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
	<< std::endl;
}