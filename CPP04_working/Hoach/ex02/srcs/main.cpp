/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/23 15:01:29 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Animal.hpp"
#include "../incl/Brain.hpp"

int	main(void)
{
std::cout << std::endl << "=======================   ex01 tests  ============================" << std::endl;;
	
	{
		Animal* Zoo[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				Zoo[i] = new Dog();
			else
				Zoo[i] = new Cat();
			// else
			// 	Zoo[i] = new Animal();
		}

		for (int i = 0; i < 10; i++)
		{
			std::cout  << "--" << Zoo[i]->getType()<< ":";
			std::cout << Zoo[i]->getIdea(i);
			std::string idea("->NONE");
			Zoo[i]->setIdea(i, idea);
			std::cout << Zoo[i]->getIdea(i) << std::endl;
		}
		
		for (int i = 0; i < 10; i++)
		{
			Zoo[i]->makeSound();
			delete Zoo[i];
		}
		return 0;

	}

std::cout << std::endl << "=======================   ex01 tests  ============================" << std::endl;;

	return 0;
}