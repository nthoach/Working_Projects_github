/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:01 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:34:13 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource) {*this = materiasource;}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i])
            delete _slots[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    if (this != &materiaSource)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_slots[i])
                delete _slots[i];
            if (materiaSource._slots[i])
                _slots[i] = materiaSource._slots[i]->clone();
            else
                _slots[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m;
            if (LOG)
                std::cout << YELLOW
                      << "The materia with the [" << m->getType() << "] type has been learned."
                      << RESET << std::endl;
            return;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] != NULL && _slots[i]->getType() == type)
        {
            if (LOG)
                std::cout << GREEN
                    << "The materia with the [" << type << "] type has been created."
                    << RESET << std::endl;
            return (_slots[i]->clone());
        }
    }
    return (NULL);
}