/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:22:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class   Animal
{
    public:
        Animal(std::string type = "NONE");
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        //methods to access
        std::string getType() const;
        virtual void makeSound() const;

    protected:
        std::string _type;

};

#endif