/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:04:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class   WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();

       void makeSound() const;
};

#endif