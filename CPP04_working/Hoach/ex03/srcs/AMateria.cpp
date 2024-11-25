/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:53:42 by nthoach           #+#    #+#             */
/*   Updated: 2024/11/25 21:00:59 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../incl/AMateria.hpp"
#include "../incl/ICharacter.hpp"

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::AMateria(AMateria const &other): _type(other._type) {}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {};

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}