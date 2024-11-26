/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/26 08:38:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Animal.hpp"
#include "../incl/WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "======================= Start: ex00 tests  ============================" << std::endl;;
	{
		const Animal* a = new Animal();
		const Animal* d = new Dog();
		const Animal* c = new Cat();
		std::cout << std::endl << std::endl;

		const WrongAnimal* wa = new WrongAnimal();
		const WrongAnimal* wc = new WrongCat();
		std::cout << std::endl << std::endl;

		std::cout << a->getType() << " " << std::endl;
		std::cout << d->getType() << " " << std::endl;
		std::cout << c->getType() << " " << std::endl;
		std::cout << std::endl << std::endl;

		a->makeSound(); //will output the cat sound!
		d->makeSound();
		c->makeSound();
		wa->makeSound();
		wc->makeSound();
		std::cout << std::endl << std::endl;
		
		delete a;
		delete d;
		delete c;
		delete wa;
		delete wc;
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
std::cout << std::endl << "======================= End: ex00 tests  ============================" << std::endl;;
	return 0;
}