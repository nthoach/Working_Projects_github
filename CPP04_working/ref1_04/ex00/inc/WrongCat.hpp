/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:03:20 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/18 14:37:05 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:
public:
    WrongCat(void);
    WrongCat(const WrongCat &wrongCat);
    WrongCat &operator=(const WrongCat &wrongCat);
    ~WrongCat();

    void makeSound(void) const;
};

#endif