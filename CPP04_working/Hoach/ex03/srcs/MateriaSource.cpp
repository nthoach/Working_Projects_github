/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:25:37 by nthoach           #+#    #+#             */
/*   Updated: 2024/11/25 21:26:55 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../incl/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _templates[i] = nullptr;
    }
}

MateriaSource::MateriaSource(MateriaSource const &other) {
    for (int i = 0; i < 4; i++) {
        if (other._templates[i]) {
            _templates[i] = other._templates[i]->clone();
        } else {
            _templates[i] = nullptr;
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
                _templates[i] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_templates[i]) {
            delete _templates[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!_templates[i]) {
            _templates[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    return nullptr;
}
