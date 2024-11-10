/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:01:27 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:02:11 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "../inc/Animal.hpp"

class Cat : public Animal
{
public:
    Cat(void);
    Cat(const Cat &cat);
    ~Cat();
    Cat &operator=(const Cat &cat);
    
    void makeSound(void) const;
};

#endif