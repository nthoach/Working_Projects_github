/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/25 21:20:19 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class   Character: public ICharacter
{
    private: 
        std::string _name;
        AMateria    *_inventory[4];

    public:
        Character(const std::string &name = "noname");
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif