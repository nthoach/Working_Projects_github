/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:45:59 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:35 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure &cure);
    virtual ~Cure();

    Cure &operator=(const Cure &cure);

    Cure *clone() const;
    void use(ICharacter &target);
};

#endif