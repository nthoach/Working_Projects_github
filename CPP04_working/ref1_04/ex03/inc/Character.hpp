/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:45:53 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:31 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "../inc/ICharacter.hpp"

#define LOG 1
#define PINK "\033[38;5;206m"
#define RED "\033[35m"
#define CYAN   "\033[36m"
#define RESET   "\033[0m"


class Character : public ICharacter
{
protected:
    AMateria *_slots[4];
    std::string _name;

public:
    Character(void);
    Character(const std::string &name);
    Character(const Character &character);
    virtual ~Character();

    Character &operator=(const Character &character);

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    void printSlots();
};

#endif