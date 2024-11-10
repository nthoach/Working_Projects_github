/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:06 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:34:09 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/MateriaSource.hpp"

static void testSubject()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

static void testOther()
{
    IMateriaSource *matSource = new MateriaSource();
    ICharacter *hero = new Character("Philips");
    ICharacter *enemy = new Character("Daniel");

    matSource->learnMateria(new Ice());
    matSource->learnMateria(new Cure());
    matSource->learnMateria(new Cure());
    matSource->learnMateria(new Cure());
    matSource->learnMateria(new Cure());

    hero->equip(matSource->createMateria("ice"));
    hero->printSlots();
    hero->equip(matSource->createMateria("cure"));
    hero->equip(matSource->createMateria("cure"));
    hero->printSlots();
    hero->equip(matSource->createMateria("ice"));
    hero->equip(matSource->createMateria("cure"));
    hero->printSlots();
    hero->unequip(1);
    hero->printSlots();

    hero->use(0, *enemy);
    hero->use(2, *enemy);

    delete matSource;
    delete hero;
    delete enemy;
}

int main()
{
    testSubject();
    testOther();
}