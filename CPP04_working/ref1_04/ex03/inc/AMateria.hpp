/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:45:47 by seozkan           #+#    #+#             */
/*   Updated: 2024/11/25 20:44:54 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "../inc/ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(const std::string &type);
	AMateria(const AMateria &amataria);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &aMateria);
	
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif