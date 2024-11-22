/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:33:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class   WrongAnimal
{
    public:
        WrongAnimal(std::string type = "NONE");
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();

        //methods to access
        std::string getType() const;
        void makeSound() const;

    protected:
        std::string _type;

};

#endif