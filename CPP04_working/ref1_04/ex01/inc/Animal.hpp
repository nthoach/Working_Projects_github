/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:18:50 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:03:22 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual ~Animal();

    std::string getType(void) const;
    virtual void makeSound(void) const;
};

#endif