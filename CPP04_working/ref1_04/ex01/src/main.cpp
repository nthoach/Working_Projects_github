/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:36:17 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:08:41 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"


static void testArray()
{
    std::cout << "\x1B[33m"
              << "---------------------- ARRAY TEST ----------------------"
              << "\033[0m" << std::endl;
    const int arraySize = 4;
    Animal *animalArray[arraySize];

    for (int i = 0; i < arraySize / 2; i++)
    {
        animalArray[i] = new Dog();
        std::cout << std::endl;
        animalArray[i + arraySize / 2] = new Cat();
        std::cout << std::endl;
    }

    for (int i = 0; i < arraySize; i++)
    {
        delete animalArray[i];
        std::cout << std::endl;
    }
}

static void testCopy()
{
    std::cout << "\x1B[33m"
              << "---------------------- COPY TEST ----------------------"
              << "\033[0m" << std::endl;
    Cat cat1;
    Cat cat2;

    cat1.printIdeas();
    cat2.printIdeas();
    cat2 = cat1;
    cat1.printIdeas();
    cat2.printIdeas();
}

int main()
{
    testArray();
    testCopy();
    return 0;
}