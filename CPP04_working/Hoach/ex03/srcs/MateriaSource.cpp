/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:25:37 by nthoach           #+#    #+#             */
/*   Updated: 2024/11/26 09:19:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &other) {
    for (int i = 0; i < 4; i++) {
        if (other._templates[i]) {
            _templates[i] = other._templates[i]->clone();
        } else {
            _templates[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_templates[i]) {
                delete _templates[i];
            }
            if (other._templates[i]) {
                _templates[i] = other._templates[i]->clone();
            } else {
                _templates[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_templates[i]) {
            delete _templates[i];
            _templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++)
    {
        if (!_templates[i]) {
            _templates[i] = m->clone();
            break;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    return NULL;
}
