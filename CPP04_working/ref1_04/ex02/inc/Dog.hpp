/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:02:17 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:00 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;

public:
    Dog(void);
    Dog(const Dog &dog);
    ~Dog();
    Dog &operator=(const Dog &dog);
    void makeSound(void) const;
    void printIdeas() const;
};

#endif