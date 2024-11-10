/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:01:27 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:32:56 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat(void);
    Cat(const Cat &cat);
    ~Cat();
    Cat &operator=(const Cat &cat);

    void makeSound(void) const;
    void printIdeas() const;
};

#endif