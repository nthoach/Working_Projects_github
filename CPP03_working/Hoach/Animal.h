/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:45:17 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 16:30:27 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   Animal
{
    public:
        void eat()
        {
            std::cout << "Eating foods" << std::endl;
        }
};

class   Dog: public Animal
{
    public:
        void bark()
        {
            std::cout << "The dog barks" << std::endl;
        }
};

