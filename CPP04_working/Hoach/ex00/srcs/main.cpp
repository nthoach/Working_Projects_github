/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/23 11:21:20 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Animal.hpp"
#include "../incl/WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "=======================   ex00 tests  ============================" << std::endl;;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl << std::endl;

		const WrongAnimal* neta = new WrongAnimal();
		const WrongAnimal* k = new WrongCat();
		std::cout << std::endl << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << k->getType() << " " << std::endl;
		std::cout << std::endl << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		k->makeSound();
		meta->makeSound();
		neta->makeSound();
		std::cout << std::endl << std::endl;
		
		delete meta;
		delete neta;
		delete j;
		delete i;
		delete k;
	}
	std::cout << std::endl << std::endl;
	{
		Animal	A1, A2;
		Dog 	D1, D2;
		Cat		C1, C2;
		std::cout << std::endl << std::endl;

		std::cout << A1.getType() << std::endl;
		std::cout << A2.getType() << std::endl;
		A2.makeSound();

		std::cout << D1.getType() << std::endl;
		std::cout << D2.getType() << std::endl;
		D1.makeSound();

		std::cout << C1.getType() << std::endl;
		std::cout << C1.getType() << std::endl;
		C2.makeSound();

		std::cout << std::endl << std::endl;
		WrongAnimal A;
		std::cout << std::endl << std::endl;
		A.makeSound();
		std::cout << std::endl << std::endl;
		WrongCat B;
		std::cout << std::endl << std::endl;
		B.makeSound();
		std::cout << std::endl << std::endl;
	}
std::cout << std::endl << "=======================   ex00 tests  ============================" << std::endl;;
	return 0;
}