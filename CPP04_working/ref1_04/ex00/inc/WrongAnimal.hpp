/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:02:56 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/18 14:06:35 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal(void);
    WrongAnimal(const std::string &type);
    WrongAnimal(const WrongAnimal &wrongAnimal);
    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
    virtual ~WrongAnimal();
    
    std::string getType(void) const;
    void makeSound(void) const;
};

#endif