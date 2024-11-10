/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:48:41 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 14:38:03 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal* Zoo[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			Zoo[i] = new Dog();
		else
			Zoo[i] = new Cat();
	}
	
	std::cout << std::endl << "-------------" << Zoo[4]->getType() << std::endl <<std::endl;
	std::cout << Zoo[4]->getIdea(3) << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		Zoo[i]->makeSound();
		delete Zoo[i];
	}

	system("leaks animal01");
	return 0;
}

