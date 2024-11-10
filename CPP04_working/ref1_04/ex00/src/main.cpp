/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:36:17 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:02:41 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

static void wrongTest(void)
{
    const WrongAnimal *wrongcat = new WrongCat();

    std::cout << wrongcat->getType() << " ";
    wrongcat->makeSound();
    delete wrongcat;
}

static void trueTest(void)
{
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << animal->getType() << " ";
    cat->makeSound();
    std::cout << dog->getType() << " ";
    dog->makeSound();
    std::cout << cat->getType() << " ";
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;
}

int main(void)
{
    std::cout << "\x1B[33m"
              << "---------------------- [True Test Result] ----------------------"
              << "\033[0m" << std::endl;
    trueTest();
    std::cout << "\x1B[33m"
              << "---------------------- [Wrong Test Result] ----------------------"
              << "\033[0m" << std::endl;
    wrongTest();
    return (0);
}