/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/24 10:28:17 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class   Character: public ICharacter
{
    private: 
        std::string _name;
        AMateria    _inventory[4];

    public:
        Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        void makeSound() const;
        std::string	getIdea(int i) const;
		void  		setIdea(int i, std::string const & idea);

};

#endif