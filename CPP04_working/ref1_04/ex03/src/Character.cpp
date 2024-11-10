/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:41 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:59 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character() : _name("noname")
{
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(const Character &character) {*this = character;}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (_slots[i])
            delete _slots[i];
}

Character &Character::operator=(const Character &character)
{
    if (this != &character)
    {
        _name = character._name;
        for (int i = 0; i < 4; i++)
        {
            if (_slots[i])
                delete _slots[i];
            if (character._slots[i])
                _slots[i] = character._slots[i];
            else
                _slots[i] = NULL;
        }
    }
    return (*this);
}

const std::string &Character::getName(void) const { return _name; }

void Character::equip(AMateria *m)
{
    if (LOG)
        std::cout << CYAN << "[" << _name << "]: " << PINK;
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m;
            if (LOG)
                std::cout << "The material with the [" << m->getType() << "] type has been [equipped] into slot " << i 
                    << RESET <<std::endl;
            return;
        }
    }
    if (LOG)
        std::cout << RED <<
            "The " << m->getType() << " material cannot be [equipped] as the inventories are FULL!"  
                << RESET << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    std::cout << CYAN << "[" << _name << "]: " << RED;
    if (idx >= 0 && idx < 4)
    {
        if (LOG)
            std::cout << "The material with the [" << _slots[idx]->getType() << "] type has been [unequipped] into slot " << idx
                << RESET <<std::endl;
        _slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && _slots[idx])
    {
        if (LOG)
            std::cout << CYAN << "[" << _name << "]: " << RESET;
        _slots[idx]->use(target);
        return;
    }
    if (LOG)
    {
        std::cout << CYAN << "[" << _name << "]: " << RESET;
        std::cout << "slot is empty" << std::endl;
    }

}

void Character::printSlots()
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] != NULL)
            std::cout << "slot " << i << " -> " << _slots[i]->getType() << " | ";
    }
    std::cout << std::endl;
}