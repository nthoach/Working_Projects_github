/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:17 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:40 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &ice);
	virtual ~Ice();

	Ice &operator=(const Ice &ice);

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif