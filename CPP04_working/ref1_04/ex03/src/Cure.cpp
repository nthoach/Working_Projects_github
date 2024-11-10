/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:49 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:34:01 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &cure) : AMateria(cure) {*this = cure;}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &cure)
{
    (void)cure;
    return (*this);
}

Cure *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}