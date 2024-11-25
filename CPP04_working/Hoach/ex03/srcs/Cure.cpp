/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:03:20 by nthoach           #+#    #+#             */
/*   Updated: 2024/11/25 21:14:34 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Cure.hpp"

Cure::Cure(): AMateria("Cure") {}

Cure::Cure(Cure const &other): AMateria(other) {}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		AMateria::operator=(other);

	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"
	<< std::endl;
}