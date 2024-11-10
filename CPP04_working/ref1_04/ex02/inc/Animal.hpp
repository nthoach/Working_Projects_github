/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:18:50 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/20 14:23:27 by seozkan          ###   ########.fr       */
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
    virtual ~Animal();

    Animal &operator=(const Animal &animal);

    std::string getType(void) const;
    virtual void makeSound(void) const = 0;
};

#endif