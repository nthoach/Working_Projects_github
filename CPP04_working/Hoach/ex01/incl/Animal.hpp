/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/23 14:20:34 by honguyen         ###   ########.fr       */
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
        virtual std::string	getIdea(int i) const;
		virtual void  		setIdea(int i, std::string const & idea);

    protected:
        std::string _type;

};

#endif